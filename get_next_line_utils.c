/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:52:32 by vsanz-su          #+#    #+#             */
/*   Updated: 2023/10/25 10:15:24 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		return (0);
	}
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char const *s1)
{
	char	*d;
	int		n;

	n = 0;
	while (s1[n])
	{
		n++;
	}
	d = (char *)malloc((n + 1) * sizeof(char));
	if (!d)
	{
		return (NULL);
	}
	n = 0;
	while (s1[n])
	{
		d[n] = s1[n];
		n++;
	}
	d[n] = '\0';
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	temp = malloc(len + 1);
	if (!temp)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			temp[j++] = s[i];
		i++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*ft_strchr(char const *s, int c)
{
	int				i;
	unsigned char	temp;

	i = 0;
	temp = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == temp)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == temp)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	str[ft_strlen(s1) + i] = '\0';
	return (str);
}
