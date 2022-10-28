/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:34:01 by dokim2            #+#    #+#             */
/*   Updated: 2022/09/10 18:23:20 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

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
