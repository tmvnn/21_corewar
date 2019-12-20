#include "asm.h"

void	assemble(char *filename)
{
    int             fd;
    t_asm_content   *content;
    // t_token         *token;
    
    if ((fd = open(filename, O_RDONLY)) == -1)
        error();
    content = init_content(fd);
    while (read_content(fd, content) != -1)
    {
        // тут должен быть парсинг
        ft_strdel(&content->line);
    }
}