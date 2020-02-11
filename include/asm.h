/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:21:29 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/09 19:17:03 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define PATTERN_T_REG "^r[0-9]{1,2}$"
# define PATTERN_T_DIR "^%-?0*[0-9]+$|^%:[0-9a-z_]+$"
# define PATTERN_T_IND "^-?[0-9]+$|^:[0-9a-z_]+$"
# define INSTRACTION "^live$|^ld$|^st$|^add$|^sub$|^and$|^or$|^xor$|^zjmp$|^ldi$|^sti$|^fork$|^lld$|^lldi$|^lfork$|^aff$"
# define LABEL "^[0-9a-z_]+:$"
# define REGISTER "^r[0-9]{1,2}$"
# define DIRECT_LABEL "^%:[0-9a-z_]+$"
# define DIRECT "^%-?0*[0-9]+$"
# define INDIRECT_LABEL "^:[0-9a-z_]+$"
# define INDIRECT "^-?[0-9]+$"
# define PATTERN_NAME_CHAMPS "^[ 	]*[.]name[ 	]*\".*\"[ 	]*([#;].*)?$"
# define PATTERN_COMMENT_CHAMPS "^[ 	]*[.]comment[ 	]*\".*\"[ 	]*([#;].*)?$"
# define PATTERN_COMMENT "^ *[#;].*$"
# define PATTERN_SPACE_OR_EMPTY_LINE "^[ 	]*$"
# define PATTERN "^[ 	]*([a-z0-9_]+:)?[ 	]*((live|zjmp|fork|lfork)[ 	]*(%-?0*[0-9]+|%:[0-9a-z_]+)|(ld|lld)[ 	]*(%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+)[ 	]*,[ 	]*r[0-9]{1,2}|st[ 	]*r[0-9]{1,2}[ 	]*,[ 	]*(r[0-9]{1,2}|-?[0-9]+|:[0-9a-z_]+)|(add|sub)[ 	]*r[0-9]{1,2}[ 	]*,[ 	]*r[0-9]{1,2}[ 	]*,[ 	]*r[0-9]{1,2}|(and|or|xor)[ 	]*(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+)[ 	]*,[ 	]*(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+)[ 	]*,[ 	]*r[0-9]{1,2}|(ldi|lldi)[ 	]*(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+)[ 	]*,[ 	]*(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+)[ 	]*,[ 	]*r[0-9]{1,2}|sti[ 	]*r[0-9]{1,2}[ 	]*,[ 	]*(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+)[ 	]*,[ 	]*(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+))?[ 	]*([#;].*)?$"
# define PATTERN_NAME_OR_COMMENT_CHAMPS_FIRST_STAGE "^[ 	]*[.](name|comment)[ 	]*\".*$"

# include "libft.h"
# include "op.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <regex.h>

# define EXP_ASM ".s"
# define EXP_COR ".cor"
# define EXP_ASM_LEN 2
# define BUFF_S 2048
# define OCTET_SIZE 8
# define HEADER_SIZE (PROG_NAME_LENGTH + COMMENT_LENGTH + (4 * OCTET_SIZE))
# define FOURTH_BYTE 3 

# define LABEL "LABEL"

# define LIVE 0x01
# define LD 0x02
# define ST 0x03
# define ADD 0x04
# define SUB 0x05
# define AND 0x06
# define OR 0x07
# define XOR 0x08
# define ZJMP 0x09
# define LDI 0x0a
# define STI 0x0b
# define FORK 0x0c
# define LLD 0x0d
# define LLDI 0x0e
# define LFORK 0x0f
# define AFF 0x10

# define LIVE_NAME "live"
# define LD_NAME "ld"
# define ST_NAME "st"
# define ADD_NAME "add"
# define SUB_NAME "sub"
# define AND_NAME "and"
# define OR_NAME "or"
# define XOR_NAME "xor"
# define ZJMP_NAME "zjmp"
# define LDI_NAME "ldi"
# define STI_NAME "sti"
# define FORK_NAME "fork"
# define LLD_NAME "lld"
# define LLDI_NAME "lldi"
# define LFORK_NAME "lfork"
# define AFF_NAME "aff"

# define ONE_BYTE 1
# define TWO_BYTE 2
# define FOUR_BYTE 4

# define LABEL_NAME "LABEL"
# define INSTRACTION_NAME "INSTRACTION"
# define REGISTER_NAME "REGISTER"
# define DIRECT_LABEL_NAME "DIRECT_LABEL"
# define DIRECT_NAME "DIRECT"
# define INDIRECT_LABEL_NAME "INDIRECT_LABEL"
# define INDIRECT_NAME "INDIRECT"

typedef	struct			s_token
{	
	int					memory_size;
	char				*content;
	char				*type;
	struct s_token		*next;
	struct s_token		*previous;
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
	int					flag_name;
	int					flag_comment;
	int					flag_pattern;
	int					memory_code_size;
	char				*line;
	char				**buff;
	t_strings			**tokens;
	char				*name;
	char				*comment;
	header_t			*header;
	char				*bytecode;
	unsigned int		exec_code_size;
	int					asm_size;
}						t_asm_content;

/* asm_content.c */
t_asm_content		*init_content();

/* assemble.c */
void				assemble(char *filename, t_asm_content **content);

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
/* interpretation.c */
void				interpretation(t_token *tokens);
int					parse(char *str, char *pattern);

#endif
