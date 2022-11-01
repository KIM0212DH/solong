/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:19:41 by dokim2            #+#    #+#             */
/*   Updated: 2022/10/28 21:01:09 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err_exit(char *msg, t_game *game)
{
	ft_printf("%s\n", msg);
	free(game->map);
	system("leaks --list -- so_long");
	exit(1);
}

void	print_err_exit2(char *msg, char *line)
{
	ft_printf("%s\n", msg);
	free(line);
	system("leaks --list -- so_long");
	exit(1);
}

void	print_err_exit3(char *msg)
{
	ft_printf("%s\n", msg);
	system("leaks --list -- so_long");
	exit(1);
}
