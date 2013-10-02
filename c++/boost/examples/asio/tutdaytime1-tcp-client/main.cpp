#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

namespace asio = boost::asio;
namespace ip = asio::ip;

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: client <host>" << std::endl;
            return 1;
        }

        asio::io_service ioService;

        // ability to resolve a query to a list of TCP endpoints
        // Endpoints may contain IPv4 and IPv6
        ip::tcp::resolver resolver(ioService);

        // Construct a query with the name of the server
        // And name of the service
        ip::tcp::resolver::query query(argv[1], "daytime");

        // iterate through the list of endpoints
        ip::tcp::resolver::iterator it = resolver.resolve(query);

        // create and connect socket
        // asio connect handles iterating through the endpoints
        ip::tcp::socket socket(ioService);
        asio::connect(socket, it);

        // at this point the connection is open
        // read response from daytime service
        for (;;)
        {
            boost::array<char, 128> buf;
            boost::system::error_code error;

            // asio::buffer() determines size of array to prevent overrun
            // possible to use other types (char[], std::vector)
            // socket.read_some() blocks until one or more bytes of data
            // has been read or until an error occurs
            size_t len = socket.read_some(asio::buffer(buf), error);

            // connection closed cleanly by peer
            if (error == asio::error::eof)
            {
                break;
            }
            // check for some other error
            else if (error)
            {
                throw boost::system::system_error(error);
            }

            // write received data
            std::cout.write(buf.data(), len);
        }
    }
    catch (std::exception e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
