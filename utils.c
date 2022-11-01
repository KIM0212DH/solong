/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:13:16 by dokim2            #+#    #+#             */
/*   Updated: 2022/10/28 21:27:18 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkopen_size(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_err_exit3("File open fail Error");
	line = get_next_line(fd);
	if (line == 0)
		print_err_exit2("File empty Error", line);
	game->map_wid = ft_strlen(line) - 1;
	check_map(fd, line, game);
	return (game->map_hei * game->map_wid);
}

void	checking_1d_arr(int idx, char *map, t_game *game)
{
	check_1d_char(idx, map, game);
	if (game->player.x == -1 || game->player.y == -1)
		print_err_exit("no player Error", game);
	if (game->collection == 0)
		print_err_exit("no collection Error", game);
	if (game->exit_cnt != 1)
		print_err_exit("exit is not one", game);
}

char	*fill_map(char *map, char *filename, t_game *game)
{
	int		fd;
	int		idx;
	char	*line;

	idx = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line > 0)
	{
		if (line[ft_strlen(line) - 1] == '\n')
		{
			ft_memcpy(map + idx, line, ft_strlen(line) - 1);
			idx = idx + ft_strlen(line) - 1;
		}
		else if (line[ft_strlen(line)] == '\0')
		{
			ft_memcpy(map + idx, line, ft_strlen(line));
			idx = idx + ft_strlen(line);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	checking_1d_arr(idx, map, game);
	return (map);
}

int	read_map(char *filename, t_game *game)
{
	int	size;

	size = checkopen_size(filename, game);
	game->size = size;
	game->map = (char *) malloc (sizeof(char) * (size + 1));
	if (!(game->map))
	{
		free(game->map);
		return (0);
	}
	game->map = fill_map(game->map, filename, game);
	game->map[size] = '\0';
	return (1);
}

void	game_play_init(t_game *game)
{
	game->map_hei = 0;
	game->map_wid = 0;
	game->collection = 0;
	game->player.x = -1;
	game->player.y = -1;
	game->player.directs = 1;
	game->player.directa = 0;
	game->player.directd = 0;
	game->player.directw = 0;
	game->end_flag = 0;
	game->cnt = 0;
	game->exit_cnt = 0;
}
