/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:28:13 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/13 13:44:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_error open_target(char *target, int *fd)
{
	*fd = open(target, O_RDONLY);
	if (*fd < 0)
	{
		ft_pdeb("Failed opening file: %s\n", target);
		ft_dprintf(2, "%s: '%s': No such file\n", PROG_NAME, target);
		return (ERR_TARGET_OPEN);
	}
	return (SUCCESS);
}
