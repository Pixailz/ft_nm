/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:28:13 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 21:26:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_error map_target(int fd, t_int32 size, char **ptr)
{
	*ptr = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (*ptr == MAP_FAILED)
		return (ERR_TARGET_MAP);
	return (SUCCESS);
}