/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:21:29 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/18 19:22:46 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define EXP_ASM ".s"
# define EXP_ASM_LEN 2
# define BUFF_S 2048
# define NAME_CHAMP ".name"
# define COMMENT_CHAMP ".comment"

typedef	struct		s_token
{
	char			*content;
	struct s_token	*next;
}					t_token;

typedef struct		s_asm_content
{
	int				fd;
	char			*line;
	char			**buff;
	t_token			*tokens;
	char			*name;
	char			*comment;
}					t_asm_content;

/* asm_content.c */
t_asm_content		*init_content(int fd);

/* assemble.c */
void				assemble(char *filename);

/* buffer.c */
void				clear_buff(char **buff);
char				**create_buff(char **line, t_asm_content **content);

/* error.c */
void				error(void);

/* filename.c */
int					valid_filename_asm(const char *filename);

/* helper.c - потом удалить */
void				what_are_tokens(t_token *token);

/* title.c */
int					skip_simple_comment(char **line);
int					check_name_or_comment(char **buff, t_asm_content **content);

/* tokenizing.c */
void				tokenizing(char **line, t_token **token, t_asm_content **content);

#endif
