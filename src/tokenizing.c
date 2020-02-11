/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 20:33:51 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/26 15:32:15 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	add_token(t_token **token, char *content)
{
	t_token	*copy;
	t_token	*new;

	copy = *token;
	if (*content == ' ' || *content == '\n' || *content == '\0')
		return ;
	if (!copy)
	{
		if (!(*token = (t_token *)ft_memalloc(sizeof(t_token))))
			error();
		(*token)->content = ft_strdup(content);
		interpretation(*token);
		(*token)->memory_size = 0;
		(*token)->next = NULL;
		(*token)->previous = NULL;
	}
	else
	{
		if (!(new = (t_token *)ft_memalloc(sizeof(t_token))))
			error();
		new->content = ft_strdup(content);
		interpretation(new);
		new->next = NULL;
		new->memory_size = 0;
		while (copy->next)
			copy = copy->next;
		copy->next = new;
		new->previous = copy;
	}
}

void		tokenizing(char **line, t_strings **row, t_asm_content **content)
{
	char	**buff;
	char	**copy_buff;
	t_token	*tokens;

	tokens = NULL;
	buff = NULL;
	if (skip_simple_comment_emptyline(line) == 1)
		return ;
	if ((buff = create_buff(line, content)) == NULL)
		return ;
	copy_buff = buff;
	while (*copy_buff)
	{
		if (**copy_buff == ';' || **copy_buff == '#')
			break ;
		add_token(&tokens, *copy_buff++);
	}
	add_string(&tokens, row);
	clear_buff(buff);
}
