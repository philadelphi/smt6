/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 17:30:48 by phaslan           #+#    #+#             */
/*   Updated: 2021/12/09 12:52:46 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			len;

	ptr = NULL;
	ptr = malloc(count * size);
	if (ptr)
	{
		len = count * size;
		while (len--)
			ptr[len] = 0;
	}
	return (ptr);
}
