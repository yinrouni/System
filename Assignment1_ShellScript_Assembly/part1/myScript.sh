#!/bin/bash
# The line above makes your script executable.
# You should write your tutorial in here.
# Include comments inline with your script explaining what is going on.

# You might start out by first saying the purpose of the script and
# demonstrating its usage.

# I don't want it to be shared on piazza board.

# Problem Statement: 

# Usually when we search for different files and dictionaries within the computer system,
# we use 'ls' command to list all file and directories in the current directories. In this way, 
# we can decide if we find the target file or where we have to keep searching. However, there is 
# a drawback in the 'ls' command. When there is a large number of files and directories in the
# current directoriesy, and the target file is in a nested dictionary which is hard to access in
# one step simply. 

# Sometimes we need a more visual overview of the nested files and directories.
# It turns out that there is a useful command to address these cases. It's called 'tree'.
# 'tree' command is recursive directory listing program that produces a depth-indented listing 
# of files. 'tree' lists the files in the current directory. Upon completion of listing all the
# files and directories found, 'tree' returns the total number of the files and directories listed.

# 'tree' can easily visualizing directory structures. Furthermore, it can mark the files and 
# directories in different colors according to the their file type. It will user to find what they
# want easily and specify the file type. 

# Meanwhile, when the targe file is exactly in the current directory and there are lots of other
# files anf nested directories there. It can make it harder to notice the target using 'tree' 
# command. Instead, 'ls' command works better in this case. 

# 'tree' and 'ls' commands can be applied effectively in different cases. Both of them have their
# pros and cons. As a result, I combine them in myScript.sh to orient myself efficiently.

# Name of command: ls
# Example of its usage:
# -bash-4.2$ ls
# part1  part2  README.md 

# Name of command: tree
# Example of its usage:
# -bash-4.2$ tree
# .
# ├── part1
# │   ├── myScript.sh
# │   └── Readme.md
# ├── part2
# │   ├── barebones
# │   ├── barebones.s
# │   ├── function.s
# │   ├── hello
# │   ├── hello2
# │   ├── hello2.c
# │   ├── hello.o
# │   ├── hello.s
# │   ├── prog1
# │   ├── README.md
# │   ├── tool
# │   └── tool.c
# └── README.md
#
# 2 directories, 15 files

# tree -C
# This is the option to use color output.

# Name of command: echo
# 'echo' command displays number or string on standard output in the terminal.
# Example of its usage:
# -bash-4.2$ echo "abc"
# abc

# Here is the myScript.sh script.

# First, 'ls' command will be executed to list all the files and directories in the current
# directory without display any nested files and directories. If the target file is in the current 
# directory, users can find it easily. It can make the porcess more clear. 
# It will also print out the number of directories inside.

# Then, echo "==========", as a seperate line between ls and tree output. It can avoid the ambiguity
# the two output.

# Finally, execute 'tree -C' command to visualize directory structures. Display all the nested files
# and directories. Mark different types of files and directories in different colors, making it 
# easier for the further search.

# usage: sh myscript.sh

ls
echo " "
echo "total directories inside: "
ls | wc -l
echo "==============================="
tree -C


# Example of output:
# myScript.sh  Readme.md	test  test1
 
# total directories inside: 
# 4
# ===============================
# .
# ├── myScript.sh
# ├── Readme.md
# ├── test
# │   ├── inside_test
# │   │   ├── test
# │   │   └── test.c
# │   └── test.txt
# └── test1

# 3 directories, 5 files

# (The '.' on the third line should be in blue,
#  and the test in inside_test should be in green.)
