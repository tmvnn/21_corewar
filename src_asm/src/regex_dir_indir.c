#include "asm.h"

char	*create_reg(t_asm_content *content)
{
	char	*t_reg;
	int		length;

	length = ft_strlen(REG_SYMBOL) + ft_strlen(NUMBERS) + 
	ft_strlen(CURLY_BRACKET_OPEN) + ft_strlen(ONE) + 
	ft_strlen(COMMA) + ft_strlen(TWO) + 
	ft_strlen(CURLY_BRACKET_CLOSE);
	if (!(t_reg = ft_strnew(length)))
		error(content);
	ft_strcat(t_reg, REG_SYMBOL);
	ft_strcat(t_reg, NUMBERS);
	ft_strcat(t_reg, CURLY_BRACKET_OPEN);
	ft_strcat(t_reg, ONE);
	ft_strcat(t_reg, COMMA);
	ft_strcat(t_reg, TWO);
	ft_strcat(t_reg, CURLY_BRACKET_CLOSE);
	return (t_reg);
}

char	*create_label_first_stage(t_asm_content *content)
{
	char	*label;
	char	*label_char;
	int		length;

	label_char = screening(LABEL_CHAR, content);
	length = ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(LABEL_CHARS) + 
	ft_strlen(SQUARE_BRACKET_CLOSE) + ft_strlen(PLUS) + 
	ft_strlen(label_char);
	if (!(label = ft_strnew(length)))
		error(content);
	ft_strcat(label, SQUARE_BRACKET_OPEN);
	ft_strcat(label, LABEL_CHARS);
	ft_strcat(label, SQUARE_BRACKET_CLOSE);
	ft_strcat(label, PLUS);
	ft_strcat(label, label_char);
	ft_strdel(&label_char);
	return (label);
}

char	*create_dir_label(t_asm_content *content)
{
	char	*dir_label;
	char    *direct_char;
	char    *label_char;
	int		length;

	direct_char = screening(DIRECT_CHAR, content);
	label_char = screening(LABEL_CHAR, content);
	length = ft_strlen(direct_char) + ft_strlen(label_char) + 
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(LABEL_CHARS) + 
	ft_strlen(SQUARE_BRACKET_CLOSE) + ft_strlen(PLUS);
	if (!(dir_label = ft_strnew(length)))
		error(content);
	ft_strcat(dir_label, direct_char);
	ft_strcat(dir_label, label_char);
	ft_strcat(dir_label, SQUARE_BRACKET_OPEN);
	ft_strcat(dir_label, LABEL_CHARS);
	ft_strcat(dir_label, SQUARE_BRACKET_CLOSE);
	ft_strcat(dir_label, PLUS);
	ft_strdel(&direct_char);
	ft_strdel(&label_char);
	return (dir_label);
}

char	*create_dir(t_asm_content *content)
{
	char	*dir;
	char    *direct_char;
	int		length;

	direct_char = screening(DIRECT_CHAR, content);
	length = ft_strlen(direct_char) + ft_strlen(MINUS) + 
	ft_strlen(QUESTION) + 
	ft_strlen(NUMBERS) + ft_strlen(PLUS);
	if (!(dir = ft_strnew(length)))
		error(content);
	ft_strcat(dir, direct_char);
	ft_strcat(dir, MINUS);
	ft_strcat(dir, QUESTION);
	ft_strcat(dir, NUMBERS);
	ft_strcat(dir, PLUS);
	ft_strdel(&direct_char);
	return (dir);
}

char	*create_indir_label(t_asm_content *content)
{
	char	*indir_label;
	char    *label_char;
	int		length;

	label_char = screening(LABEL_CHAR, content);
	length = ft_strlen(label_char) + ft_strlen(SQUARE_BRACKET_OPEN) + 
	ft_strlen(LABEL_CHARS) + ft_strlen(SQUARE_BRACKET_CLOSE) + 
	ft_strlen(PLUS);
	if (!(indir_label = ft_strnew(length)))
		error(content);
	ft_memset(indir_label, '\0', length + 1);
	ft_strcat(indir_label, label_char);
	ft_strcat(indir_label, SQUARE_BRACKET_OPEN);
	ft_strcat(indir_label, LABEL_CHARS);
	ft_strcat(indir_label, SQUARE_BRACKET_CLOSE);
	ft_strcat(indir_label, PLUS);
	ft_strdel(&label_char);
	return (indir_label);
}

char	*create_indir(t_asm_content *content)
{
	char	*indir;
	int		length;

	length = ft_strlen(MINUS) + ft_strlen(QUESTION) + 
	ft_strlen(NUMBERS) + ft_strlen(PLUS);
	if (!(indir = ft_strnew(length)))
		error(content);
	ft_strcat(indir, MINUS);
	ft_strcat(indir, QUESTION);
	ft_strcat(indir, NUMBERS);
	ft_strcat(indir, PLUS);
	return (indir);
}