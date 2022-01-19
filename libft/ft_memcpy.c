/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 16:36:54 by phaslan           #+#    #+#             */
/*   Updated: 2021/12/09 12:40:16 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dx;
	char	*sx;

	dx = dst;
	sx = (void *)src;
	if (dx == NULL && sx == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dx[i] = sx[i];
		i++;
	}
	return (dst);
}
