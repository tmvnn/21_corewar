/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemtulupov <artemtulupov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:26:35 by ramory-l          #+#    #+#             */
/*   Updated: 2019/12/20 17:24:43 by artemtulupo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_intleng(unsigned long long int n)
{
	int		i;

	i = 0;
	while (n /= 10)
		i++;
	return (i + 1);
}

char				*ft_itoa(unsigned long long int n)
{
	int						leng;
	char					*str;
	unsigned long long int	b;

	b = n;
	leng = ft_intleng(b);
	str = ft_memalloc(leng + 1);
	while (leng-- && str[leng] != '-')
	{
		str[leng] = '0' + (b % 10);
		b /= 10;
	}
	return (str);
}
