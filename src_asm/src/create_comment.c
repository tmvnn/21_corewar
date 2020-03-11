#include "asm.h"

char	*create_comment_champ(t_asm_content *content)
{
	char	*comment;
	char    *comment_cmd_string;
	char    *alt_comment_char;
	char	*comment_char;
	int		length;

	comment_cmd_string = str_screening(COMMENT_CMD_STRING, content);
	alt_comment_char = screen(ALT_COMMENT_CHAR, content);
	comment_char = screen(COMMENT_CHAR, content);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(comment_cmd_string) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(QUOTATION_MARK) + ft_strlen(SQUARE_BRACKET_OPEN) + 
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(QUOTATION_MARK) + 
	ft_strlen(SQUARE_BRACKET_CLOSE) + ft_strlen(MULTIPLIER) + 
	ft_strlen(QUOTATION_MARK) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(alt_comment_char) + 
	ft_strlen(comment_char) + ft_strlen(SQUARE_BRACKET_CLOSE) + 
	ft_strlen(POINT) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(QUESTION) + ft_strlen(DOLLAR);
	if (!(comment = ft_strnew(length)))
		error(content);
	ft_strcat(comment, CIRCUMFLEXUS);
	ft_strcat(comment, SPACE_OR_TAB);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, comment_cmd_string);
	ft_strcat(comment, SPACE_OR_TAB);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, QUOTATION_MARK);
	ft_strcat(comment, SQUARE_BRACKET_OPEN);
	ft_strcat(comment, CIRCUMFLEXUS);
	ft_strcat(comment, QUOTATION_MARK);
	ft_strcat(comment, SQUARE_BRACKET_CLOSE);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, QUOTATION_MARK);
	ft_strcat(comment, SPACE_OR_TAB);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, ROUND_BRACKET_OPEN);
	ft_strcat(comment, SQUARE_BRACKET_OPEN);
	ft_strcat(comment, alt_comment_char);
	ft_strcat(comment, comment_char);
	ft_strcat(comment, SQUARE_BRACKET_CLOSE);
	ft_strcat(comment, POINT);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, ROUND_BRACKET_CLOSE);
	ft_strcat(comment, QUESTION);
	ft_strcat(comment, DOLLAR);
	ft_strdel(&comment_cmd_string);
	ft_strdel(&alt_comment_char);
	ft_strdel(&comment_char);
	return (comment);
}

char	*create_comment(t_asm_content *content)
{
	char	*comment;
	char    *alt_comment_char;
	char	*comment_char;
	int		length;

	alt_comment_char = screen(ALT_COMMENT_CHAR, content);
	comment_char = screen(COMMENT_CHAR, content);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(SQUARE_BRACKET_OPEN) + 
    ft_strlen(alt_comment_char) + ft_strlen(comment_char) + 
	ft_strlen(SQUARE_BRACKET_CLOSE) + ft_strlen(POINT) + 
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(comment = ft_strnew(length)))
		error(content);
	ft_strcat(comment, CIRCUMFLEXUS);
	ft_strcat(comment, SPACE_OR_TAB);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, SQUARE_BRACKET_OPEN);
	ft_strcat(comment, alt_comment_char);
	ft_strcat(comment, comment_char);
	ft_strcat(comment, SQUARE_BRACKET_CLOSE);
	ft_strcat(comment, POINT);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, DOLLAR);
	ft_strdel(&alt_comment_char);
	ft_strdel(&comment_char);
	return (comment);
}

char	*create_pattern_space_or_empty_line(t_asm_content *content)
{
	char	*space_or_empty_line;
	int		length;

	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(space_or_empty_line = ft_strnew(length)))
		error(content);
	ft_strcat(space_or_empty_line, CIRCUMFLEXUS);
	ft_strcat(space_or_empty_line, SPACE_OR_TAB);
	ft_strcat(space_or_empty_line, MULTIPLIER);
	ft_strcat(space_or_empty_line, DOLLAR);
	return (space_or_empty_line);
}