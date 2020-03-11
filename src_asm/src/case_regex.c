# include "asm.h"

int		create_pattern_first_length(t_norminette *struct_norme)
{
	int				length;

	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(QUESTION) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(FIRST_CASE) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->dir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(POINT) + 
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	return (length);
}

void	create_pattern_first_strcat(t_norminette *struct_norme, char *first_case)
{
	ft_strcat(first_case, CIRCUMFLEXUS);
	ft_strcat(first_case, SPACE_OR_TAB);
	ft_strcat(first_case, MULTIPLIER);
	ft_strcat(first_case, ROUND_BRACKET_OPEN);
	ft_strcat(first_case, struct_norme->label);
	ft_strcat(first_case, ROUND_BRACKET_CLOSE);
	ft_strcat(first_case, QUESTION);
	ft_strcat(first_case, SPACE_OR_TAB);
	ft_strcat(first_case, MULTIPLIER);
	ft_strcat(first_case, FIRST_CASE);
	ft_strcat(first_case, ROUND_BRACKET_OPEN);
	ft_strcat(first_case, struct_norme->dir);
	ft_strcat(first_case, PIPELINE);
	ft_strcat(first_case, struct_norme->dir_label);
	ft_strcat(first_case, ROUND_BRACKET_CLOSE);
	ft_strcat(first_case, POINT);
	ft_strcat(first_case, MULTIPLIER);
	ft_strcat(first_case, DOLLAR);
}

char	*create_pattern_first(t_asm_content *content)
{
	t_norminette	struct_norme;
	char			*first_case;

	struct_norme.label = create_label_first_stage(content);
	struct_norme.dir = create_dir(content);
	struct_norme.dir_label = create_dir_label(content);
	if (!(first_case = ft_strnew(create_pattern_first_length(&struct_norme))))
		error(content);
	create_pattern_first_strcat(&struct_norme, first_case);
	ft_strdel(&struct_norme.label);
	ft_strdel(&struct_norme.dir);
	ft_strdel(&struct_norme.dir_label);
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
	ft_strlen(POINT) + 
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
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

void	init_struct_norme_for_pattern_third(t_norminette *struct_norme, t_asm_content *content)
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

int		create_pattern_third_length_first(t_norminette *struct_norme)
{
	int				length;

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
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB);
	return (length);
}

int		create_pattern_third_length_second(t_norminette *struct_norme)
{
	int				length;

	length = ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->reg) + 
	ft_strlen(PIPELINE) + ft_strlen(ST_NAME) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + 
	ft_strlen(struct_norme->reg) + ft_strlen(SPACE_OR_TAB) +
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
	ft_strlen(PLUS) + ft_strlen(ROUND_BRACKET_OPEN);
	return (length);
}

int		create_pattern_third_length_third(t_norminette *struct_norme)
{
	int				length;

	length = ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme->indir) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme->indir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(PIPELINE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(struct_norme->dir) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme->dir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->reg) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->indir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->indir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) + 
	ft_strlen(INSTRACTION_FIFTH) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(SPACE_OR_TAB);
	return (length);
}

int		create_pattern_third_length_fourth(t_norminette *struct_norme)
{
	int				length;

	length = ft_strlen(PLUS) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme->indir) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme->indir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(PIPELINE) + ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->dir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme->dir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->separator) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) + ft_strlen(STI_NAME) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + ft_strlen(struct_norme->reg) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB);
	return (length);
}

int		create_pattern_third_length_fifth(t_norminette *struct_norme)
{
	int				length;

	length = ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme->dir) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme->dir_label) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme->indir) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme->indir_label) + ft_strlen(ROUND_BRACKET_CLOSE) + 
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) + 
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) + 
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) + 
	ft_strlen(struct_norme->dir) + 
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) + 
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) + 
	ft_strlen(AFF_NAME) + ft_strlen(SPACE_OR_TAB) + 
	ft_strlen(PLUS) + ft_strlen(struct_norme->reg) + 
	ft_strlen(ROUND_BRACKET_CLOSE) +  
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(struct_norme->comment_char) + 
	ft_strlen(struct_norme->alt_comment_char) + ft_strlen(SQUARE_BRACKET_CLOSE) + 
	ft_strlen(POINT) + ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	return (length);
}

void	pattern_third_strcat_first(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, CIRCUMFLEXUS);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, QUESTION);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, INSTRACTION_FIRST);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_SECOND);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
}

void	pattern_third_strcat_second(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, ST_NAME);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
}

void	pattern_third_strcat_third(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_THIRD);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->reg);
}

void	pattern_third_strcat_fourth(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_FOURTH);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->dir);
	ft_strcat(pattern_third, PIPELINE);
}

void	pattern_third_strcat_fifth(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, struct_norme->dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir_label);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
}

void	pattern_third_strcat_sixth(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_FIFTH);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
}

void	pattern_third_strcat_seventh(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, STI_NAME);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
}

void	pattern_third_strcat_eigth(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir_label);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir_label);
}

void	pattern_third_strcat_ninth(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, AFF_NAME);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SQUARE_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->comment_char);
	ft_strcat(pattern_third, struct_norme->alt_comment_char);
	ft_strcat(pattern_third, SQUARE_BRACKET_CLOSE);
	ft_strcat(pattern_third, POINT);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, DOLLAR);
}

void	pattern_third_strdel(t_norminette *struct_norme)
{
	ft_strdel(&struct_norme->reg);
	ft_strdel(&struct_norme->dir);
	ft_strdel(&struct_norme->dir_label);
	ft_strdel(&struct_norme->indir);
	ft_strdel(&struct_norme->indir_label);
	ft_strdel(&struct_norme->label);
	ft_strdel(&struct_norme->separator);
	ft_strdel(&struct_norme->alt_comment_char);
	ft_strdel(&struct_norme->comment_char);
}

char	*create_pattern_third(t_asm_content *content)
{
	t_norminette	struct_norme;
	char			*pattern_third;
	int				length;

	init_struct_norme_for_pattern_third(&struct_norme, content);
	length = create_pattern_third_length_first(&struct_norme) + 
	create_pattern_third_length_second(&struct_norme) + 
	create_pattern_third_length_third(&struct_norme) +
	create_pattern_third_length_fourth(&struct_norme) + 
	create_pattern_third_length_fifth(&struct_norme);
	if (!(pattern_third = ft_strnew(length)))
		error(content);
	pattern_third_strcat_first(pattern_third, &struct_norme);
	pattern_third_strcat_second(pattern_third, &struct_norme);
	pattern_third_strcat_third(pattern_third, &struct_norme);
	pattern_third_strcat_fourth(pattern_third, &struct_norme);
	pattern_third_strcat_fifth(pattern_third, &struct_norme);
	pattern_third_strcat_sixth(pattern_third, &struct_norme);
	pattern_third_strcat_seventh(pattern_third, &struct_norme);
	pattern_third_strcat_eigth(pattern_third, &struct_norme);
	pattern_third_strcat_ninth(pattern_third, &struct_norme);
	pattern_third_strdel(&struct_norme);
	return (pattern_third);
}