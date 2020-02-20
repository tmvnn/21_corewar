/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_binary_files.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:21:05 by astanton          #+#    #+#             */
/*   Updated: 2020/02/16 17:41:39 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	check_null(int fd, char *file)
{
	int				ret;
	unsigned char	buff[sizeof(unsigned int) + 1];
	unsigned int	check;

	lseek(fd, sizeof(COREWAR_EXEC_MAGIC) + PROG_NAME_LENGTH, SEEK_SET);
	ret = read(fd, buff, sizeof(unsigned int));
	buff[ret] = '\0';
	check = (unsigned int)(*buff);
	if (check)
		ft_print_error_message("Wrong binary format, NULL marker is missing \
or in the wrong place in file : ", file);
	lseek(fd, sizeof(unsigned int) + COMMENT_LENGTH, SEEK_CUR);
	ret = read(fd, buff, sizeof(unsigned int));
	check = (unsigned int)(*buff);
	if (check)
		ft_print_error_message("Wrong binary format, NULL marker is missing \
or in the wrong place in file : ", file);
}

static void	check_magic(int fd, char *file)
{
	int				ret;
	unsigned char	buff[sizeof(COREWAR_EXEC_MAGIC) + 1];
	unsigned int	cur_res;
	unsigned int	tmp;

	tmp = 0;
	ret = read(fd, buff, sizeof(COREWAR_EXEC_MAGIC));
	buff[ret] = '\0';
	cur_res = *((unsigned int *)ft_memcpy(&tmp, buff,
				sizeof(COREWAR_EXEC_MAGIC)));
	cur_res = (cur_res & BYTE_1) << 24 | (cur_res & BYTE_2) << 8
				| (cur_res & BYTE_3) >> 8 | (cur_res & BYTE_4) >> 24;
	if (cur_res != COREWAR_EXEC_MAGIC)
		ft_print_error_message("Magic_number is different from \
COREWAR_EXEC_MAGIC in file : ", file);
}

static void	check_exec_code(int fd, char *file)
{
	int				ret;
	unsigned int	size;
	unsigned int	tmp;
	unsigned char	buff[sizeof(unsigned int) + 1];

	size = sizeof(unsigned int) * 2 + PROG_NAME_LENGTH;
	lseek(fd, size, SEEK_SET);
	ret = read(fd, buff, sizeof(unsigned int));
	buff[ret] = '\0';
	size = *((unsigned int*)ft_memcpy(&ret, buff,
				sizeof(COREWAR_EXEC_MAGIC)));
	size = (size & BYTE_1) << 24 | (size & BYTE_2) << 8
			| (size & BYTE_3) >> 8 | (size & BYTE_4) >> 24;
	tmp = 0;
	lseek(fd, COMMENT_LENGTH + sizeof(unsigned int), SEEK_CUR);
	while ((ret = read(fd, buff, sizeof(unsigned int) + 1)))
		tmp += ret;
	if (tmp != size || size > (CHAMP_MAX_SIZE))
		ft_print_error_message("Wrong size of exec code in file : ", file);
}

static void	check_binary(char *file)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_print_error_message("Can't open next file : ", file);
	check_magic(fd, file);
	check_null(fd, file);
	check_exec_code(fd, file);
	if (close(fd) != 0)
		ft_print_error_message("Can't close next file : ", file);
}

void		check_binary_files(int *arg_types, char **av, int ac, int files)
{
	int i;

	if (files > MAX_PLAYERS)
		ft_print_usage_and_exit("Too many champions.");
	i = 0;
	while (++i < ac)
		if (arg_types[i - 1] == TYPE_FILE)
			check_binary(av[i]);
}
