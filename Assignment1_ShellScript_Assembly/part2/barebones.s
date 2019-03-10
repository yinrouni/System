# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
					# (1) What are we setting up here?
					# Ans: Push the old base pointer onto the stack to save it for later.
	pushq %rbp			# Then copy the value of the stack pointer to the base pointer.
	movq  %rsp, %rbp		# %rbp points to the base of the main's stack.

					# (2) What is going on here
					# Ans: These are the parameters we have to pass to the system call.
	movq $1, %rax			# Specify which function we want to call by writing the number into the rax register; 1 for write.
	movq $1, %rdi			# Put 1 into the rdi register to point to the standard output.  
	leaq .hello.str,%rsi		# Loads the address of .hello.str in rsi register, which contains the content and length of the string. 


					# (3) What is syscall? We did not talk about this
					# in class.
					# Ans: Syscalls are the interface between user program and the Linux kernel
					# They are uesd to let the kernel preform various system tasks.   
	syscall				# Which syscall is being run?
					# Ans: write

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans: call printf

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans: System call 60 is exit, and return error code 0. 
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans: In "Hello" and "World", there are 10 characters. 
					# Plus, there are still a space, a "!" and a newline code.
					# There are 13 bytes in total. 	
