## SIMPLE SHELL PROJECT

### DESCRIPTION:
The project "simple_shell" is an implementation of a simple UNIX shell that accepts and executes user commands.
It is designed to perform the same basic functions as the built-in shell (/bin/sh) on UNIX systems.

### REQUIREMENTS:
- The program must be written in C.
- The program must compile without any errors or warnings using gcc on Ubuntu 20.04 LTS
- The program must use the Betty style.
- The program must not have any memory leaks or errors.
- The program must have a prompt "$ " that waits for user input.
- The program must exit when the user types "exit" or presses Ctrl-D.
- The program must be able to execute commands with arguments and handle pipes and redirections.
## COMPILATION COMMAND:
The shell will be compiled this way:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

##AUTHORIZED FUNCTIONS:
- access
- execve
- fork
- free
- getline
- isatty
- malloc
- printf
- fprinf
- sprintf
- strtok
- wait

##RETURN:
- 0 on success.
- 127 if the program was not found.
- 128 if the memory allocation failed.
- 129 if the child proccess could not be called
- 130 if the call command was not executed successfully

### USAGE:
##INTERACTIVE MODE:
To run the program, execute the following command:

```
./hsh
```

##NON INTERACTIVE MODE:
To run the program in non interactive mode, execute the following command:

```
echo "<your command>" | ./hsh
```
### EXAMPLES:
```
$ ls

AUTHORS README.md Simpleshell flowchart.png main.c man_1_simpleshell simple_shell.h strings.c utility.c
```
```
echo "ls" | ./hsh

AUTHORS README.md Simpleshell flowchart.png main.c man_1_simpleshell simple_shell.h strings.c utility.c
```

### TESTING:
- Using Valgrind to fix memorys leaks
- Manual tests for expected and edge cases.
- Testing a couple of time the same command to check if it's dont crash (segmentation fault)
- Using online compiler to check more often the issues due to the code

### AUTHORS:
Marc Pourias, Arnaud Tily
