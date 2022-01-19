/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 17:05:56 by phaslan           #+#    #+#             */
/*   Updated: 2021/12/09 12:42:12 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*p;

	p = 0;
	while (*str)
	{
		if (*str == c)
			p = (char *)str;
		str++;
	}
	if (*str == c)
		return ((char *)str);
	return (p);
}
