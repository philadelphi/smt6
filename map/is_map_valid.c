/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:02:56 by phaslan           #+#    #+#             */
/*   Updated: 2022/01/18 20:24:04 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"

int	check_wall(int y, int x, t_mapdata *mapdata, char read)
{
	if (y == 0 || x == 0
		|| y == mapdata->size.y - 1 || x == mapdata->size.x - 2)
		if (read != '1')
			return (0);
	return (1);
}

int	is_good_form(t_mapdata mapdata, char **map)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	x = mapdata.size.x;
	i = 0;
	while (y < mapdata.size.y && map[y][0] != '\0')
	{
		i = ft_strlen(map[y]);
		if (x != i)
			return (0);
		y++;
	}
	if (mapdata.size.y == mapdata.size.x - 1)
		return (0);
	return (1);
}

int	check_if_valid_char(t_mapdata *mapdata, char **map)
{
	int		y;
	int		x;
	char	read;

	y = 0;
	while (y < mapdata->size.y && map[y][0] != '\0')
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			read = map[y][x];
			if (!ft_strrchr("01CEP", read))
				return (0);
			if (!check_wall(y, x, mapdata, read))
				return (0);
			check_vars(mapdata, read);
			x++;
		}
		y++;
	}
	return (1);
}

t_mapdata	arrange_struct(char **map)
{
	t_mapdata	map_data;

	map_data.size.x = ft_strlen(map[0]);
	map_data.size.y = ft_table_count(map);
	map_data.curser.x = 0;
	map_data.curser.y = 0;
	map_data.square.x = 0;
	map_data.square.y = 0;
	map_data.player = 0;
	map_data.collec = 0;
	map_data.exit = 0;
	return (map_data);
}

int	is_map_valid(char **map)
{
	int			i;
	t_mapdata	mapdata;

	i = 0;
	mapdata = arrange_struct(map);
	if (!is_good_form(mapdata, map))
		return (error("error\nla forme n'est pas bonne\n"));
	if (!check_if_valid_char(&mapdata, map))
		return (error("error\nla map contient un char invalide\n"));
	if (mapdata.player != 1 || mapdata.collec <= 0 || mapdata.exit <= 0)
		return (error("error\nla map n'a pas le bon nombre de variables\n"));
	return (1);
}
