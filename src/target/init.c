/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:28:13 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 19:54:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_error	init_target(char *target, t_nm *main)
{
	int		fd;
	t_error	retv;

	main->file_path = target;
	CHECK_RET(retv, open_target, target, &fd);
	if ((retv = get_stat(fd, &main->stat)))
	{
		close(fd);
		return (retv);
	}
	CHECK_RET(retv, map_target, fd, main->stat.st_size, &main->file_ptr);
	close(fd);
	ft_pdeb("File size: %d\n", main->stat.st_size);
	return (retv);
}