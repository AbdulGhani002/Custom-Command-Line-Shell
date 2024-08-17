#include "main.h"
void execute(char *prompt)
{
    prompt[strcspn(prompt, "\n")] = 0;
    char *command = strtok(prompt, " ");
    char *args = strtok(NULL, "");
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(command, in_built_commands[i]) == 0)
        {
            printf("Executing built-in command: %s\n", in_built_commands[i]);
            command_functions[i](args);
            return;
        }
    }
}
int main(void)
{
    char prompt[10000];
    while (1)
    {
        custom_prompt();
        fgets(prompt, sizeof(prompt), stdin);
        execute(prompt);
    }
    reset_color();
}