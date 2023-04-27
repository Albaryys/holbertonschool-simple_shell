## SIMPLE SHELL PROJECT

### DESCRIPTION:
The project "simple_shell" is an implementation of a simple UNIX shell that accepts and executes user commands.
It is designed to perform the same basic functions as the built-in shell (/bin/sh) on UNIX systems.

### REQUIREMENTS:
- The program must be written in C.
- The program must compile without any errors or warnings using gcc.
- The program must use the Betty style.
- The program must not have any memory leaks or errors.
- The program must have a prompt "Ownshell$" that waits for user input.
- The program must exit when the user types "exit" or presses Ctrl-D.
- The program must be able to execute commands with arguments and handle pipes and redirections.

### COMPILATION COMMAND:
To compile the simpleshell program, use the following command:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

### USAGE:
To run the program, execute the following command:

```
./hsh
```

### EXAMPLES:
```
Ownshell$ ls

AUTHORS README.md Simpleshell flowchart.png main.c man_1_simpleshell simple_shell.h strings.c utility.c
```

### TESTING:
- Using Valgrind to fix memorys leaks
- Manual tests for expected and edge cases.
- Testing a couple of time the same command to check if it's dont crash (segmentation fault)
- Using online compiler to check more often the issues due to the code

### AUTHORS:
Marc Pourias, Arnaud Tily
