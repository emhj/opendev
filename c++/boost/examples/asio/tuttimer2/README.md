# Timer Tutorial 2

This tutorial is from the [Boost 1.54.0 ASIO Manual] [1].

This tutorial utilizes a timer with an asynchronous wait for 5 seconds using the
Boost Date Time header file.

This code depends on libboost\_system and pthread.

The included Makefile assumes that libboost\_system can be found in
/usr/local/lib.

To run the executable (build/bin/boost\_asio\_tut\_timer2), you must set the
LD\_LIBRARY\_PATH to include /usr/local/lib.

  [1]: http://www.boost.org/doc/libs/1_54_0/doc/html/boost_asio/tutorial/tuttimer2.html
