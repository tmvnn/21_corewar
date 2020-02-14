/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_bytecode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:07:20 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/11 22:29:03 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void convert_four_byte(t_asm_content **content, unsigned int number, int move) {
	int		size;
	char	*copy;

	size = 4;
	copy = (*content)->bytecode + move + FOURTH_BYTE;
	while (size--) {
		*copy = (uint8_t)number;
		number >>= 8;
		if (size)
			copy--;
	}
}

static void	convert_text(char **dst, char *src, size_t size) {
	char	*copy;

	copy = *dst;
	// write(1, "hello", 5);
	// if (!src)
	// 	printf("NULL\n");
	while (size--) {
		if (*src)
			*copy++ = *src++;
		else
			*copy++ = '\0';
	}
	// write(1, "hello", 5);
}

static void create_header(char *src, header_t **header, size_t size) {
	header_t	*copy;
	char		*pointer;

	copy = *header;
	if (size == PROG_NAME_LENGTH + 1)
		pointer = copy->prog_name;
	else
		pointer = copy->comment;
	// write(1, "hello", 5);
	convert_text(&pointer, src, size);
}

static void header(t_asm_content **content) {
	convert_four_byte(content, COREWAR_EXEC_MAGIC, 0);
	// write(1, "hello", 5);
	create_header((*content)->name, &(*content)->header, PROG_NAME_LENGTH + 1);
	// write(1, "hello", 5);
	ft_memcpy((*content)->bytecode + 4, (*content)->header->prog_name, PROG_NAME_LENGTH);
	// write(1, "hello", 5);
	convert_four_byte(content, (*content)->exec_code_size, 4 + 4 + PROG_NAME_LENGTH);
	create_header((*content)->comment, &(*content)->header, COMMENT_LENGTH + 1);
	ft_memcpy((*content)->bytecode + 4 + PROG_NAME_LENGTH + 4 + 4, (*content)->header->comment, COMMENT_LENGTH);
}

void        in_bytecode(t_asm_content **content) {
	header(content);
}
