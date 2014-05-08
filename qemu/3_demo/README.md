# Demo 3

This demo illustrates creating a basic root filesystem and running linux on a
QEMU Versatile Express machine.

## Script 1

This script creates a 100 MiB raw QEMU Disk image, test.img, mounts the disk
image, creates a basic root filesystem structure, copies a pre-compiled
statically linked busybox program to the root filesystem, and adds some basic
symbolic links for some core utilities.  Finally, the script unmounts test.img.

## Script 2

This script mimics Demo 2's `script\_4.sh`, with the exception that it uses the
`-sd` parameter rather than the `-drive` parameter.  Notice that busybox's init
process runs because it is at /bin/init (via symbolic link).

## Script 3

This script introduces the `init` kernel parameter for configuring a specific
process to boot.  This will allow you to play around with the basic root
filesystem.  Be careful: once you type `exit`, the machine will die.

## Script 4

This script modifies test.img to have a simple `rcS` initialization script.  It
mounts the temporary proc and devtmpfs filesystems so that the default busybox
init can startup properly.

As of the Linux 3.10 kernel, the devtmpfs can be auto-mounted.  See the Generic
Drivers section of the menu configuration when building the kernel.

## Script 5

This script is verbatim `script\_2.sh`.  It is merely here for indicating the
next step.

## Script 6

This script introduces the `-curses` parameter as well as redirects the qemu
monitor to a pseudoterminal (see the Demo 0 README).  The `-curses` parameter
can be used to better control the terminal process. In some cases, <C-c> can
cause the QEMU process to die.  The `-curses` parameter can solve this issue.
