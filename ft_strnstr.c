/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:53:02 by shamzaou          #+#    #+#             */
/*   Updated: 2022/09/20 14:30:33 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i_big;
	unsigned int	i_lit;

	i_big = 0;
	if (!*little || big == little)
		return ((char *)big);
	while (i_big < len)
	{
		i_lit = 0;
		while (little[i_lit] != '\0' && big[i_big + i_lit] == little[i_lit]
			&& (i_lit < (len - i_big)))
		{
			i_lit++;
		}
		if (i_lit == ft_strlen(little))
			return ((char *)(big + i_big));
		i_big++;
	}
	return (NULL);
}
