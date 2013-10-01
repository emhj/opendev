#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

namespace io = boost::asio;
namespace posix_time = boost::posix_time;

class Printer
{
public:
    Printer(io::io_service &io) :
        strand_(io),
        timer1_(io, posix_time::seconds(1)),
        timer2_(io, posix_time::seconds(1)),
        count_(0)
    {
        timer1_.async_wait(
            strand_.wrap(
                boost::bind(&Printer::print1,
                            this)
            )
        );
        timer2_.async_wait(
            strand_.wrap(
                boost::bind(&Printer::print2,
                            this)
            )
        );
    }

    ~Printer()
    {
        std::cout << "Final count is " << count_ << std::endl;
    }

    void print1()
    {
        if (count_ < 10)
        {
            std::cout << "Timer 1 (Thread "
                      << boost::this_thread::get_id()
                      << "): "
                      << count_
                      << std::endl;
            ++count_;
            timer1_.expires_at(timer1_.expires_at() + posix_time::seconds(1));
            timer1_.async_wait(
                strand_.wrap(
                    boost::bind(&Printer::print1,
                                this)
                )
            );
        }
    }

    void print2()
    {
        if (count_ < 10)
        {
            std::cout << "Timer 2 (Thread "
                      << boost::this_thread::get_id()
                      << "): "
                      << count_
                      << std::endl;
            ++count_;
            timer2_.expires_at(timer2_.expires_at() + posix_time::seconds(1));
            timer2_.async_wait(
                strand_.wrap(
                    boost::bind(&Printer::print2,
                                this)
                )
            );
        }
    }

private:
    io::strand strand_;
    io::deadline_timer timer1_;
    io::deadline_timer timer2_;
    int count_;
};

int main(void)
{
    io::io_service ioService;
    Printer p(ioService);
    boost::thread t(
        boost::bind(
            &io::io_service::run,
            &ioService
        )
    );

    ioService.run();
    t.join();

    return 0;
}
