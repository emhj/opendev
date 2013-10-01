#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

namespace io = boost::asio;

void print(const boost::system::error_code &,
           io::deadline_timer *t,
           int *count)
{
    if (*count < 5)
    {
        std::cout << *count << std::endl;
        ++(*count);
        t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
        t->async_wait(
            boost::bind(print,
                        io::placeholders::error,
                        t,
                        count)
        );
    }
}

int main(void)
{
    io::io_service ioService;
    int count = 0;

    io::deadline_timer t(ioService, boost::posix_time::seconds(1));

    t.async_wait(
        boost::bind(print,
                    io::placeholders::error,
                    &t,
                    &count)
    );

    ioService.run();

    std::cout << "Final count is " << count << std::endl;

    return 0;
}
