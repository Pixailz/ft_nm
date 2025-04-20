/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:28:13 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 21:34:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	free_process(t_nm main)
{
	if (main.file_ptr)
		munmap(main.file_ptr, main.stat.st_size);
	if (main.s_hdrs)
		free(main.s_hdrs);
	if (main.s_hdrs_name)
		free(main.s_hdrs_name);
	if (main.syms)
		free(main.syms);
}

/**
 * 1. opening and mapping the file with init_target()
 * 2. reading the ELF header identification with read_e_ident()
 * 3. reading the ELF header with read_e_hdr()
 * 4. reading section header
 */
t_error	process_target(char *target)
{
	t_nm	main;
	t_error	retv;

	ft_pdeb(ELF_STR_EHDR SEP "%s\n", target);
	ft_bzero(&main, sizeof(t_nm));
	CHECK_RET(retv, init_target, target, &main);
	CHECK_RET(retv, read_e_ident, main.file_ptr, &main.e_ident);
	if (main.stat.st_size <= 0x80)
		return (ERR_TARGET_SIZE);
	CHECK_RET(retv, read_e_hdr, main.file_ptr, &main.e_hdr);
	CHECK_RET(retv, read_s_hdrs, &main);
	if ((retv = read_syms(&main)))
	{
		free_process(main);
		return (retv);
	}
	CHECK_RET(retv, print_syms, &main);
	free_process(main);
	return (retv);
}