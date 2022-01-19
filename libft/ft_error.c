/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:37:21 by phaslan           #+#    #+#             */
/*   Updated: 2022/01/18 16:49:15 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	error(char *message)
{
	printf("%s", message);
	return (0);
}

char	error_char(char *message)
{
	printf("%s", message);
	return (0);
}

void	*null_error(char *message)
{
	printf("%s", message);
	return (0);
}
