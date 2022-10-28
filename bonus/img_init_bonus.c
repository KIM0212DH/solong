/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:27:18 by dokim2            #+#    #+#             */
/*   Updated: 2022/10/11 18:16:41 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_init(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img.road = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/road.xpm", &img_width, &img_height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/wall.xpm", &img_width, &img_height);
	game->img.character = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/player_S01.xpm", &img_width, &img_height);
	game->img.exitclosed = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/stone.xpm", &img_width, &img_height);
	game->img.exitopen = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/ladder.xpm", &img_width, &img_height);
	game->img.collection = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/ball.xpm", &img_width, &img_height);
	game->img.ending = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/ending.xpm", &img_width, &img_height);
}
