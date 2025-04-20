/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 19:06:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

extern t_uint8	NM_CLASS;

t_error read_e_hdr(char *file_ptr, t_elf_ehdr *e_hdr)
{
	t_error		retv;

	ft_bzero(e_hdr, sizeof(e_hdr));
	CHECK_RET(retv, cast_e_hdr, file_ptr, e_hdr);
	CHECK_RET(retv, check_e_hdr_type, e_hdr);
	CHECK_RET(retv, check_e_hdr_machine, e_hdr);
	CHECK_RET(retv, check_e_hdr_version, e_hdr);
	CHECK_RET(retv, check_e_hdr_entry, e_hdr);
	CHECK_RET(retv, check_e_hdr_phoff, e_hdr);
	CHECK_RET(retv, check_e_hdr_shoff, e_hdr);
	CHECK_RET(retv, check_e_hdr_flags, e_hdr);
	CHECK_RET(retv, check_e_hdr_ehsize, e_hdr);
	CHECK_RET(retv, check_e_hdr_phentsize, e_hdr);
	CHECK_RET(retv, check_e_hdr_phnum, e_hdr);
	CHECK_RET(retv, check_e_hdr_shentsize, e_hdr);
	CHECK_RET(retv, check_e_hdr_shnum, e_hdr);
	CHECK_RET(retv, check_e_hdr_shstrndx, e_hdr);
	return (SUCCESS);
}
