/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 19:33:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

extern t_uint8	NM_CLASS;

t_sym_size	get_sym_size(t_elf_sym *sym)
{
	t_sym_size	size;

	if (is_good_sym(sym))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		size = sym->_64->st_size;
	else if (NM_CLASS == ELFCLASS32)
		size = sym->_32->st_size;
	return (size);
}

t_error	check_sym_size(t_elf_sym *sym)
{
	t_sym_size	size;
	char		*fmt;

	size = get_sym_size(sym);
	fmt = ELF_STR_SYM_SIZE SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, size);
	return (SUCCESS);
}
