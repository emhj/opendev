# Daytime Tutorial 3

This tutorial is from the [Boost 1.54.0 ASIO Manual] [1].

This tutorial creates two classes, TcpConnection and TcpServer, to create an
asynchronous TCP daytime server.

The TcpServer class handles setting up an acceptor object, creating a new
TcpConnection shared\_ptr, and starting the TcpConnection.

The TcpConnection class is utilizes the Factory pattern to create shareable
objects that represent a TCP connection.  Upon starting a connection, the
TcpConnection class retrieves the current time and asynchronously writes the
time over the connection.

This code depends on libboost\_system and pthread.

The included Makefile assumes that libboost\_system can be found in
/usr/local/lib.

To run the executable (build/bin/boost\_asio\_tut\_daytime3\_tcp\_async\_server), you
must set the LD\_LIBRARY\_PATH to include /usr/local/lib.

  [1]: http://www.boost.org/doc/libs/1_54_0/doc/html/boost_asio/tutorial/tutdaytime3.html
