# Demo 1

This demo introduces a basic QEMU machine running a cross compiled ARM kernel
and running it with and without the VNC server.

## Script 1

Script 1 shows how to run the Versatile Express QEMU machine with a
pre-compiled kernel.  Although basic, you can connect to the graphical display
using something like vncviewer.  The default vnc server is 127.0.0.1 on port
5900.

## Script 2

Script 2 is the same as script 1 with one extra flag: daemonize.  This will run
the machine in the background.  It is useful if trying to run machines as
background processes, such as for automated testing.

## Script 3

Script 3 shows how to redirect the kernel console output to standard output for
the Versatile Express.

## Script 4

Script 4 demonstrates running the Versatile Express and redirecting the output
to stdio.  Both the monitor and Versatile Express output are directed to stdio.
To exit the, use <C-x>.

Be careful, you will lose your shell prompt.  You can regain it by typing <C-c>
followed by 'reset'.  If you have problems regaining a working shell prompt, it
is perfectly fine to restart your terminal.  You've been warned.
