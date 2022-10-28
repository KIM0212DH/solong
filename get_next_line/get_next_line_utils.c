/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:21:33 by dokim2            #+#    #+#             */
/*   Updated: 2022/09/10 18:25:07 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	temp;
	int		i;

	temp = (unsigned char)c;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == temp)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == temp)
		return ((char *)&s[i]);
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;
	size_t			i;

	if (dst == 0 && src == 0)
		return (0);
	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		if (t_src > t_dst)
		{
			t_dst[i] = t_src[i];
			i++;
		}
		else
		{
			t_dst[len - 1 - i] = t_src[len - 1 - i];
			i++;
		}
	}
	return (t_dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	count;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	count = s1_len + s2_len;
	ret = (char *)malloc(sizeof(char) * (count + 1));
	if (!ret)
		return (0);
	ft_memmove(ret, s1, s1_len);
	ft_memmove(ret + s1_len, s2, s2_len);
	ret[count] = '\0';
	return (ret);
}
