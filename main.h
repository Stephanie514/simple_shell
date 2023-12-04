#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <errno.h>

extern char **environ;
int isspace(int c);
int _strcmp(const char *s1, const char *s2);
void umgebung_builtin(void);
void tokenize_input(char *userinput, char **userinput_cpy);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void repl_loop(int *exit_status);
int execute_command(char **userinput_cpy);
char *get_path(char *cmd);
void repl_exit(int exit_status);
char *_strtok(char *str, const char *delim);
char *_strtrim(char *str);
int _strlen(const char *s);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_getenv(const char *envv);

#endif
