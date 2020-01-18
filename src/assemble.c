#include "asm.h"

void	assemble(char *filename)
{
    int             fd;
    t_asm_content   *content;
    t_token         *token;
    
    token = NULL;
    if ((fd = open(filename, O_RDONLY)) == -1)
        error();
    content = init_content(fd);
    while (get_next_line(fd, &content->line) > 0)
        tokenizing(&content->line, &token, &content);
    printf("name: %s\ncomment: %s\n", content->name, content->comment);
    what_are_tokens(token);
}