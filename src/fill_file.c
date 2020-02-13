#include "asm.h"

int		check(t_token *pointer)
{
	if (!ft_strcmp(pointer->type, INSTRACTION_NAME) && (!ft_strcmp(pointer->content, LIVE_NAME) || !ft_strcmp(pointer->content, FORK_NAME) || !ft_strcmp(pointer->content, LFORK_NAME) || !ft_strcmp(pointer->content, ZJMP_NAME)))
		return (0);
	return (1);
}

int		fill_write(t_token *pointer, t_strings *rows, t_asm_content **content)
{
	fill_write_code_instraction(pointer->content, content);
	if (check(pointer))
		fill_write_code_arg(pointer, content);
	fill_write_arg(pointer, rows, content);
	return (1);
}

int		fill_file(t_strings *rows, t_asm_content **content)
{
	t_token		*pointer;
	t_strings	*rows_start;

	rows_start = rows;
	while (rows)
	{
		pointer = rows->string;
		while (pointer)
		{
			if (!ft_strcmp(pointer->type, INSTRACTION_NAME))
			{
				if (!fill_write(pointer, rows_start, content))
					return (0);
			}
			pointer = pointer->next;
		}
		rows = rows->next;
	}
	return (1);
}