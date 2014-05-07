# Demo 2

This demo briefly shows off QEMU's disk imaging utility, `qemu-img`.

Try `qemu-img -help` for more information.

## Script 1

Script 1 creates a 100 MiB raw disk image called test.

## Script 2

Script 2 formats the 100 MiB test image as ext2, creates a temporary mount
point, and mounts the image to the mount point.

The test image is mounted using a loopback device.

## Script 3

Script 3 demonstrates how to unmount the mounted temporary directory and removes the mount point.
