/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:02:40 by dokim2            #+#    #+#             */
/*   Updated: 2022/10/28 21:02:42 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		print_err_exit3("we need ./solong map_name.ber");
	game_play_init(&game);
	if (!read_map(argv[1], &game))
		print_err_exit3("map Error");
	game.mlx_ptr = mlx_init();
	img_init(&game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map_wid * TS,
			game.map_hei * TS, "mlx 42");
	show_map(&game);
	mlx_hook(game.win_ptr, X_EVENT_KEY_RELEASE, 0, &key_press, &game);
	mlx_hook(game.win_ptr, X_EVENT_EXIT, 0, &exit_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
