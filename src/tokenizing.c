/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 20:33:51 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/18 19:19:49 by idunaver         ###   ########.fr       */
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
		(*token)->next = NULL;
	}
	else
	{
		if (!(new = (t_token *)ft_memalloc(sizeof(t_token))))
			error();
		new->content = ft_strdup(content);
		new->next = NULL;
		while (copy->next)
			copy = copy->next;
		copy->next = new;
	}
}

void		tokenizing(char **line, t_token **token, t_asm_content **content)
{
	char	**buff;
	char	**copy_buff;

	buff = NULL;
	if (skip_simple_comment(line) == 1)
		return ;
	if ((buff = create_buff(line, content)) == NULL)
		return ;
	copy_buff = buff;
	while (*copy_buff)
		add_token(token, *copy_buff++);
	clear_buff(buff);
}
