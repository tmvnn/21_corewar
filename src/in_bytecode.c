/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_bytecode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:07:20 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/02 21:13:49 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void create_header(char *str, header_t **header, int size) {
	header_t    *copy;
	char		*pointer;

	copy = *header;
	if (size == PROG_NAME_LENGTH + 1)
		pointer = copy->prog_name;
	else
		pointer = copy->comment;
	if (!str || ft_strlen(str) > size)
		error();
	while (pointer && size--) {
		// тут должен быть перевод двоичного числа в шестнадцатеричное с помощью
		// itoa_base и еще одной вспомогательной функции
	}
}

void        in_bytecode(t_asm_content **content) {
	create_header((*content)->name, &(*content)->header, PROG_NAME_LENGTH + 1);
	create_header((*content)->comment, &(*content)->header, COMMENT_LENGTH + 1);
}
