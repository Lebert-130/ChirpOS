# Declare constants for the multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Reserve a stack for the initial thread.
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# The kernel entry point.
.section .text
.global _start
.type _start, @function

gdtr:
limit:	.word 0 # For limit
base:	.long 0 # For base storage

_start:
	movl $stack_top, %esp

	# Enable A20
	inb $0x92, %al
	orb $2, %al
	outb %al, $0x92

	# Set GDT
	call setGdt

	# Enter Protected Mode
	call enterPrt

	# Call the global constructors.
	call _init

	# Transfer control to the main kernel.
	call kernel_main

	# Hang if kernel_main unexpectedly returns.
	cli
1:	hlt
	jmp 1b
.size _start, . - _start

setGdt:
	movl 4(%esp),	%eax
	movl %eax,	base
	movw 8(%esp),	%ax
	movw %ax,	gdtr
	lgdt gdtr
	ret

enterPrt:
	cli # Disable interrupts
	lgdt gdtr # Load GDT register with start address of Global Descriptor Table
	movl %cr0, %eax
	orb $1, %al # set PE (Protection Enable) bit in CR0 (Control Register 0)
	movl %eax, %cr0

	# Perform far jump to selector 08h (offset into GDT, pointing at a 32bit PM code segment descriptor)
	# to load CS with proper PM32 descriptor

	jmp PModeMain

PModeMain:
# Load DS, ES, FS, GS, SS, ESP