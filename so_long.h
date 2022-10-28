/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:32:29 by dokim2            #+#    #+#             */
/*   Updated: 2022/10/11 18:44:56 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx_opengl_20191021/mlx.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

# define TS           64
# define X_EVENT_KEY_PRESS      2
# define X_EVENT_KEY_RELEASE    3
# define X_EVENT_EXIT           17
# define KEY_ESC                53
# define KEY_W                  13
# define KEY_A                  0
# define KEY_S                  1
# define KEY_D                  2

typedef struct s_img
{
	void	*road;
	void	*wall;
	void	*character;
	void	*collection;
	void	*exitclosed;
	void	*exitopen;
	void	*ending;
}	t_img;

typedef struct s_player
{
	int	x;
	int	y;
	int	directw;
	int	directs;
	int	directd;
	int	directa;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*map;
	int			map_hei;
	int			map_wid;
	int			collection;
	int			end_flag;
	int			cnt;
    int         exit_cnt;
	t_player	player;
	t_img		img;
}	t_game;

void	game_play_init(t_game *game);
void	img_init(t_game *game);
void	start_place(t_player *player, int x, int y);
int		checkopen_size(char *filename, t_game *game);
char	*fill_map(char *map, char *filename, t_game *game);
int		read_map(char *filename, t_game *game);
void	print_err_exit(char *msg, t_game *game);
void	show_map(t_game *game);
int		key_press(int keycode, t_game *game);
int		exit_game(t_game *game);
void	check_direction(t_game *game);
void	clear_exit_game(t_game *game);
void	show_condition(int idx, t_game *game);

#endif
