#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

namespace asio = boost::asio;
namespace ip = asio::ip;

/** Create and return a string representing the current time */
std::string make_daytime_string()
{
    std::time_t now = std::time(0);
    return std::ctime(&now);
}

class TcpConnection : public boost::enable_shared_from_this<TcpConnection>
{
public:
    // used shared pointer to keep connection alive if any reference exists
    typedef boost::shared_ptr<TcpConnection> Pointer;

    // factory method
    static Pointer create(asio::io_service &ioService)
    {
        return Pointer(new TcpConnection(ioService));
    }

    ip::tcp::socket &socket()
    {
        return socket_;
    }

    void start()
    {
        message_ = make_daytime_string();

        // serve data to client with async_write to send entire block of data
        // NB: async_write_some() does not send an entire block of data
        asio::async_write(
            socket_,
            asio::buffer(message_),
            boost::bind(
                &TcpConnection::handle_write_,
                shared_from_this(),
                asio::placeholders::error,
                asio::placeholders::bytes_transferred
            )
        );
    }

private:
    TcpConnection(asio::io_service &ioService) :
        socket_(ioService) 
    {
    }

    void handle_write_(
        const boost::system::error_code &,
        size_t
    )
    {
    }

    ip::tcp::socket socket_;
    std::string message_;
};

class TcpServer
{
public:
    TcpServer(asio::io_service &ioService) :
        acceptor_(ioService,
                  ip::tcp::endpoint(ip::tcp::v4(), 13))
    {
        start_accept_();
    }

private:
    ip::tcp::acceptor acceptor_;

    void start_accept_()
    {
        // create a new TcpConnection
        TcpConnection::Pointer newConnection =
            TcpConnection::create(acceptor_.get_io_service());

        // initiate async accept, using handle_accept_() to handle
        // the acception
        acceptor_.async_accept(
            newConnection->socket(),
            boost::bind(&TcpServer::handle_accept_,
                        this,
                        newConnection,
                        asio::placeholders::error)
        );
    }

    void handle_accept_(
        TcpConnection::Pointer newConnection,
        const boost::system::error_code &error
    )
    {
        // called when accept initiated by start_accept_() finishes
        if (!error)
        {
            std::cout << "Handled connection" << std::endl;
            // service client request
            newConnection->start();
        }

        // start next async acception
        start_accept_();
    }
};

int main()
{
    try
    {
        asio::io_service ioService;
        TcpServer server(ioService);
        ioService.run();
    }
    catch (std::exception e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
