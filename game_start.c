/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:06:34 by phaslan           #+#    #+#             */
/*   Updated: 2022/01/18 19:17:43 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map/map.h"

int	is_dir(char *pathname)
{
	int	fd;

	fd = open(pathname, O_DIRECTORY);
	if (fd > -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

t_tile	**map_start(int ac, char **av, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	if (!ft_valid_extension(ac, av[1]))
		return (NULL);
	if (is_dir(av[1]))
		return (null_error("Error\nmauvais args"));
	map = read_map(av[1]);
	if (!map)
		return (NULL);
	if (is_map_valid(map) == 0)
	{
		ft_chartable_free(map);
		return (NULL);
	}
	tilemap = get_map(map, game);
	ft_chartable_free(map);
	putchar('z');
	if (!tilemap)
		return (NULL);
	return (tilemap);
}

void	open_images(t_game *game)
{
	game->stairs = mlx_xpm_file_to_image(game->mlx,
			"assets/stairs.xpm", &game->spritesize.x, &game->spritesize.y);
	game->player.sprite = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm", &game->spritesize.x, &game->spritesize.y);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &game->spritesize.x, &game->spritesize.y);
	game->ground = mlx_xpm_file_to_image(game->mlx,
			"assets/ground.xpm", &game->spritesize.x, &game->spritesize.y);
	game->collec = mlx_xpm_file_to_image(game->mlx,
			"assets/collec.xpm", &game->spritesize.x, &game->spritesize.y);
}

int	start(t_game *game, int ac, char **av)
{
	game->collects = 0;
	game->moves = 0;
	game->tilemap = map_start(ac, av, game);
	if (game->tilemap == NULL)
		return (0);
	open_images(game);
	return (1);
}
