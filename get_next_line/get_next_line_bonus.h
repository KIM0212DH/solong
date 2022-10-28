/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:59:57 by dokim2            #+#    #+#             */
/*   Updated: 2022/09/10 21:14:13 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*get_line(int fd, char **backup, char *buf);
int		ft_read_file(int fd, char *buf, char *backup);
char	*new_backup(char *backup);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
