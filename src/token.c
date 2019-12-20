#include "asm.h"

void	add_token(t_token **token, char *content) {
	t_token	*copy;
	t_token	*new;
	t_token	*end;

	copy = *token;
	if (!copy)
	{
		if (!(*token = (t_token *)ft_memalloc(sizeof(t_token))))
			error();
		(*token)->content = content;
		(*token)->next = NULL;
	}
	else
	{
		if (!(new = (t_token *)ft_memalloc(sizeof(t_token))))
			error();
		new->content = content;
		new->next = NULL;
		while (copy->next)
			copy = copy->next;
		copy->next = new;	
	}
}