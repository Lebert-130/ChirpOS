#!/bin/bash

YELL='\033[1;33m'
GRN='\033[0;32m'
CYAN='\033[0;36m'
LGRN='\033[1;32m'
NC='\033[0m'

# COMPILE BOOT.O
echo -e "\n${CYAN}Compiling bootstrap asm...${NC}"
i686-elf-as boot.s -o boot.o
echo -e "${LGRN}Done!${NC}"

# COMPILE KERNEL FILE
echo -e "${CYAN}Compiling kernel...${NC}"
sudo i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
echo -e "${LGRN}Done!${NC}"

# COMPILE LINKER FILE
echo -e "${CYAN}Compiling linker file...${NC}"
sudo i686-elf-gcc -T linker.ld -o ChirpOS.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc
echo -e "${LGRN}Done!${NC}"

# COPY OS BIN
sudo cp ChirpOS.bin ChirpISO/boot/ChirpOS.bin

# COPY GRUB CFG
sudo cp grub.cfg ChirpISO/boot/grub/grub.cfg

# COMPILE ISO FILE
echo -e "${CYAN}Building ISO file...${NC}"
sudo grub-mkrescue -o ChirpOS.iso ChirpISO
echo -e "${YELL}Build done!\n${NC}"
