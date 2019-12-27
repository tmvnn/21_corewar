/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 20:33:51 by idunaver          #+#    #+#             */
/*   Updated: 2019/12/27 21:31:08 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		add_token(t_token **token, char *content) {
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

static void	space_replacement(char **line, int size) {
	char	*copy;
	int		quotes;

	quotes = 0;
	copy = *line;
	while (*copy && --size != -1) {
		if (*copy == '"' && quotes == 1)
			quotes = 0;
		if (*copy == '"' && quotes == 0)
			quotes = 1;
		if (ft_isspace(*copy) && quotes == 0)
			*copy = ',';
		copy++;
	}
}

void		clear_buff(char **buff) {
	char	**copy;

	copy = buff;
	if (!buff)
		return ;
	while (*copy)
		ft_strdel(&(*copy++));
	free(buff);
	buff = NULL;
}

void		tokenizing(char **line, t_token **token) {
	char	**buff;
	char	**copy_buff;

	buff = NULL;
	space_replacement(line, ft_strlen(*line));
	buff = ft_strsplit(*line, ',');
	copy_buff = buff;
	ft_strdel(line);
	while (*copy_buff)
		add_token(token, *copy_buff++);
	clear_buff(buff);
}
