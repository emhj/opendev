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

        // Create udp socket to receive requests on UDP port 13
        ip::udp::socket socket(
            ioService,
            ip::udp::endpoint(ip::udp::v4(), 13)
        );

        // Wait for client to contact us
        for (;;)
        {
            boost::array<char, 1> recvBuf;
            ip::udp::endpoint remoteEndpoint;
            boost::system::error_code error;

            socket.receive_from(
                asio::buffer(recvBuf),
                remoteEndpoint,          // populated by receive_from
                0,
                error
            );

            if (error && error != asio::error::message_size)
            {
                throw boost::system::system_error(error);
            }

            // at this point a client is accessing the server
            std::cout << "Handling client connection" << std::endl;

            // create the daytime string
            std::string msg = make_daytime_string();

            // write the string to the client using remoteEndpoint
            boost::system::error_code ignored_error;
            socket.send_to(
                asio::buffer(msg),
                remoteEndpoint,
                0,
                ignored_error
            );
        }
    }
    catch (std::exception e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
