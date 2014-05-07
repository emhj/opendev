#!/bin/bash

qemu-system-arm -daemonize -M vexpress-a9 -kernel ../data/zImage
