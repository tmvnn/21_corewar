#include "asm.h"

char	*create_pattern(t_asm_content *content)
{
	char	*pattern;
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
	ft_strlen(AFF_NAME) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(reg) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(QUESTION) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(comment_char) + 
	ft_strlen(alt_comment_char) + ft_strlen(SQUARE_BRACKET_CLOSE) + 
	ft_strlen(POINT) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(QUESTION) + 
	ft_strlen(DOLLAR);
	if (!(pattern = ft_strnew(length)))
		error(content);
	ft_strcat(pattern, CIRCUMFLEXUS);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, QUESTION);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, INSTRACTION_FIRST);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_SECOND);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, ST_NAME);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_THIRD);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_FOURTH);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_FIFTH);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, STI_NAME);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, AFF_NAME);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, reg);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, QUESTION);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SQUARE_BRACKET_OPEN);
	ft_strcat(pattern, comment_char);
	ft_strcat(pattern, alt_comment_char);
	ft_strcat(pattern, SQUARE_BRACKET_CLOSE);
	ft_strcat(pattern, POINT);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, QUESTION);
	ft_strcat(pattern, DOLLAR);
	ft_strdel(&reg);
	ft_strdel(&dir);
	ft_strdel(&dir_label);
	ft_strdel(&indir);
	ft_strdel(&indir_label);
	ft_strdel(&label);
	ft_strdel(&separator);
	ft_strdel(&alt_comment_char);
	ft_strdel(&comment_char);
	return (pattern);
}