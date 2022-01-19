/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:06:28 by phaslan           #+#    #+#             */
/*   Updated: 2022/01/18 19:17:44 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (!start(&game, ac, av))
		return (0);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx,
			game.windowsize.x, game.windowsize.y, "so_long");
	mlx_hook(game.window, 02, 0, ft_input, (void *)&game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx);
}
