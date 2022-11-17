/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:08:30 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/17 20:03:38 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	char	*ss;
	char	cc;

	if (!s)
		return (0);
	ss = (char *)s;
	cc = (char)c;
	while (*ss)
	{
		if (*ss == cc)
			return (ss);
		ss++;
	}
	if (*ss == cc)
		return (ss);
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*result;
	int		i;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = 0;
	return (result);
}
