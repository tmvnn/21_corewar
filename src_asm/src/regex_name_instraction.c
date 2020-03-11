#include "asm.h"

char	*create_instraction_first_stage(t_asm_content *content)
{
	char	*instraction;
	int		length;

	length = ft_strlen(LIVE_NAME) + 
	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + 
	ft_strlen(LD_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + 
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(ST_NAME) + ft_strlen(DOLLAR) + 
	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(ADD_NAME) + 
	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + 
	ft_strlen(SUB_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + 
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(AND_NAME) + ft_strlen(DOLLAR) + 
	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(OR_NAME) + 
	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + 
	ft_strlen(XOR_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + 
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(ZJMP_NAME) + ft_strlen(DOLLAR) + 
	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(LDI_NAME) + 
	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + 
	ft_strlen(STI_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + 
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(FORK_NAME) + ft_strlen(DOLLAR) + 
	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(LLD_NAME) + 
	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + 
	ft_strlen(LLDI_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + 
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(LFORK_NAME) + ft_strlen(DOLLAR) + 
	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(AFF_NAME);
	if (!(instraction = ft_strnew(length)))
		error(content);
	ft_strcat(instraction, LIVE_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, LD_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, ST_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, ADD_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, SUB_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, AND_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, OR_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, XOR_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, ZJMP_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, LDI_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, STI_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, FORK_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, LLD_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, LLDI_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, LFORK_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, AFF_NAME);
	return (instraction);
}

char	*create_name_champ(t_asm_content *content)
{
	char	*name;
	char    *name_cmd_string;
	char    *alt_comment_char;
	char	*comment_char;
	int		length;

	name_cmd_string = str_screening(NAME_CMD_STRING, content);
	alt_comment_char = screen(ALT_COMMENT_CHAR, content);
	comment_char = screen(COMMENT_CHAR, content);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + 
	ft_strlen(name_cmd_string) + 
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
	if (!(name = ft_strnew(length)))
		error(content);
	ft_strcat(name, CIRCUMFLEXUS);
	ft_strcat(name, SPACE_OR_TAB);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, name_cmd_string);
	ft_strcat(name, SPACE_OR_TAB);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, QUOTATION_MARK);
	ft_strcat(name, SQUARE_BRACKET_OPEN);
	ft_strcat(name, CIRCUMFLEXUS);
	ft_strcat(name, QUOTATION_MARK);
	ft_strcat(name, SQUARE_BRACKET_CLOSE);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, QUOTATION_MARK);
	ft_strcat(name, SPACE_OR_TAB);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, ROUND_BRACKET_OPEN);
	ft_strcat(name, SQUARE_BRACKET_OPEN);
	ft_strcat(name, alt_comment_char);
	ft_strcat(name, comment_char);
	ft_strcat(name, SQUARE_BRACKET_CLOSE);
	ft_strcat(name, POINT);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, ROUND_BRACKET_CLOSE);
	ft_strcat(name, QUESTION);
	ft_strcat(name, DOLLAR);
	ft_strdel(&alt_comment_char);
	ft_strdel(&comment_char);
	ft_strdel(&name_cmd_string);
	return (name);
}

char	*create_pattern_name_or_comment_champs(t_asm_content *content)
{
	char	*pattern_name_or_comment;
	char	*name_cmd_string;
	char	*comment_cmd_string;
	int		length;

	name_cmd_string = str_screening(NAME_CMD_STRING, content);
	comment_cmd_string = str_screening(COMMENT_CMD_STRING, content);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(name_cmd_string) + 
	ft_strlen(PIPELINE) + 
	ft_strlen(comment_cmd_string) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + 
	ft_strlen(QUOTATION_MARK) + ft_strlen(POINT) + 
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(pattern_name_or_comment = ft_strnew(length)))
		error(content);
	ft_strcat(pattern_name_or_comment, CIRCUMFLEXUS);
	ft_strcat(pattern_name_or_comment, SPACE_OR_TAB);
	ft_strcat(pattern_name_or_comment, MULTIPLIER);
	ft_strcat(pattern_name_or_comment, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_name_or_comment, name_cmd_string);
	ft_strcat(pattern_name_or_comment, PIPELINE);
	ft_strcat(pattern_name_or_comment, comment_cmd_string);
	ft_strcat(pattern_name_or_comment, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_name_or_comment, SPACE_OR_TAB);
	ft_strcat(pattern_name_or_comment, MULTIPLIER);
	ft_strcat(pattern_name_or_comment, QUOTATION_MARK);
	ft_strcat(pattern_name_or_comment, POINT);
	ft_strcat(pattern_name_or_comment, MULTIPLIER);
	ft_strcat(pattern_name_or_comment, DOLLAR);
	ft_strdel(&name_cmd_string);
	ft_strdel(&comment_cmd_string);
	return (pattern_name_or_comment);
}
