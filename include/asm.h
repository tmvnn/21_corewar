/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:21:29 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/14 15:00:38 by timuryakubo      ###   ########.fr       */
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
# define ARGS_TYPES_COUNT 3

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

typedef struct			s_op
{	
	char				*op_name;
	u_int8_t			args_num;
	u_int8_t			args_types[3];
	u_int8_t			op_code;
	int					op_cycles;
	char				*op_comment;
	t_bool				args_types_code;
	u_int8_t			t_dir_size;
	u_int8_t			oname_size;
}						t_op;

static t_op    op_tab[17] =
{
	{0, 0, {0}, 0, 0, 0, 0, 0, 0},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 4, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 4, 2},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 4, 2},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 4, 3},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 4, 3},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 4, 3},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 4, 2},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 4, 3},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 2, 4},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 2, 3},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 2, 3},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 2, 4},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 4, 3},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 2, 4},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 2, 5},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 4, 3}
};

/* asm_content.c */
t_asm_content		*init_content(char ad_flag);

/* assemble.c */
void				assemble(char *filename, t_asm_content **content);

/* disassemble.c */
void				disassemble(char *filename, t_asm_content **content);

/* parse_chmp_exec_code.c */
void				parse_chmp_exec_code(t_asm_content **content);

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
