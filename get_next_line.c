/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czorraqu <czorraqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:07:48 by czorraqu          #+#    #+#             */
/*   Updated: 2022/11/10 20:21:18 by czorraqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_substr(str, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_deleteline(char *str)
{
	char	*nextline;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (free_ptr(&str));
	nextline = ft_substr(str, i + 1, ft_strlen(str));
	if (!nextline)
		return (free_ptr(&str));
	free_ptr(&str);
	return (nextline);
}

char	*ft_readline(int fd, char *str)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_ptr(&str));
	buffer[0] = '\0';
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			str = ft_strjoin(str, buffer);
			if (!str)
				return (free_ptr(&buffer));
		}
	}
	free_ptr(&buffer);
	if (bytes == -1)
		return (free_ptr(&str));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*almacen = NULL;
	char		*line;

	line = "";
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	almacen = ft_readline(fd, almacen);
	if (!almacen)
		return (NULL);
	line = ft_getline(almacen);
	if (!line)
		return (free_ptr(&almacen));
	almacen = ft_deleteline(almacen);
	return (line);
}

// int main(void)
// {
// 	int fd;

// 	fd = open("hola.txt", O_RDONLY);

// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return (0);
// }
