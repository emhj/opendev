#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

namespace asio = boost::asio;
namespace ip = asio::ip;

/** Create and return a string representing the current time */
std::string make_daytime_string()
{
    std::time_t now = std::time(0);
    return std::ctime(&now);
}

int main()
{
    try
    {
        asio::io_service ioService;

        // acceptor object for listening for new connections
        ip::tcp::acceptor acceptor(
            ioService,
            ip::tcp::endpoint(ip::tcp::v4(), 13)
        );

        // create an iterative server that handles one connection at a time
        // create a socket for representing the client connection
        // wait for a connection
        for (;;)
        {
            // create socket
            ip::tcp::socket socket(ioService);
            // wait for connection
            acceptor.accept(socket);

            // at this point a client is accessing the server
            std::cout << "Handling client connection" << std::endl;

            // create the daytime string
            std::string msg = make_daytime_string();

            // write the string to the client
            boost::system::error_code ignored_error;
            asio::write(socket, asio::buffer(msg), ignored_error);
        }
    }
    catch (std::exception e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
