/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_bytecode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:07:20 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/09 17:00:22 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	convert_text(char **str, char *target, int size) {
	uint8_t i;
	size_t	size_target;
	char	*copy;

	i = 0;
	size_target = 0;
	ft_bzero(*str, size);
	copy = *str;
	while (size_target--) {
		*copy = (uint8_t)(*target) & 255;
		target++;
		copy++;
	}
}

static void create_header(char *str, header_t **header, size_t size) {
	header_t    *copy;
	char		*pointer;

	copy = *header;
	if (size == PROG_NAME_LENGTH + 1)
		pointer = copy->prog_name;
	else
		pointer = copy->comment;
	if (!str || ft_strlen(str) > size)
		error();
	convert_text(&pointer, str, size);
}

void        in_bytecode(t_asm_content **content) {
	create_header((*content)->name, &(*content)->header, PROG_NAME_LENGTH + 1);
	create_header((*content)->comment, &(*content)->header, COMMENT_LENGTH + 1);
	(*content)->bytecode_header = (char *)ft_memalloc(HEADER_SIZE * sizeof(char));
	write((*content)->fd_dst, (*content)->name, PROG_NAME_LENGTH);
	ft_strdel(&(*content)->bytecode_header);
	printf("\n%d\n", HEADER_SIZE);
}
