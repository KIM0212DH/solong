/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:02:52 by dokim2            #+#    #+#             */
/*   Updated: 2022/10/11 16:11:20 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_direction(t_game *game)
{
	int	img_width;
	int	img_height;

	if (game->player.directw == 1)
		game->img.character = mlx_xpm_file_to_image(game->mlx_ptr,
				"./images/player_N01.xpm", &img_width, &img_height);
	else if (game->player.directs == 1)
		game->img.character = mlx_xpm_file_to_image(game->mlx_ptr,
				"./images/player_S01.xpm", &img_width, &img_height);
	else if (game->player.directa == 1)
		game->img.character = mlx_xpm_file_to_image(game->mlx_ptr,
				"./images/player_W01.xpm", &img_width, &img_height);
	else if (game->player.directd == 1)
		game->img.character = mlx_xpm_file_to_image(game->mlx_ptr,
				"./images/player_E01.xpm", &img_width, &img_height);
}
