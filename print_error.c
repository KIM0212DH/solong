/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:19:41 by dokim2            #+#    #+#             */
/*   Updated: 2022/10/11 18:20:45 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err_exit(char *msg, t_game *game)
{
	ft_printf("%s\n", msg);
	free(game->map);
	system("leaks --list -- solong");
	exit(1);
}
