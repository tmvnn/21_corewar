#include "asm.h"

char	*create_start_and_finish_str(char *str, t_asm_content *content)
{
	char	*result;
	int		length;

	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(str) + 
	ft_strlen(DOLLAR);
	if (!(result = ft_strnew(length)))
		error(content);
	ft_strcat(result, CIRCUMFLEXUS);
	ft_strcat(result, str);
	ft_strcat(result, DOLLAR);
	return (result);
}

char	*create_label_result(t_asm_content *content)
{
	char	*label;
	char	*result_label;

	label = create_label_first_stage(content);
	result_label = create_start_and_finish_str(label, content);
	return (result_label);
}

char	*create_t_reg(t_asm_content *content)
{
	char	*reg;
	char	*t_reg;
	
	reg = create_reg(content);
	t_reg = create_start_and_finish_str(reg, content);
	ft_strdel(&reg);
	return (t_reg);
}

char    *create_t_dir(t_asm_content *content)
{
	char	*t_dir;
	char	*dir;
	char	*dir_label;
	int		length;


	dir = create_start_and_finish_str(create_dir(content), content);
	dir_label = create_start_and_finish_str(create_dir_label(content), content);
	length = ft_strlen(dir) + ft_strlen(PIPELINE) + ft_strlen(dir_label);
	if (!(t_dir = ft_strnew(length)))
		error(content);
	ft_strcat(t_dir, dir);
	ft_strcat(t_dir, PIPELINE);
	ft_strcat(t_dir, dir_label);
	ft_strdel(&dir);
	ft_strdel(&dir_label);
	return (t_dir);
}

char    *create_t_ind(t_asm_content *content)
{
	char    *t_ind;
	char	*indir;
	char	*indir_label;
	char	*indir_start;
	char	*indir_label_start;
	int		length;

	indir_start = create_indir(content);
	indir = create_start_and_finish_str(indir_start, content);
	indir_label_start = create_indir_label(content);
	indir_label = create_start_and_finish_str(indir_label_start, content);
	length = ft_strlen(indir) + ft_strlen(PIPELINE) + ft_strlen(indir_label);
	if (!(t_ind = ft_strnew(length)))
		error(content);
	ft_strcat(t_ind, indir);
	ft_strcat(t_ind, PIPELINE);
	ft_strcat(t_ind, indir_label);
	ft_strdel(&indir);
	ft_strdel(&indir_label);
	ft_strdel(&indir_label_start);
	ft_strdel(&indir_start);
	return (t_ind);
}

char	*create_instraction(t_asm_content *content)
{
	char	*instraction_first_stage;
	char	*result;

	instraction_first_stage = create_instraction_first_stage(content);
	result = create_start_and_finish_str(instraction_first_stage, content);
	ft_strdel(&instraction_first_stage);
	return (result);
}

void    create_regex(t_asm_content *content)
{
	regex_array[PATTERN_T_REG] = create_t_reg(content);
	regex_array[PATTERN_T_DIR] = create_t_dir(content);
	regex_array[PATTERN_T_IND] = create_t_ind(content);
	regex_array[INSTRACTION] = create_instraction(content);
	regex_array[LABEL] = create_label_result(content);
	regex_array[REGISTER] = create_t_reg(content);
	regex_array[DIRECT_LABEL] = create_dir_label_result(content);
	regex_array[DIRECT] = create_dir_result(content);
	regex_array[INDIRECT_LABEL] = create_indir_label_result(content);
	regex_array[INDIRECT] = create_indir_result(content);
	regex_array[PATTERN_NAME_CHAMPS] = create_name_champ(content);
	regex_array[PATTERN_COMMENT_CHAMPS] = create_comment_champ(content);
	regex_array[PATTERN_COMMENT] = create_comment(content);
	regex_array[PATTERN_SPACE_OR_EMPTY_LINE] = create_pattern_space_or_empty_line(content);
	regex_array[PATTERN] = create_pattern(content);
	regex_array[PATTERN_NAME_OR_COMMENT_CHAMPS] = create_pattern_name_or_comment_champs(content);
	regex_array[PATTERN_HELP_VALIDATION_FIRST_CASE] = create_pattern_first(content);
	regex_array[PATTERN_HELP_VALIDATION_SECOND_CASE] = create_pattern_second(content);
	regex_array[PATTERN_HELP_VALIDATION_THIRD_CASE] = create_pattern_third(content);
}