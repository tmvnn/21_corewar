/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:15:51 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/18 23:58:51 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	clean_t_strings(t_strings **tokens)
{
	t_token		*p_token;
	t_token		*prev_token;
	t_strings	*p_strings;

	p_token = NULL;
	prev_token = NULL;
	p_strings = NULL;
	if (!tokens)
		return ;
	while (*tokens)
	{
		p_token = (*tokens)->string;
		while (p_token)
		{
			ft_strdel(&p_token->content);
			ft_strdel(&p_token->type);
			prev_token = p_token;
			p_token = p_token->next;
			free(prev_token);
		}
		p_strings = *tokens;
		*tokens = (*tokens)->next;
		free(p_strings);
	}
}

static void	clean_content(t_asm_content **content)
{
	clean_t_strings((*content)->tokens);
	free((*content)->header);
	(*content)->header = NULL;
	ft_strdel(&(*content)->bytecode);
	(*content)->bytecode = NULL;
	ft_strdel(&(*content)->name);
	(*content)->name = NULL;
	ft_strdel(&(*content)->comment);
	(*content)->comment = NULL;
	ft_strdel(&(*content)->new_filename);
	(*content)->new_filename = NULL;
	free(*content);
	free((*content)->buf);
	(*content)->buf = NULL;
	content = NULL;
}

char		*clean_memory(t_asm_content **content)
{
	if (*content)
		clean_content(content);
	return (NULL);
}
