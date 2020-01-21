/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:21:29 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/21 21:43:59 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
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

# define LIVE "live"
# define LD "ld"
# define ST "st"
# define ADD "add"
# define SUB "sub"
# define AND "and"
# define OR "or"
# define XOR "xor"
# define ZJMP "zjmp"
# define LDI "ldi"
# define STI "sti"
# define FORK "fork"
# define LLD "lld"
# define LLDI "lldi"
# define LFORK "lfork"
# define AFF "aff"

typedef	struct			s_token
{	
	char				*content;
	char				*type;
	struct s_token		*next;
}						t_token;

typedef struct			s_strings
{
	t_token				*string;
	struct s_strings	*next;
}						t_strings;

typedef struct			s_asm_content
{	
	int					fd;
	char				*line;
	char				**buff;
	t_strings			**tokens;
	char				*name;
	char				*comment;
}						t_asm_content;

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
void				what_are_strings(t_strings *rows);

/* title.c */
int					skip_simple_comment_emptyline(char **line);
int					check_name_or_comment(char **buff, t_asm_content **content);

/* tokenizing.c */
void				tokenizing(char **line, t_strings **row, t_asm_content **content);

/* string.c */
void    			add_string(t_token **tokens, t_strings **row);

#endif
