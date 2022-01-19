/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:36:25 by phaslan           #+#    #+#             */
/*   Updated: 2022/01/18 19:17:51 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124  
# define LEFT 123
# define IMG_SIZE 32

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}	t_tiletype;

typedef struct s_tile
{
	t_tiletype		type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_player
{
	t_tile	*tile;
	void	*sprite;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	t_vector	windowsize;
	t_vector	spritesize;
	t_tile		**tilemap;
	int			collects;
	int			moves;
	t_player	player;
	void		*stairs;
	void		*collec;
	void		*wall;
	void		*ground;
	int			backup;
}	t_game;

int	start(t_game *game, int ac, char **av);
int	ft_input(int keycode, t_game *game);
int	update(t_game *game);
int	end_program(t_game *game);

#endif