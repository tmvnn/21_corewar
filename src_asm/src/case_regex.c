# include "asm.h"

char	*create_pattern_first(t_asm_content *content)
{
	char	*first_case;
	char	*label;
	char	*dir;
	char	*dir_label;
	int		length;

	label = create_label_first_stage(content);
	dir = create_dir(content);
	dir_label = create_dir_label(content);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(QUESTION) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(FIRST_CASE) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(POINT) + 
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(first_case = ft_strnew(length)))
		error(content);
	ft_strcat(first_case, CIRCUMFLEXUS);
	ft_strcat(first_case, SPACE_OR_TAB);
	ft_strcat(first_case, MULTIPLIER);
	ft_strcat(first_case, ROUND_BRACKET_OPEN);
	ft_strcat(first_case, label);
	ft_strcat(first_case, ROUND_BRACKET_CLOSE);
	ft_strcat(first_case, QUESTION);
	ft_strcat(first_case, SPACE_OR_TAB);
	ft_strcat(first_case, MULTIPLIER);
	ft_strcat(first_case, FIRST_CASE);
	ft_strcat(first_case, ROUND_BRACKET_OPEN);
	ft_strcat(first_case, dir);
	ft_strcat(first_case, PIPELINE);
	ft_strcat(first_case, dir_label);
	ft_strcat(first_case, ROUND_BRACKET_CLOSE);
	ft_strcat(first_case, POINT);
	ft_strcat(first_case, MULTIPLIER);
	ft_strcat(first_case, DOLLAR);
	ft_strdel(&label);
	ft_strdel(&dir);
	ft_strdel(&dir_label);
	return (first_case);
}

char	*create_pattern_second(t_asm_content *content)
{
	char	*second_case;
	char	*label;
	int		length;
	
	label = create_label_first_stage(content);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(label) + 
	ft_strlen(POINT) + ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(second_case = ft_strnew(length)))
		error(content);
	ft_strcat(second_case, CIRCUMFLEXUS);
	ft_strcat(second_case, SPACE_OR_TAB);
	ft_strcat(second_case, MULTIPLIER);
	ft_strcat(second_case, label);
	ft_strcat(second_case, POINT);
	ft_strcat(second_case, MULTIPLIER);
	ft_strcat(second_case, DOLLAR);
	ft_strdel(&label);
	return (second_case);
}

char	*create_pattern_third(t_asm_content *content)
{
	char	*pattern_third;
	char    *alt_comment_char;
	char	*comment_char;
	char    *reg;
	char    *dir;
	char    *dir_label;
	char    *indir;
	char    *indir_label;
	char    *label;
	char	*separator;
	int		length;

	reg = create_reg(content);
	dir = create_dir(content);
	dir_label = create_dir_label(content);
	indir = create_indir(content);
	indir_label = create_indir_label(content);
	label = create_label_first_stage(content);
	separator = screen(SEPARATOR_CHAR, content);
	alt_comment_char = screen(ALT_COMMENT_CHAR, content);
	comment_char = screen(COMMENT_CHAR, content);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(QUESTION) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(INSTRACTION_FIRST) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(INSTRACTION_SECOND) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(indir) + 
	ft_strlen(PIPELINE) + ft_strlen(indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(reg) + 
	ft_strlen(PIPELINE) + ft_strlen(ST_NAME) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(reg) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(reg) + 
	ft_strlen(PIPELINE) + ft_strlen(indir) + 
	ft_strlen(PIPELINE) + ft_strlen(indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(INSTRACTION_THIRD) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(reg) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(reg) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(reg) + 
	ft_strlen(PIPELINE) + ft_strlen(INSTRACTION_FOURTH) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + 
	ft_strlen(indir) + ft_strlen(PIPELINE) + 
	ft_strlen(indir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(PIPELINE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(dir) + ft_strlen(PIPELINE) + 
	ft_strlen(dir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(reg) + 
	ft_strlen(PIPELINE) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(PIPELINE) + ft_strlen(indir) + 
	ft_strlen(PIPELINE) + ft_strlen(indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + ft_strlen(INSTRACTION_FIFTH) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + 
	ft_strlen(indir) + ft_strlen(PIPELINE) + 
	ft_strlen(indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + ft_strlen(STI_NAME) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(reg) + ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + 
	ft_strlen(dir) + ft_strlen(PIPELINE) + 
	ft_strlen(dir_label) + ft_strlen(PIPELINE) + 
	ft_strlen(indir) + ft_strlen(PIPELINE) + 
	ft_strlen(indir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(reg) + ft_strlen(PIPELINE) + ft_strlen(dir) + 
	ft_strlen(PIPELINE) + ft_strlen(dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(AFF_NAME) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(reg) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(QUESTION) +  
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(comment_char) + 
	ft_strlen(alt_comment_char) + ft_strlen(SQUARE_BRACKET_CLOSE) + 
	ft_strlen(POINT) + ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(pattern_third = ft_strnew(length)))
		error(content);
	ft_strcat(pattern_third, CIRCUMFLEXUS);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, QUESTION);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, INSTRACTION_FIRST);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_SECOND);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, ST_NAME);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_THIRD);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_FOURTH);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_FIFTH);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, STI_NAME);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, AFF_NAME);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, reg);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, QUESTION);
	ft_strcat(pattern_third, SQUARE_BRACKET_OPEN);
	ft_strcat(pattern_third, comment_char);
	ft_strcat(pattern_third, alt_comment_char);
	ft_strcat(pattern_third, SQUARE_BRACKET_CLOSE);
	ft_strcat(pattern_third, POINT);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, DOLLAR);
	ft_strdel(&reg);
	ft_strdel(&dir);
	ft_strdel(&dir_label);
	ft_strdel(&indir);
	ft_strdel(&indir_label);
	ft_strdel(&label);
	ft_strdel(&separator);
	ft_strdel(&alt_comment_char);
	ft_strdel(&comment_char);
	return (pattern_third);
}