# Daytime Tutorial 4

This tutorial is from the [Boost 1.54.0 ASIO Manual] [1].

This tutorial creates a simple, synchronous udp daytime server that listens for
UDP datagrams over port 13 using boost::asio::ip::udp's socket class.  The
server responds by utilizing the boost::asio::ip::udp::endpoint class to
determine how to talk back to the client.

This code depends on libboost\_system and pthread.

The included Makefile assumes that libboost\_system can be found in
/usr/local/lib.

To run the executable (build/bin/boost\_asio\_tut\_daytime4\_tcp\_sync\_server), you
must set the LD\_LIBRARY\_PATH to include /usr/local/lib.

  [1]: http://www.boost.org/doc/libs/1_54_0/doc/html/boost_asio/tutorial/tutdaytime4.html
