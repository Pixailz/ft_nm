/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:51:16 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 19:33:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

extern t_uint8	NM_CLASS;

t_sym_name	get_sym_name(t_elf_sym *sym)
{
	t_sym_name	name;

	if (is_good_sym(sym))
		return (0);
	if (NM_CLASS == ELFCLASS64)
		name = sym->_64->st_name;
	else if (NM_CLASS == ELFCLASS32)
		name = sym->_32->st_name;
	return (name);
}

t_error	check_sym_name(t_elf_sym *sym)
{
	t_sym_name	name;
	char		*fmt;

	name = get_sym_name(sym);
	fmt = ELF_STR_SYM_NAME SEP ELF_FMT_NB "\n";
	ft_pdeb(fmt, name);
	return (SUCCESS);
}
