/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:43:50 by phaslan           #+#    #+#             */
/*   Updated: 2022/01/18 16:52:28 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkext(char *file, char *ext)
{
	int	len;
	int	lenext;

	len = ft_strlen(file);
	lenext = ft_strlen(ext);
	len = len - lenext;
	if (file[len] == '\0')
		return (0);
	while (file[len])
	{
		if (file[len] != *ext)
			return (0);
		len++;
		ext++;
	}
	return (1);
}
