## SIMPLE SHELL PROJECT

### DESCRIPTION:
The project "simple_shell" is an implementation of a simple UNIX shell that accepts and executes user commands.
It is designed to perform the same basic functions as the built-in shell (/bin/sh) on UNIX systems.

### COMPILATION COMMAND:
To compile the simpleshell program, use the following command:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```

### USAGE:
To run the program, execute the following command:

```
./simple_shell
```

### REQUIREMENTS:
- The program must be written in C.
- The program must compile without any errors or warnings using gcc.
- The program must use the Betty style.
- The program must not have any memory leaks or errors.
- The program must have a prompt "$" that waits for user input.
- The program must exit when the user types "exit" or presses Ctrl-D.
- The program must be able to execute commands with arguments and handle pipes and redirections.

### EXAMPLES:
```
$ ls
```

### TESTING:
- Unit tests using a testing framework like check.
- Manual tests for expected and edge cases.
- Integration tests with other shell scripts and programs.

### AUTHORS:
Marc Pourias, Arnaud Tily
