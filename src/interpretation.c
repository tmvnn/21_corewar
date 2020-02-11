/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:35:43 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/26 15:35:31 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int     parse(char *str, char *pattern)
{
    int         err;
    regex_t     reg1;
    regmatch_t  pm;

    err = regcomp(&reg1, pattern, REG_EXTENDED);
    if (err != 0)
    {
        regfree(&reg1);
        printf("error with regex in file interpretation.c\n");
        return (0);
    }
    if (!regexec(&reg1, str, 0, &pm, 0))
    {
        regfree(&reg1);
        return (1);
    }
    regfree(&reg1);
    return (0);
}

void	interpretation(t_token *tokens)
{
	if(parse(tokens->content, LABEL))
		tokens->type = ft_strdup(LABEL_NAME);
	else if (parse(tokens->content, INSTRACTION))
		tokens->type = ft_strdup(INSTRACTION_NAME);
	else if (parse(tokens->content, REGISTER))
		tokens->type = ft_strdup(REGISTER_NAME);
	else if (parse(tokens->content, DIRECT_LABEL))
		tokens->type = ft_strdup(DIRECT_LABEL_NAME);
	else if (parse(tokens->content, DIRECT))
		tokens->type = ft_strdup(DIRECT_NAME);
    else if (parse(tokens->content, INDIRECT))
        tokens->type = ft_strdup(INDIRECT_NAME);
    else if (parse(tokens->content, INDIRECT_LABEL))
        tokens->type = ft_strdup(INDIRECT_LABEL_NAME);
}
