/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 19:30:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

extern t_uint8	NM_CLASS;

t_eh_entry	get_e_hdr_entry(t_elf_ehdr *e_hdr)
{
	t_eh_entry	entry;

	if (is_good_e_hdr(e_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		entry = e_hdr->_64->e_entry;
	else if (NM_CLASS == ELFCLASS32)
		entry = (t_eh_entry)e_hdr->_32->e_entry;
	return (entry);
}

t_error	check_e_hdr_entry(t_elf_ehdr *e_hdr)
{
	t_eh_entry	entry;
	char		*fmt;

	entry = get_e_hdr_entry(e_hdr);
	fmt = ELF_STR_EHDR_ENTRY SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, entry);
	return (SUCCESS);
}
