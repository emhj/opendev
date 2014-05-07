#!/bin/bash

qemu-system-arm -M vexpress-a9         \
                -kernel ../data/zImage \
                -append “console=ttyAMA0,115200”
