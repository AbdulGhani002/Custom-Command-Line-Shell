#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
void cd(char* prompt);
void help(char* prompt);
void exit_shell(char* prompt);
void pwd(char* prompt);
void echo(char* prompt);
void clear_screen(char* prompt);
void ls(char* prompt);
void mkdir_command(char* prompt);
void rmdir_command(char* prompt);
void touch(char* prompt);
const char *in_built_commands[10] = {
    "cd",    // Change directory
    "help",  // Show help information
    "exit",  // Exit the shell
    "pwd",   // Print working directory
    "echo",  // Echo arguments
    "clear", // Clear the terminal screen
    "ls",    // List directory contents
    "mkdir", // Create a new directory
    "rmdir", // Remove directory
    "touch"  // Create an empty file or update file timestamp
};
void (*command_functions[10])(char* prompt) = {
    cd,
    help,
    exit_shell,
    pwd,
    echo,
    clear_screen,
    ls,
    mkdir_command,
    rmdir_command,
    touch
};
#include "functions.c"