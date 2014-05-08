# Demo\_0

This demo introduces some of the basic commands for using QEMU.

After installing QEMU with ARM softmmu support, try the following commands:

    qemu-system-arm
    qemu-system-arm --help
    qemu-system-arm -M help
    qemu-system-arm --nographic
    qemu-system-arm --nographic -monitor pty

## VNC

Note that by default, QEMU runs a VNC server for a graphical display.  This can
be disabled with a <C-c> (Cntrl+c).

## QEMU Monitor

The QEMU Monitor allows you access to the virtual machine's components
directly.  If the monitor is started on stdio, The help menu can be display
with <C-h> and the console can be accessed with <C-c>.  If using QEMU monitor
from a pseudoterminal (pty), then the <C-h> and <C-c> options are no longer
needed.
