/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:12:24 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/16 20:42:13 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// static int	check_slashn_end(const char *filename, t_asm_content **content)
// {
// 	int		fd;
	
// 	fd = 0;
// 	if (!(fd = open(filename, O_RDONLY)))
// 		error(*content);
// 	while () {
// 	lseek(fd, -1, SEEK_END);
// 	read();
// 	}
// }

// static int	count_slashn()
// {
// 	char	ch;

// 	int		pos;
// 	int		i;

// 	pos = 0;
// 	i = 0;
// 	while ((read(fd, &ch, 1)) > 0)
// 	{
// 		if (ch == '\n')
// 			pos = i;
// 		i++;
// 	}
// 	return (pos);
// }

int	file(const char *filename, t_asm_content **content)
{
	int		filename_len;
	char	*filename_dot_cor;

	filename_len = 0;
	if (!filename || (filename_len = ft_strlen(filename)) == 0 ||
	ft_strcmp((filename + filename_len - EXP_ASM_LEN), EXP_ASM))
		error(*content);
	*content = init_content();
	filename_dot_cor = (char *)ft_memalloc((filename_len + 3) * sizeof(char));
	ft_strcat(ft_memcpy(filename_dot_cor, filename, filename_len - 2), EXP_COR);
	check_slashn_end(filename, content);
	if (!((*content)->fd_dst = open(filename_dot_cor, O_CREAT | O_RDWR, 0644)))
		error(*content);
	if (((*content)->fd_src = open(filename, O_RDONLY)) == -1)
		error(*content);
	ft_strdel(&filename_dot_cor);
	return (1);
}
