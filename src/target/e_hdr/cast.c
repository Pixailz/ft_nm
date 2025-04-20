/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/07 14:43:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

extern t_uint8	NM_CLASS;

t_error	cast_e_hdr(char *file_ptr, t_elf_ehdr *e_hdr)
{
	if (NM_CLASS == ELFCLASSNONE)
	{
		ft_perr("unknown class\n");
		return (ERR_CAST_HDR);
	}
	if (NM_CLASS == ELFCLASS64)
		e_hdr->_64 = (Elf64_Ehdr *)file_ptr;
	else if (NM_CLASS == ELFCLASS32)
		e_hdr->_32 = (Elf32_Ehdr *)file_ptr;
	return (SUCCESS);
}
