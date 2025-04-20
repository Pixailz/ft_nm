/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:22:30 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 17:20:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	free_target(void)
{
	char	**target;

	target = sing_get_target();
	if (target != FT_NULL)
		free(target);
}

void	free_prog(void)
{
	free_target();
}