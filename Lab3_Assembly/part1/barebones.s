# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data

.globl main

	main:						#  (1) What are we setting up here?
								#  Ans:
	pushq %rbp					#  here we are setting up the stack frame
	movq  %rsp, %rbp			#  of a function by pushing the base pointer
								#  and stack pointer in order to execute the function.

								# (2) What is going on here
								# Ans:
	movq $1, %rax				# We are sto1ring an integer value 1 to register rax
	movq $1, %rdi				# Then we are setting the destination index register
	leaq .hello.str,%rsi		# to 1 to write std-out, then setting the source index
								# register to the start of the string.


								# (3) What is syscall? We did not talk about this
								# in class.
								# Ans: syscall calls the OS kernel to execute a
	syscall						# service depending on the value stored in %rax.
								# Which syscall is being run?
								# Ans: in this case, %rax is set to 1 - meaning
								# call to sys_write.

	movq	$60, %rax			# (5) We are again setting up another syscall
	movq	$0, %rdi			# What command is it?
								# Ans: system call 60 is the sys_exit command.
	syscall

	popq %rbp					# (Note we do not really need
								# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
								# Ans: it accounts for 13 bytes of data
								# passed in assembly language.
