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

        // ability to resolve a query to a list of UDP endpoints
        // Endpoints may contain IPv4 and IPv6
        ip::udp::resolver resolver(ioService);

        // Construct a query using IPv4, with the name of the server and name
        // of the service
        ip::udp::resolver::query query(ip::udp::v4(), argv[1], "daytime");

        // ip::udp::resolver::resolve() is guaranteed to return at least one
        // endpoint in the list if it does not fail
        ip::udp::endpoint receiverEndpoint = *resolver.resolve(query);

        // create socket
        ip::udp::socket socket(ioService);

        // Initiate contact with remote endpoint
        socket.open(ip::udp::v4());
        boost::array<char, 1> sendBuf = {{ 0 }};
        socket.send_to(asio::buffer(sendBuf), receiverEndpoint);

        // Wait to accept whatever the server sends
        boost::array<char, 128> recvBuf;
        ip::udp::endpoint senderEndpoint;
        size_t len = socket.receive_from(
            asio::buffer(recvBuf),
            senderEndpoint
        );

        // write received data
        std::cout.write(recvBuf.data(), len);
    }
    catch (std::exception e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
