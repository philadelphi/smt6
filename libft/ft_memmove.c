/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 16:38:38 by phaslan           #+#    #+#             */
/*   Updated: 2021/12/09 12:40:21 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dx;
	char	*sx;

	dx = dst;
	sx = (void *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (sx < dx)
	{
		while (++i <= len)
		{
			dx[len - i] = sx[len - i];
		}
	}
	else
	{
		while (i < len)
		{
			dx[i] = sx[i];
			i++;
		}
	}
	return (dx);
}
