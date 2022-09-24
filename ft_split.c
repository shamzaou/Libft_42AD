/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:52:29 by shamzaou          #+#    #+#             */
/*   Updated: 2022/09/06 10:37:20 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_length(char const *str, char c, size_t	start)
{
	size_t	length;

	length = start;
	while (str[length] && str[length] != c)
	{
		length++;
	}
	length = length - start;
	return (length);
}

static size_t	str_count(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != '\0')
			count++;
		i = i + str_length(s, c, i);
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**split;

	i = 0;
	j = 0;
	split = (char **)ft_calloc(sizeof(char *), (str_count(s, c) + 1));
	if (!split || !s)
	{
		free((void **)split);
		return (NULL);
	}
	while (j < (str_count(s, c)))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] && s[i] != '\0')
			split[j] = ft_substr(s, i, str_length(s, c, i));
		if (!split[j])
			return (NULL);
		i = i + str_length(s, c, i);
		j++;
	}
	return (split);
}
