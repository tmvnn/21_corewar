/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebase_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:13:59 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/20 19:55:58 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*rebase_str_first_case(char *content)
{
	char *result;
	char *str_cat;
	char *temp;
	char *temp1;
	char *separator;
	char *direct_char;

	separator = screen(SEPARATOR_CHAR);
	direct_char = screen(DIRECT_CHAR);
	temp = ft_strchr(content, direct_char);
	temp1 = ft_strsub(content, 0, strlen(content) - strlen(temp));
	str_cat = ft_strjoinwcm(temp1, separator);
	result = ft_strjoinwcm(str_cat, temp);
	ft_strdel(&content);
	ft_strdel(&separator);
	ft_strdel(&direct_char);
	return (result);
}

char	*rebase_str_second_case(char *content)
{
	char *result;
	char *str_cat;
	char *temp;
	char *temp1;
	char *separator;
	char *label_char;

	separator = screen(SEPARATOR_CHAR);
	label_char = screen(LABEL_CHAR);
	temp = ft_strchr(content, label_char) + 1;
	temp1 = ft_strsub(content, 0, strlen(content) - strlen(temp));
	str_cat = ft_strjoinwcm(temp1, separator);
	result = ft_strjoinwcm(str_cat, temp);
	ft_strdel(&content);
	ft_strdel(&separator);
	ft_strdel(&label_char);
	return (result);
}

char	*rebase_str_third_case(char *content)
{
	char *result;
	char *str_cat;
	char *temp;
	char *temp1;
	char *separator;
	char *comment_char;
	char *alt_comment_char;

	separator = screen(SEPARATOR_CHAR);
	comment_char = screen(COMMENT_CHAR);
	alt_comment_char = screen(ALT_COMMENT_CHAR);
	if (!(temp = ft_strchr(content, comment_char)))
		temp = ft_strchr(content, alt_comment_char);
	temp1 = ft_strsub(content, 0, strlen(content) - strlen(temp));
	str_cat = ft_strjoinwcm(temp1, separator);
	result = ft_strjoinwcm(str_cat, temp);
	ft_strdel(&content);
	ft_strdel(&separator);
	ft_strdel(&comment_char);
	ft_strdel(&alt_comment_char);
	return (result);
}

// char	*rebase_str_fourth_case(char *content)
// {
// 	char *result;
// 	char *str_cat;
// 	char *temp;
// 	char *temp1;
// 	char *separator;
// 	char *alt_comment_char;

// 	separator = screen(SEPARATOR_CHAR);
// 	alt_comment_char = screen(COMMENT_CHAR);
// 	temp = ft_strchr(content, alt_comment_char);
// 	temp1 = ft_strsub(content, 0, strlen(content) - strlen(temp));
// 	str_cat = ft_strjoinwcm(temp1, separator);
// 	result = ft_strjoinwcm(str_cat, temp);
// 	ft_strdel(&content);
// 	ft_strdel(&separator);
// 	ft_strdel(&alt_comment_char);
// 	return (result);
// }
