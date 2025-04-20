/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 19:30:56 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

extern t_uint8	NM_CLASS;

t_eh_shoff	get_e_hdr_shoff(t_elf_ehdr *e_hdr)
{
	t_eh_shoff	shoff;

	if (is_good_e_hdr(e_hdr))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		shoff = e_hdr->_64->e_shoff;
	else if (NM_CLASS == ELFCLASS32)
		shoff = e_hdr->_32->e_shoff;
	return (shoff);
}

t_error	check_e_hdr_shoff(t_elf_ehdr *e_hdr)
{
	t_eh_shoff	shoff;
	char		*fmt;

	shoff = get_e_hdr_shoff(e_hdr);
	fmt = ELF_STR_EHDR_SHOFF SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, shoff);
	return (SUCCESS);
}