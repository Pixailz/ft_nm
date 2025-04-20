/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 19:30:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

extern t_uint8	NM_CLASS;

t_eh_entry	get_e_hdr_phoff(t_elf_ehdr *e_hdr)
{
	t_eh_phoff	phoff;

	if (is_good_e_hdr(e_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		phoff = e_hdr->_64->e_phoff;
	else if (NM_CLASS == ELFCLASS32)
		phoff = e_hdr->_32->e_phoff;
	return (phoff);
}

t_error	check_e_hdr_phoff(t_elf_ehdr *e_hdr)
{
	t_eh_phoff	phoff;
	char		*fmt;

	phoff = get_e_hdr_phoff(e_hdr);
	fmt = ELF_STR_EHDR_PHOFF SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, phoff);
	return (SUCCESS);
}