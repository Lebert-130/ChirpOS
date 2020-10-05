#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/chirpos.kernel isodir/boot/chirpos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "ChirpOS" {
	multiboot /boot/chirpos.kernel
}
EOF
grub-mkrescue -o chirpos.iso isodir