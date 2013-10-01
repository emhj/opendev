# Timer Tutorial 5

This tutorial is from the [Boost 1.54.0 ASIO Manual] [1].

This tutorial creates a class that utilizes a timer with an asynchronous wait
for counting from 0 to 9, once a second.  For each callback for a wait, another
asynchronous wait is scheduled until a counter reaches 10.

The tutorial creates a boost::asio::io\_service and adds another thread to the
service by binding the thread to the io\_service's run method.  Two threads,
the main thread and the newly created thread, operate on behalf of the
io\_service.

The tutorial makes use of the boost::bind method to a member function.  The
tutorial also makes use of the boost::asio::strand object which wraps callback
handlers to prevent those handlers from executing concurrently if wrapped with
the same strand.  Strand is a form of synchronization.

This code depends on libboost\_system, libbooth\_thread, and pthread.

The included Makefile assumes that libboost\_system and libboost\_thread can be
found in /usr/local/lib.

To run the executable (build/bin/boost\_asio\_tut\_timer5), you must set the
LD\_LIBRARY\_PATH to include /usr/local/lib.

  [1]: http://www.boost.org/doc/libs/1_54_0/doc/html/boost_asio/tutorial/tuttimer5.html
