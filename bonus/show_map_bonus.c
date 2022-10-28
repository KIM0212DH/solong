/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:15:13 by dokim2            #+#    #+#             */
/*   Updated: 2022/10/11 16:35:30 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	show_ending(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.ending, game->map_wid * TS / 3, 0);
}

void	show_condition(int idx, t_game *game)
{
	if (game->map[idx] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.road,
			(idx % game->map_wid) * TS, (idx / game->map_wid) * TS);
	else if (game->map[idx] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.wall, (idx % game->map_wid) * TS,
			(idx / game->map_wid) * TS);
	else if (game->map[idx] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.character, (idx % game->map_wid) * TS,
			(idx / game->map_wid) * TS);
	else if (game->map[idx] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.collection, (idx % game->map_wid) * TS,
			(idx / game->map_wid) * TS);
	else if (game->map[idx] == 'E' && game->collection == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.exitopen, (idx % game->map_wid) * TS,
			(idx / game->map_wid) * TS);
	else if (game->map[idx] == 'E' && game->collection != 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.exitclosed, (idx % game->map_wid) * TS,
			(idx / game->map_wid) * TS);
}

void	show_map(t_game *game)
{
	int	idx;

	idx = 0;
	while (game->map[idx] != '\0')
	{
        mlx_string_put(game->mlx_ptr, game->win_ptr, 32, 32, 0x000000, ft_itoa(game->cnt));
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.road,
			(idx % game->map_wid) * TS, (idx / game->map_wid) * TS);
		if (game->end_flag == 1)
			show_ending(game);
		show_condition(idx, game);
		idx++;
	}
}
