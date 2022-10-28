/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:02:40 by dokim2            #+#    #+#             */
/*   Updated: 2022/10/11 18:21:53 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	argv[1] = "map.ber";
    if (argc != 1)
        print_err_exit("we need ./solong map_name.ber", &game);
	game_play_init(&game);
	if (!read_map("map.ber", &game))
		print_err_exit("map Error", &game);
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
