/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/07 15:15:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_error read_e_ident(char *file_ptr, t_elf_hdr_ident *e_ident)
{
	t_error	retv;

	ft_pdeb(ELF_STR_EHDR_IDENT "\n");
	ft_bzero(e_ident, sizeof(t_elf_hdr_ident));
	CHECK_RET(retv, read_e_ident_mag, file_ptr, e_ident);
	CHECK_RET(retv, read_e_ident_class, file_ptr);
	CHECK_RET(retv, read_e_ident_endianess, file_ptr, e_ident);
	CHECK_RET(retv, read_e_ident_version, file_ptr, e_ident);
	CHECK_RET(retv, read_e_ident_abi, file_ptr, e_ident);
	CHECK_RET(retv, read_e_ident_abi_version, file_ptr, e_ident);
	CHECK_RET(retv, check_e_ident_padding, file_ptr, e_ident);
	return (retv);
}
