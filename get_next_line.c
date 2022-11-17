/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:21:11 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/17 20:22:03 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*ft_read(int fd, char *total)
{
	char	*buffer;
	int		result;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	result = 1;
	while (result != 0 && !ft_strchr(total, '\n'))
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[result] = 0;
		total = ft_strjoin(total, buffer);
	}
	free(buffer);
	return (total);
}

char	*get_line(char *total)
{
	char	*result;
	int		length;

	length = 0;
	while (total[length] != '\n')
		length++;
	result = malloc((length + 2) * sizeof(char));
	if (!result)
		return (0);
	length = 0;
	while (*total && *total != '\n')
		result[length++] = *total++;
	result[length++] = '\n';
	result[length] = 0;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*total;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	total = ft_read(fd, total);
	if (!total)
		return (0);
	line = get_line(total);
	total += ft_strlen(line);
	printf("total %s\n", total);
	return (line);
}

int	main()
{
	int		fd;
	char	*text;

	fd = open("salut", O_RDONLY);
	text = get_next_line(fd);
	printf("rendu : %s\n", text);
	text = get_next_line(fd);
	printf("ensuite %s\n", text);
	return (0);
}
