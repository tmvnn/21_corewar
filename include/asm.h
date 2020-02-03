/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:21:29 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/26 15:31:46 by idunaver         ###   ########.fr       */
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
# define PATTERN_NAME_CHAMPS "^[ 	]*[.]name[ 	]*\".{0,128}\"[ 	]*([#;].*)?$"
# define PATTERN_NAME_COMMENT "^[ 	]*[.]comment[ 	]\".{0,255}\"[ 	]*([#;].*)?$"
# define PATTERN_COMMENT "^ *[#;].*$"
# define PATTERN_SPACE_OR_EMPTY_LINE "^[ 	]*$"
# define PATTERN "^[ 	]*([a-z0-9_]+:)?[ 	]*((live|zjmp|fork|lfork)[ 	]*(%-?0*[0-9]+|%:[0-9a-z_]+)|(ld|lld)[ 	]*(%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+)[ 	]*,[ 	]*r[0-9]{1,2}|st[ 	]*r[0-9]{1,2}[ 	]*,[ 	]*(r[0-9]{1,2}|-?[0-9]+|:[0-9a-z_]+)|(add|sub)[ 	]*r[0-9]{1,2}[ 	]*,[ 	]*r[0-9]{1,2}[ 	]*,[ 	]*r[0-9]{1,2}|(and|or|xor)[ 	]*(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+)[ 	]*,[ 	]*(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+)[ 	]*,[ 	]*r[0-9]{1,2}|(ldi|lldi)[ 	]*(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+)[ 	]*,[ 	]*(r[0-9]{1,2}|%-?0*[0-9]+$|^%:[0-9a-z_]+)[ 	]*,[ 	]*r[0-9]{1,2}|sti[ 	]*r[0-9]{1,2}[ 	]*,[ 	]*(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+|-?[0-9]+|:[0-9a-z_]+)[ 	]*,[ 	]*(r[0-9]{1,2}|%-?0*[0-9]+|%:[0-9a-z_]+))?[ 	]*([#;].*)?$"


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

# define LABEL_NAME "LABEL"
# define INSTRACTION_NAME "INSTRACTION"
# define REGISTER_NAME "REGISTER"
# define DIRECT_LABEL_NAME "DIRECT_LABEL"
# define DIRECT_NAME "DIRECT"

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
	int					flag_name;
	int					flag_comment;
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

/* interpretation.c */
void				interpretation(t_token *tokens);
int					parse(char *str, char *pattern);

#endif
