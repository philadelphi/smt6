/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:49:17 by phaslan           #+#    #+#             */
/*   Updated: 2022/01/18 18:35:25 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../gnl/get_next_line.h"

int	ft_table_count(char **file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	return (i);
}

void	ft_chartable_free(char **table)
{
	int	i;

	i = 0;
	while (table[i] != '\0')
	{
		free(table[i]);
		i++;
	}
	free (table[i]);
}

void	ft_window_size(t_game *game, int x, int y)
{
	x--;
	game->windowsize.x = x * IMG_SIZE;
	game->windowsize.y = y * IMG_SIZE;
}

int	ft_valid_extension(int ac, char *av)
{
	int	valid;

	if (ac != 2)
	{
		return (error("Error\nmauvais args"));
	}
	if (ac == 2)
	{
		valid = ft_checkext(av, ".ber");
		if (valid)
			return (valid);
	}
	return (error("Error\nmauvaise ext"));
}

void	check_vars(t_mapdata *mapdata, char c)
{
	if (c == 'E')
		mapdata->exit += 1;
	if (c == 'C')
		mapdata->collec += 1;
	if (c == 'P')
		mapdata->player += 1;
}
