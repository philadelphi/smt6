/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:05:29 by phaslan           #+#    #+#             */
/*   Updated: 2022/01/18 20:21:45 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../so_long.h"

typedef struct s_mapdata
{
	t_vector	size;
	t_vector	curser;
	t_vector	square;

	int			player;
	int			exit;
	int			collec;
}					t_mapdata;

int			ft_valid_extension(int ac, char *av);
int			is_map_valid(char **map);
char		**read_map(char *mapx);
int			check_line(char *file);
t_mapdata	arrange_struct(char **map);
int			check_if_valid_char(t_mapdata *mapdata, char **map);
int			is_good_form(t_mapdata mapdata, char **map);
int			check_wall(int y, int x, t_mapdata *mapdata, char read);
void		ft_chartable_free(char **table);
int			ft_table_count(char **file);
t_tile		**get_map(char **map, t_game *game);
void		ft_window_size(t_game *game, int x, int y);
void		check_vars(t_mapdata *mapdata, char c);

#endif
