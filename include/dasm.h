/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:52:05 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/02/16 15:08:34 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DASM_H
# define DASM_H

# include "libft.h"

# define MAGIC_NUMBER_SIZE 4
# define NULL_SIZE 4
# define CHMP_CODE_VAR_SIZE 4
# define NAME_CMD_LEN 5
# define COMMENT_CMD_LEN 8
# define SPACE_LEN 1
# define D_QUOTE_LEN 1
# define SLASH_N_LEN 1
# define ARGS_TYPES_COUNT 3
# define BUFF_SIZE_FOR_DIS 4096
# define OP_TAB_SIZE 17
// # define BUFF_SIZE_FOR_DIS NAME_CMD_LEN + PROG_NAME_LENGTH + COMMENT_CMD_LEN +\
// 		COMMENT_LENGTH + 4 * D_QUOTE_LEN + 2 * SPACE_LEN + 3 * SLASH_N_LEN  +\
// 		CHAMP_MAX_SIZE + 1

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

#endif
