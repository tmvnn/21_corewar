/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:21:29 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/12 16:27:10 by timuryakubo      ###   ########.fr       */
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
# define EXP_COR ".cor"
# define EXP_ASM_LEN 2
# define EXP_COR_LEN 4
# define BUFF_S 2048
# define OCTET_SIZE 8
# define HEADER_SIZE (PROG_NAME_LENGTH + COMMENT_LENGTH + (4 * OCTET_SIZE))
# define FOURTH_BYTE 3
# define ASSEMBLE 'c'
# define DISASSEMBLE 's'
# define MAGIC_NUMBER_SIZE 4
# define NULL_SIZE 4
# define CHMP_CODE_VAR_SIZE 4

# define NAME_CMD_LEN 5
# define COMMENT_CMD_LEN 8
# define SPACE_LEN 1
# define D_QUOTE_LEN 1
# define SLASH_N_LEN 1

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
	int					fd_dst;
	int					fd_src;
	char				asm_dsm_flag;
	char				*line;
	char				**buff;
	t_strings			**tokens;
	char				*name;
	char				*comment;
	header_t			*header;
	char				*bytecode_header;
	unsigned int		exec_code_size;
}						t_asm_content;

/* asm_content.c */
t_asm_content		*init_content(char ad_flag);

/* assemble.c */
void				assemble(char *filename, t_asm_content **content);

/* assemble.c */
void				disassemble(char *filename, t_asm_content **content);

/* buffer.c */
void				clear_buff(char **buff);
char				**create_buff(char **line, t_asm_content **content);

/* error.c */
void				error(void);

/* filename.c */
int					file(const char *filename, t_asm_content **content);

/* helper.c - потом удалить */
void				what_are_strings(t_strings *rows);

/* title.c */
int					skip_simple_comment_emptyline(char **line);
int					check_name_or_comment(char **buff, t_asm_content **content);

/* tokenizing.c */
void				tokenizing(char **line, t_strings **row, t_asm_content **content);

/* string.c */
void    			add_string(t_token **tokens, t_strings **row);

/* in_bytecode.c */
void    			in_bytecode(t_asm_content **content);

#endif
