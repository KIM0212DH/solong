/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:21:19 by dokim2            #+#    #+#             */
/*   Updated: 2022/09/10 18:20:41 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char **backup, char *buf)
{
	char	*ret;
	char	*old_backup;
	int		byte;
	int		idx;

	idx = 0;
	if (!*backup || !ft_strlen(*backup))
		return (0);
	byte = 1;
	while (!ft_strchr(*backup, '\n') && byte > 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		buf[byte] = '\0';
		old_backup = *backup;
		*backup = ft_strjoin(*backup, buf);
		free(old_backup);
	}
	while ((*backup)[idx] != '\n' && (*backup)[idx] != '\0')
		idx++;
	ret = (char *)malloc(sizeof(char) * (idx + 2));
	ft_memmove(ret, *backup, (idx) + 1);
	ret[idx + 1] = '\0';
	return (ret);
}

char	*new_backup(char *backup)
{
	size_t	len;
	char	*new;
	size_t	idx;

	idx = 0;
	while (! (backup[idx] == '\n' || backup[idx] == '\0'))
		idx++;
	len = ft_strlen(backup);
	if (len > idx + 1)
	{
		new = ft_strjoin(backup + idx + 1, "");
		free(backup);
		backup = new;
	}
	else
	{
		free(backup);
		backup = NULL;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	char		*old_backup;
	char		*ret;
	int			byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	byte = read(fd, buf, BUFFER_SIZE);
	if (byte == -1 || (byte == 0 && backup == NULL))
		return (NULL);
	buf[byte] = '\0';
	if (byte && backup)
	{
		old_backup = backup;
		backup = ft_strjoin(backup, buf);
		free(old_backup);
	}
	if (byte && !backup)
		backup = ft_strjoin("", buf);
	ret = get_line(fd, &backup, buf);
	backup = new_backup(backup);
	return (ret);
}
