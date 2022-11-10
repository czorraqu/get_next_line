/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czorraqu <czorraqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:07:43 by czorraqu          #+#    #+#             */
/*   Updated: 2022/11/07 18:46:22 by czorraqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*a;

	i = 0;
	a = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (&a[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&a[i]);
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	if (ft_strlen(s) <= start || len == 0 || ft_strlen(s) == 0)
		size = 0;
	else if (len <= ft_strlen(s) && start + len < ft_strlen(s))
		size = len;
	else
		size = ft_strlen(s) - start;
	sub = (char *) malloc(size + 1);
	if (sub == NULL)
		return (0);
	*sub = '\0';
	if (start < ft_strlen(s))
	{
		while (i < size)
		{
			sub[i] = s[start + i];
			i++;
		}
		sub[i] = '\0';
	}
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*joined;
	size_t		i;

	i = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (free_ptr(&s1));
	while (s1[++i] != '\0')
		joined[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		joined[ft_strlen(s1) + i] = s2[i];
	joined[ft_strlen(s1) + i] = '\0';
	free_ptr(&s1);
	return (joined);
}
