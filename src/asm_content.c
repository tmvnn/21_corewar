#include "asm.h"

t_asm_content	*init_content(int fd)
{
	t_asm_content	*content;

	content = (t_asm_content *)ft_memalloc(sizeof(t_asm_content));
	content->fd = fd;
	content->line = NULL;
	content->tokens = NULL;
	content->name = NULL;
	content->comment = NULL;
	return (content);
}
