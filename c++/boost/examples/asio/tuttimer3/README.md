# Timer Tutorial 3

This tutorial is from the [Boost 1.54.0 ASIO Manual] [1].

This tutorial utilizes a timer with an asynchronous wait for counting from 0 to
4, once a second.  For each callback for a wait, another asynchronous wait is
scheduled until a counter reaches 5.

This code depends on libboost\_system and pthread.

The included Makefile assumes that libboost\_system can be found in
/usr/local/lib.

To run the executable (build/bin/boost\_asio\_tut\_timer3), you must set the
LD\_LIBRARY\_PATH to include /usr/local/lib.

  [1]: http://www.boost.org/doc/libs/1_54_0/doc/html/boost_asio/tutorial/tuttimer3.html