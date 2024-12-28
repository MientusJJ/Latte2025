# Latte Compiler

## what is it?
It is compiler to the Latte language.

Prepared in C/C++ 20.
It creates code in x86.
## Output
In the case, when input program doesn't have syntax nor semantic errors, it returns 0 and writes "OK" at stderr output.
Then it creates files input.s and executable input in the same directory

Otherwise, program in first lane writes "ERROR" and in following lines gives the informations about localization and kind of the error.
## External libraries
Program uses:

flex 2.6.4 version 

Bison (GNU Bison) 3.8.2 version

They are used as BNFC converter and significantly solve all the problems connected to parsing
## Directories
"lib" keeps default functions such like: PrintInt,PrintString etc. and additional files use to compile the output (C/C++ libraries etc.)

In "lattests" are all the tests provided by Lecturer.

"cmake-build-debug" and CMakeLists.txt are used for local compiling and I decided to not delete them from the project at this stage

## How to use this?

after unpacking the folder, type "make" to build the program.

After it, your folder, where you made unpacking should contains file "latc_x86"

Typing "./latc foo/bar/core001.lat" allows you to analyse the input of core001.lat file located in foo/bar and if it has no error it creates file foo/bar/core001.s and executable program core001 in directory foo/bar/

## Extensions
- removing redundant code
- removing not reachable code
- computing trivial expressions in compilation time
- arrays
- structs
- objects with object inheritance
- garbage collector 

