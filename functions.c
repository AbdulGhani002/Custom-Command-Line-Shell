#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
void cd(char* prompt) {
    if (prompt == NULL || strcmp(prompt, "") == 0) {
        fprintf(stderr, "cd: expected argument\n");
    } else {
        if (chdir(prompt) != 0) {
            perror("cd");
            return;
        }

        DIR *d;
        struct dirent *dir;
        d = opendir(".");
        if (d) {
            printf("Contents of the directory:\n");
            while ((dir = readdir(d)) != NULL) {
                printf("%s\n", dir->d_name);
            }
            closedir(d);
        } else {
            perror("opendir");
        }
    }
}

void help(char* prompt) {
    printf("Shell Help - List of Available Commands:\n\n");
    printf("cd <directory>  - Changes the current directory to the specified directory.\n");
    printf("help            - Displays this help information.\n");
    printf("exit            - Exits the shell.\n");
    printf("pwd             - Prints the current working directory.\n");
    printf("echo <text>     - Displays the provided text.\n");
    printf("clear           - Clears the terminal screen.\n");
    printf("ls              - Lists the files in the current directory.\n");
    printf("mkdir <name>    - Creates a new directory with the specified name.\n");
    printf("rmdir <name>    - Removes the directory with the specified name.\n");
    printf("touch <file>    - Creates an empty file or updates the timestamp of the specified file.\n\n");
    printf("Type the command name followed by its arguments, if any, to use the command.\n");
}
void exit_shell(char* prompt){
    printf("Exiting shell...\n");
    exit(0);
};
void pwd(char* prompt){
    char cwd[10000];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("pwd");
    }
};
void echo(char* prompt){
    printf("%s\n",prompt);
};
void clear_screen(char* prompt){
    printf("\033[H\033[J");
};
void ls(char* prompt){
    DIR *d;
        struct dirent *dir;
        d = opendir(".");
        if (d) {
            printf("Contents of the directory:\n");
            while ((dir = readdir(d)) != NULL) {
                printf("%s\n", dir->d_name);
            }
            closedir(d);
        } else {
            perror("opendir");
        }
};
void mkdir_command(char* prompt){
    if (prompt == NULL || *prompt == '\0') {
        fprintf(stderr, "mkdir: missing operand\n");
    } else {
        
        if (mkdir(prompt) == -1) {
            perror("mkdir"); 
        } else {
            printf("Directory '%s' created successfully.\n", prompt);
        }
    }
};
void rmdir_command(char* prompt){
    if (prompt == NULL || *prompt == '\0') {
        fprintf(stderr, "rmdir: missing operand\n");
    } else {
        
        if (rmdir(prompt) == -1) {
            perror("rmdir"); 
        } else {
            printf("Directory '%s' removed successfully.\n", prompt);
        }
    }
};
void touch(char* prompt){
    if (prompt == NULL || *prompt == '\0') {
        fprintf(stderr, "touch: missing file operand\n");
        return;
    }

    int fd = open(prompt, O_WRONLY | O_CREAT , 0644);
    
    if (fd == -1) {
        perror("touch");
    } else {
        close(fd);
        printf("File '%s' touched/created successfully.\n", prompt);
    }
};