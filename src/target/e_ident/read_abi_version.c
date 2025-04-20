/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_abi_version.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:07:52 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/07 15:15:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_error	read_e_ident_abi_version(char *file_ptr, t_elf_hdr_ident *elf_hdr)
{
	t_uint16	ptr;

	ptr = *(t_uint16 *)(file_ptr + EI_OSABI);
	elf_hdr->abi_version = ptr;
	ft_pdeb(ELF_STR_EHDR_IDENT_ABI_VERSION SEP "%d\n", elf_hdr->abi_version);
	return (SUCCESS);
}
