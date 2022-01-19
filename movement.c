/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:06:06 by phaslan           #+#    #+#             */
/*   Updated: 2022/01/18 20:17:34 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_empty(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

void	pick_collect(t_game *game, t_tile *tile)
{
	tile->type = EMPTY;
	game->collects--;
}

void	move_to_exit(t_game *game)
{
	printf("rayquaza a bien mangé\n");
	end_program(game);
}

int	move_to(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		pick_collect(game, tile);
	else if (tile->type == EXIT && game->collects <= 0)
		move_to_exit(game);
	else if (tile->type == WALL)
		return (FALSE);
	return (TRUE);
}

int	ft_input(int key, t_game *game)
{
	int	moved;

	if (key == UP)
		moved = move_to(game, game->player.tile->up);
	else if (key == DOWN)
		moved = move_to(game, game->player.tile->down);
	else if (key == LEFT)
		moved = move_to(game, game->player.tile->left);
	else if (key == RIGHT)
		moved = move_to(game, game->player.tile->right);
	else
		return (0);
	if (moved)
		printf("Moves -> %02d\n", ++game->moves);
	return (1);
}
