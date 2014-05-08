# Demo 2

This demo briefly shows off QEMU's disk imaging utility, `qemu-img`.

Try `qemu-img -help` for more information.

## Script 1

Script 1 creates a 100 MiB raw disk image called test.

## Script 2

Script 2 formats the 100 MiB test image as ext2, creates a temporary mount
point, and mounts the image to the mount point. The test image is mounted using
a loopback device.

After mounting the image, the `hello\_world.c` program is cross-compiled and
copied to `/etc/init` on the image.  `/etc/init` is a default path the kernel
looks for the init process.

## Script 3

Script 3 demonstrates how to add a file as an SD card to the Versatile Express.
Note the difference in output between Demo 1's last command and this command.

## Script 4

Script 4 demonstrates the `root` parameter to the Linux kernel which specifies
what device to mount as the root filesystem.

After setting this parameter, you should see "Hello, World!" in the output if
script 2 ran correctly.
