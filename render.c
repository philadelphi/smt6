/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:06:14 by phaslan           #+#    #+#             */
/*   Updated: 2022/01/18 20:10:56 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tilemap(t_game *game)
{
	t_tile	**tilemap;

	tilemap = game->tilemap;
	while (*game->tilemap != NULL)
	{
		free(*game->tilemap);
		game->tilemap++;
	}
	free (tilemap);
}

int	end_program(t_game *game)
{
	free_tilemap(game);
	game->tilemap = NULL;
	exit (0);
}

static void	draw_image(t_tile tile, t_game game, t_vector pos)
{
	if (tile.type == WALL)
		mlx_put_image_to_window(game.mlx,
			game.window, game.wall, pos.x, pos.y);
	else if (tile.type == EMPTY)
		mlx_put_image_to_window(game.mlx,
			game.window, game.ground, pos.x, pos.y);
	else if (tile.type == PLAYER)
		mlx_put_image_to_window(game.mlx,
			game.window, game.player.sprite, pos.x, pos.y);
	else if (tile.type == COLLECTABLE)
		mlx_put_image_to_window(game.mlx,
			game.window, game.collec, pos.x, pos.y);
	else if (tile.type == EXIT)
		mlx_put_image_to_window(game.mlx,
			game.window, game.stairs, pos.x, pos.y);
}

void	render(t_game game)
{
	t_tile	tile;
	int		x;
	int		y;

	mlx_clear_window(game.mlx, game.window);
	y = 0;
	while (game.tilemap[y] != NULL)
	{
		x = 0;
		while (game.tilemap[y][x].type != 0)
		{
			tile = game.tilemap[y][x];
			draw_image(tile, game, tile.position);
			x++;
		}
		y++;
	}
}

int	update(t_game *game)
{
	render(*game);
	return (1);
}
