/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 20:33:51 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/18 18:18:20 by idunaver         ###   ########.fr       */
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

static void	space_replacement(char **line, int size, char c) {
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
			*copy = c;
		copy++;
	}
}

void		clear_buff(char **buff) {
	char	**copy;

	copy = buff;
	if (!buff || !*buff)
		return ;
	while (*copy)
		ft_strdel(&(*copy++));
	free(buff);
	buff = NULL;
}

static int	add_name(char **buff, t_asm_content **content) {
	if (buff[1])
		(*content)->name = ft_strdup(buff[1]);
	clear_buff(buff);
	return (1);
}

static int	add_comment(char **buff, t_asm_content **content) {
	if (buff[1])
		(*content)->comment = ft_strdup(buff[1]);
	clear_buff(buff);
	return (1);
}

static int	check_name_or_comment(char **buff, t_asm_content **content) {
	if (!buff || !*buff || ft_isspace(**buff))
		return (1);
	if (ft_strcmp(*buff, NAME_CHAMP) == 0)
		return(add_name(buff, content));
	else if (ft_strcmp(*buff, COMMENT_CHAMP) == 0)
		return(add_comment(buff, content));
	return (0);
}

static int	skip_simple_comment(char **line) {
	if (**line == '#') {
		ft_strdel(line);
		return (1);
	}
	return (0);
}

static char	**create_buff(char **line, t_asm_content **content) {
	char	**buff;
	char	c;

	c = (**line == '.') ? '"' : ',';
	space_replacement(line, ft_strlen(*line), c);
	buff = ft_strsplit(*line, c);
	if (**line == '.') {
		if (check_name_or_comment(buff, content) == 1)
			return (NULL);
	}
	ft_strdel(line);
	return (buff);
}

void		tokenizing(char **line, t_token **token, t_asm_content **content) {
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
