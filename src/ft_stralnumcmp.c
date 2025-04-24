/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralnumcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:48:57 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/25 00:12:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * @brief			Compare two strings, only on alpha numeric portion
 *
 * @param char* s1		First string
 * @param char* s2		Second string
 *
 * @return (int)	0 if s1 is the same as s2, postive if s1 greater and
 * 					negative if s2 is greater
 */

int	ft_stralnumcasecmp(char *s1, char *s2)
{
	int				i1;
	int				i2;
	unsigned char	u1;
	unsigned char	u2;

	i1 = 0;
	i2 = 0;
	u1 = 0;
	u2 = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (0 - *s2);
	if (!s2)
		return (*s1);
	while (s1[i1] && s2[i2])
	{
		while (s1[i1] && !ft_isalnum(s1[i1]))
			i1++;
		while (s2[i2] && !ft_isalnum(s2[i2]))
			i2++;
		if ((u1 = ft_toupper(s1[i1])) != (u2 = ft_toupper(s2[i2])))
			break ;
		i1++;
		i2++;
	}
	if (u1 == u2 && i1 == i2 && ft_strcmp(s1, s2))
	{
		if (ft_is_str(s1, ft_isalnum) && ft_is_str(s2, ft_isalnum))
			return (ft_strcmp(s2, s1));
		else
			return (ft_strcmp(s1, s2));
	}
	if (s1[i1] == s2[i2])
	{
		if (i1 < i2)
			return (1);
		else if (i2 < i1)
			return (-1);
	}
	return (u1 - u2);
}
