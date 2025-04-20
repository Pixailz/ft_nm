/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:57:07 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/18 17:35:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

char	get_sym_type(t_sym *symbole)
{
	char		retv;
	t_sh_type	h_type;
	t_sh_flags	h_flags;

	h_type = get_s_hdr_type(symbole->shdr);
	h_flags = get_s_hdr_flags(symbole->shdr);
	retv = '?';
	if (!ft_strncmp(symbole->name, ".SUNW_signature", 15))
		return ('n');
	else if (!ft_strncmp(symbole->name, ".debug", 6))
		return ('N');
	else if (symbole->bind == STB_GNU_UNIQUE)
		retv = 'u';
	else if (symbole->bind == STB_WEAK)
	{
		retv = 'W';
		if (symbole->type == STT_OBJECT)
			retv = 'V';

		if (symbole->shndx == SHN_UNDEF)
			retv = ft_tolower(retv);
	}
	else if (symbole->shndx == SHN_UNDEF)
		retv = 'U';
	else if (symbole->shndx == SHN_ABS)
		retv = 'A';
	else if (symbole->shndx == SHN_COMMON)
		retv = 'C';
	else if (h_type == SHT_NOBITS)
		retv = 'B';
	else if (h_type == SHT_PROGBITS)
	{
		if (h_flags & SHF_ALLOC)
		{
			if (h_flags & SHF_WRITE)
				retv = 'D';
			else if (h_flags & SHF_EXECINSTR)
				retv = 'T';
			else
				retv = 'R';
		}
		else
			retv = 'N';
	}
	else if (
		h_type == SHT_FINI_ARRAY	||
		h_type == SHT_INIT_ARRAY	||
		h_type == SHT_DYNAMIC		||
		h_type == SHF_MERGE
	)
		retv = 'D';
	else if (h_flags & SHF_ALLOC && !(h_flags & SHF_WRITE))
		retv = 'R';
	if (retv != '?' && symbole->bind == STB_LOCAL)
		retv = ft_tolower(retv);
	return (retv);
}
