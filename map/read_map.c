/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:57:44 by phaslan           #+#    #+#             */
/*   Updated: 2022/01/18 20:44:17 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "map.h"

int	check_line(char *file)
{
	int		fd;
	int		lines;
	int		readc;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	lines = 1;
	while (1)
	{
		readc = read(fd, &c, 1);
		if (readc == 0)
			break ;
		if (readc < 0)
			return (error("error\npas de ligne\n"));
		if (c == '\n')
			lines++;
	}
	close(fd);
	return (lines);
}

static	char	**malloc_columns(char *file)
{
	char	**map;
	int		line_count;

	line_count = check_line(file);
	if (line_count <= 0)
		return (null_error("error\nfichier nul\n"));
	map = malloc(sizeof(char *) * line_count + 1);
	if (map == NULL)
		return (null_error("malloc raté"));
	return (map);
}

char	**read_map(char *mapx)
{
	char	**map;
	int		fd;
	int		line;
	int		y;

	map = malloc_columns(mapx);
	if (map == NULL)
		return (NULL);
	line = check_line(mapx);
	fd = open(mapx, O_RDONLY);
	y = 0;
	while (y < line)
	{
		map[y] = get_next_line(fd);
		y++;
	}
	close (fd);
	map[y] = NULL;
	return (map);
}
