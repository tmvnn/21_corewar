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

/* filename.c */
int     		valid_filename_asm(const char *filename);

/* assemble.c */
void			assemble(char *filename);

/* error.c */
void			error();

/* asm_content.c */
t_asm_content	*init_content(int fd);
int				read_content(int fd, t_asm_content *content);

/* token.c */
void			add_token(t_token **token, char *content);
void			tokenizing(char **line, t_token **token, t_asm_content **content);
void			what_are_tokens(t_token *token);

/* helper_for_works.c */


#endif