# Daytime Tutorial 1

This tutorial is from the [Boost 1.54.0 ASIO Manual] [1].

This tutorial creates a simple echo tcp client that connects to a given host
using boost::asio::io::tcp's resolver, query, and socket classes, as well as
boost::asio's connect method.

This code depends on libboost\_system and pthread.

The included Makefile assumes that libboost\_system can be found in
/usr/local/lib.

To run the executable (build/bin/boost\_asio\_tut\_daytime1\_tcp\_client), you
must set the LD\_LIBRARY\_PATH to include /usr/local/lib.

  [1]: http://www.boost.org/doc/libs/1_54_0/doc/html/boost_asio/tutorial/tutdaytime1.html
