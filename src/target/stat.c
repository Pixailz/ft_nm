/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 20:32:47 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/11 16:33:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_error	get_stat(int fd, struct stat *stat)
{
	if (fstat(fd, stat) < 0)
	{
		ft_perr("Failed getting file stat\n");
		return (ERR_TARGET_STAT);
	}
	return (SUCCESS);
}