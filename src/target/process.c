/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:28:13 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 17:00:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_elf_error	process_target(char *target)
{
	t_elf_error	retv;
	t_elfbin	bin;

	if ((retv = ft_readelf(target, &bin)))
	{
		ft_readelf_free(bin);
		return (retv);
	}
	CHECK_RET(retv, print_syms, &bin);
	ft_readelf_free(bin);
	return (retv);
}