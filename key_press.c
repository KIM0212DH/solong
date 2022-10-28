/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:00:35 by dokim2            #+#    #+#             */
/*   Updated: 2022/10/11 18:19:50 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_game *game)
{
	game->player.directw = 1;
	if (game->player.y < 1
		|| game->map[(game->player.y - 1)
			* game->map_wid + game->player.x] == '1')
		return ;
	if (game->collection != 0
		&& game->map[((game->player.y - 1)
				* game->map_wid + game->player.x)] == 'E')
		return ;
	if (game->collection == 0 && game->map[((game->player.y - 1)
				* game->map_wid + game->player.x)] == 'E')
		game->end_flag = 1;
	if (game->map[((game->player.y - 1)
				* game->map_wid + game->player.x)] == 'C')
			game->collection--;
	game->map[game->player.y * game->map_wid + game->player.x] = '0';
	game->map[((game->player.y - 1) * game->map_wid + game->player.x)] = 'P';
	game->player.y--;
	game->cnt++;
}

void	move_s(t_game *game)
{
	game->player.directs = 1;
	if (game->player.y >= game->map_hei - 2
		|| game->map[((game->player.y + 1)
				* game->map_wid + game->player.x)] == '1')
		return ;
	if (game->collection != 0
		&& game->map[((game->player.y + 1)
				* game->map_wid + game->player.x)] == 'E')
		return ;
	if (game->collection == 0 && game->map[((game->player.y + 1)
				* game->map_wid + game->player.x)] == 'E')
		game->end_flag = 1;
	if (game->map[((game->player.y + 1)
				* game->map_wid + game->player.x)] == 'C')
		game->collection--;
	game->map[game->player.y * game->map_wid + game->player.x] = '0';
	game->map[((game->player.y + 1) * game->map_wid + game->player.x)] = 'P';
	game->player.y++;
	game->cnt++;
}

void	move_d(t_game *game)
{
	game->player.directd = 1;
	if (game->player.x >= game->map_wid - 2
		|| game->map[game->player.y
			* game->map_wid + game->player.x + 1] == '1')
		return ;
	if (game->collection != 0
		&& game->map[game->player.y
			* game->map_wid + game->player.x + 1] == 'E')
		return ;
	if (game->collection == 0 && game->map[game->player.y
			* game->map_wid + game->player.x + 1] == 'E')
		game->end_flag = 1;
	if (game->map[game->player.y * game->map_wid + game->player.x + 1] == 'C')
		game->collection--;
	game->map[game->player.y * game->map_wid + game->player.x] = '0';
	game->map[game->player.y * game->map_wid + game->player.x + 1] = 'P';
	game->player.x++;
	game->cnt++;
}

void	move_a(t_game *game)
{
	game->player.directa = 1;
	if (game->player.x < 1
		|| game->map[game->player.y
			* game->map_wid + game->player.x - 1] == '1')
		return ;
	if (game->collection != 0
		&& game->map[game->player.y
			* game->map_wid + game->player.x - 1] == 'E')
		return ;
	if (game->collection == 0 && game->map[game->player.y
			* game->map_wid + game->player.x - 1] == 'E')
		game->end_flag = 1;
	if (game->map[game->player.y * game->map_wid + game->player.x - 1] == 'C')
		game->collection--;
	game->map[game->player.y * game->map_wid + game->player.x] = '0';
	game->map[game->player.y * game->map_wid + game->player.x - 1] = 'P';
	game->player.x--;
	game->cnt++;
}

int	key_press(int keycode, t_game *game)
{
	game->player.directw = 0;
	game->player.directs = 0;
	game->player.directd = 0;
	game->player.directa = 0;
	if (keycode == KEY_W)
		move_w(game);
	else if (keycode == KEY_S)
		move_s(game);
	else if (keycode == KEY_D)
		move_d(game);
	else if (keycode == KEY_A)
		move_a(game);
	else if (keycode == KEY_ESC)
		exit(0);
	ft_printf("x: %d, y: %d\n", game->player.x, game->player.y);
	ft_printf("collection : %d\n", game->collection);
	ft_printf("move cnt: %d\n", game->cnt);
	check_direction(game);
	show_map(game);
	if (game->end_flag == 1)
		ft_printf("complete!\n");
	return (0);
}
