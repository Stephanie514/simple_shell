#include <stdio.h>
#include <string.h>

void handle_comments(char *cmd)
{
    char *comment_pos = strchr(cmd, '#');

    if (comment_pos != NULL) 
    {
        *comment_pos = '\0';
    }
}
