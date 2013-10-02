# Daytime Tutorial 2

This tutorial is from the [Boost 1.54.0 ASIO Manual] [1].

This tutorial creates a simple, synchronous tcp daytime server that listens for
TCP connections over port 13 using boost::asio::ip::tcp's socket and acceptor
classes.

This code depends on libboost\_system and pthread.

The included Makefile assumes that libboost\_system can be found in
/usr/local/lib.

To run the executable (build/bin/boost\_asio\_tut\_daytime1\_tcp\_server), you
must set the LD\_LIBRARY\_PATH to include /usr/local/lib.

  [1]: http://www.boost.org/doc/libs/1_54_0/doc/html/boost_asio/tutorial/tutdaytime2.html
