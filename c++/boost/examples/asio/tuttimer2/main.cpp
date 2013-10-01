#include <iostream>
#include <boost/asio.hpp>

#include <boost/date_time/posix_time/posix_time.hpp>

namespace io = boost::asio;

void print(const boost::system::error_code &)
{
    std::cout << "Hello, world!" << std::endl;
}

int main(void)
{
    io::io_service ioService;

    io::deadline_timer t(ioService, boost::posix_time::seconds(5));
    t.async_wait(&print);

    ioService.run();

    return 0;
}
