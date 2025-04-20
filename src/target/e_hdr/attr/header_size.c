/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 19:30:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

extern t_uint8	NM_CLASS;

t_eh_ehsize	get_e_hdr_ehsize(t_elf_ehdr *e_hdr)
{
	t_eh_ehsize	ehsize;

	if (is_good_e_hdr(e_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		ehsize = e_hdr->_64->e_ehsize;
	else if (NM_CLASS == ELFCLASS32)
		ehsize = e_hdr->_32->e_ehsize;
	return (ehsize);
}

t_error	check_e_hdr_ehsize(t_elf_ehdr *e_hdr)
{
	t_eh_ehsize	ehsize;
	char		*fmt;

	ehsize = get_e_hdr_ehsize(e_hdr);
	fmt = ELF_STR_EHDR_SIZE SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, ehsize);
	return (SUCCESS);
}
