/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/08 23:51:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

extern t_uint8	NM_CLASS;

t_error	cast_sym(char *file_ptr, t_elf_sym *sym)
{
	if (NM_CLASS == ELFCLASSNONE)
	{
		ft_perr("unknown class\n");
		return (ERR_CAST_HDR);
	}
	if (NM_CLASS == ELFCLASS64)
		sym->_64 = (Elf64_Sym *)file_ptr;
	else if (NM_CLASS == ELFCLASS32)
		sym->_32 = (Elf32_Sym *)file_ptr;
	return (SUCCESS);
}
