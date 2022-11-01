/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1darr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:43:43 by dokim2            #+#    #+#             */
/*   Updated: 2022/11/01 13:16:12 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(int fd, char *line, t_game *game)
{
	while (line > 0)
	{
		if (line[ft_strlen(line) - 1] == '\n')
		{
			if (game->map_wid != (int)ft_strlen(line) - 1)
				print_err_exit2("line align Error", line);
		}
		else if (line[ft_strlen(line)] == '\0')
		{
			if (game->map_wid != (int)ft_strlen(line))
				print_err_exit2("line align Error", line);
		}
		game->map_hei = game->map_hei + 1;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	check_correct_input(char input, t_game *game)
{
	if (input != 'P' && input != 'C' && input != '1'
		&& input != '0' && input != 'E')
		print_err_exit("unvalid input", game);
}

void	check_1d_char(int idx, char *map, t_game *game)
{
	idx = 0;
	while (idx < game->size)
	{
		check_correct_input(map[idx], game);
		if ((idx < game->map_wid && map[idx] != '1')
			|| ((idx > game->map_wid * (game->map_hei - 1)) && map[idx] != '1'))
			print_err_exit("wall Error", game);
		if ((idx % game->map_wid == 0 && map[idx] != '1')
			|| (idx % game->map_wid == game->map_wid - 1 && map[idx] != '1'))
			print_err_exit("wall Error", game);
		if (map[idx] == 'C')
			game->collection++;
		if (map[idx] == 'P')
		{
			if (game->player.x != -1 || game->player.y != -1)
				print_err_exit("more than one player\n", game);
			game->player.x = idx % game->map_wid;
			game->player.y = idx / game->map_wid;
		}
		if (map[idx++] == 'E')
			game->exit_cnt++;
	}
}
