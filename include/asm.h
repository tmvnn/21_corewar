/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:21:29 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/16 19:05:30 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include "dasm.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define ASSEMBLE 'c'
# define DISASSEMBLE 's'
# define EXP_ASM ".s"
# define EXP_COR ".cor"
# define EXP_ASM_LEN 2
# define EXP_COR_LEN 4
# define BUFF_S 2048
# define OCTET_SIZE 8
# define HEADER_SIZE (PROG_NAME_LENGTH + COMMENT_LENGTH + (4 * OCTET_SIZE))
# define FOURTH_BYTE 3

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
	char				**buff; //unused?
	char				*buf; //for disass
	int					b_pos;
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

/* disassemble.c */
void				disassemble(char *filename, t_asm_content **content);

/* parse_chmp_exec_code.c */
void				parse_chmp_exec_code(t_asm_content **content);
u_int8_t			get_num_from_1byte(t_asm_content **content, int *i);
int					get_num_from_nbyte(t_asm_content **content, int *i,
														u_int8_t t_dir_size);
void				get_args_types(t_asm_content **content, int *i,
															u_int8_t cur_op);
void				write_curr_op(t_asm_content **content, int *i,
															u_int8_t cur_op);

/* write_args.c */
void				write_reg(t_asm_content **content, u_int8_t cur_op, int *i,
																		int j);
void				write_dir(t_asm_content **content, u_int8_t cur_op, int *i,
																		int j);
void				write_ind(t_asm_content **content, u_int8_t cur_op, int *i,
																		int j);
/* parse_name_comt_cs.c */
int					file_is_binary(int fd);
int					parse_name(char *buff, int *b_pos, int fd);
int					parse_comment(char *buff, int *b_pos, int fd);
void				skip_null_bytes(t_asm_content **content);
void				parse_chmp_exec_code_size(t_asm_content **content);

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
