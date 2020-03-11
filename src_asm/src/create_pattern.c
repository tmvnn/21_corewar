#include "asm.h"

void	init_create_pattern(t_norminette *struct_norme, t_asm_content *content)
{
	struct_norme->reg = create_reg(content);
	struct_norme->dir = create_dir(content);
	struct_norme->dir_label = create_dir_label(content);
	struct_norme->indir = create_indir(content);
	struct_norme->indir_label = create_indir_label(content);
	struct_norme->label = create_label_first_stage(content);
	struct_norme->separator = screen(SEPARATOR_CHAR, content);
	struct_norme->alt_comment_char = screen(ALT_COMMENT_CHAR, content);
	struct_norme->comment_char = screen(COMMENT_CHAR, content);
}

int		create_pattern_length_first(t_norminette *struct_norme)
{
	int length;

	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(QUESTION) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(INSTRACTION_FIRST) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->dir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(INSTRACTION_SECOND) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->dir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->indir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->reg);
	return (length);
}

int		create_pattern_length_second(t_norminette *struct_norme)
{
	int length;
	
	length = ft_strlen(PIPELINE) + ft_strlen(ST_NAME) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(struct_norme->reg) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->reg) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->indir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(INSTRACTION_THIRD) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(struct_norme->reg) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->reg) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->reg) + 
	ft_strlen(PIPELINE) + ft_strlen(INSTRACTION_FOURTH) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme->indir) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme->indir_label) + ft_strlen(ROUND_BRACKET_CLOSE);
	return (length);
}

char	*create_pattern(t_asm_content *content)
{
	char			*pattern;
	int				length;
	t_norminette	struct_norme;

	init_create_pattern(&struct_norme, content);
	length = create_pattern_length_first(&struct_norme) + 
	
	ft_strlen(PIPELINE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(struct_norme.dir) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme.dir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme.separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme.reg) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme.dir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme.dir_label) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme.indir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme.indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme.separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(struct_norme.reg) + ft_strlen(PIPELINE) + ft_strlen(INSTRACTION_FIFTH) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(struct_norme.reg) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme.indir) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme.indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme.dir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme.dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(struct_norme.separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(struct_norme.reg) + ft_strlen(PIPELINE) + ft_strlen(struct_norme.dir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme.dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme.separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(struct_norme.reg) + ft_strlen(PIPELINE) + ft_strlen(STI_NAME) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(struct_norme.reg) + ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(struct_norme.separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(struct_norme.reg) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme.dir) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme.dir_label) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme.indir) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme.indir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(struct_norme.separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(struct_norme.reg) + ft_strlen(PIPELINE) + ft_strlen(struct_norme.dir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme.dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(AFF_NAME) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(struct_norme.reg) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(QUESTION) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(struct_norme.comment_char) + 
	ft_strlen(struct_norme.alt_comment_char) + ft_strlen(SQUARE_BRACKET_CLOSE) + 
	ft_strlen(POINT) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(QUESTION) + 
	ft_strlen(DOLLAR);
	if (!(pattern = ft_strnew(length)))
		error(content);
	ft_strcat(pattern, CIRCUMFLEXUS);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme.label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, QUESTION);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, INSTRACTION_FIRST);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme.dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_SECOND);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme.dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme.indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, ST_NAME);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_THIRD);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_FOURTH);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme.dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.dir_label);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_FIFTH);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme.dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, STI_NAME);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.dir_label);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme.separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme.dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, AFF_NAME);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, struct_norme.reg);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, QUESTION);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SQUARE_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme.comment_char);
	ft_strcat(pattern, struct_norme.alt_comment_char);
	ft_strcat(pattern, SQUARE_BRACKET_CLOSE);
	ft_strcat(pattern, POINT);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, QUESTION);
	ft_strcat(pattern, DOLLAR);
	ft_strdel(&struct_norme.reg);
	ft_strdel(&struct_norme.dir);
	ft_strdel(&struct_norme.dir_label);
	ft_strdel(&struct_norme.indir);
	ft_strdel(&struct_norme.indir_label);
	ft_strdel(&struct_norme.label);
	ft_strdel(&struct_norme.separator);
	ft_strdel(&struct_norme.alt_comment_char);
	ft_strdel(&struct_norme.comment_char);
	return (pattern);
}