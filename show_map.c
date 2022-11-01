/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:15:13 by dokim2            #+#    #+#             */
/*   Updated: 2022/10/28 21:02:08 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_ending(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->map);
	ft_printf("complete!\n");
	system("leaks --list -- so_long");
	exit(0);
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
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.road,
			(idx % game->map_wid) * TS, (idx / game->map_wid) * TS);
		if (game->end_flag == 1)
			show_ending(game);
		show_condition(idx, game);
		idx++;
	}
}
