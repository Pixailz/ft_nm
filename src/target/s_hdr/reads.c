/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reads.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 07:42:54 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 20:54:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

extern t_uint8	NM_CLASS;

t_error check_s_hdrs(t_nm *main)
{
	t_eh_shnum	shnum;
	int			counter;
	t_elf_shdr	*s_hdrs;

	shnum = get_e_hdr_shnum(&main->e_hdr);
	counter = 0;
	ft_pdeb(ELF_STR_SHDR "\n");
	while (counter < shnum)
	{
		s_hdrs = &main->s_hdrs[counter];
		ft_pdeb(
			ELF_STR_PAD ELF_STR_LIST "%s (%d)\n",
			main->s_hdrs_name[counter], counter
		);
		check_s_hdr_name(s_hdrs);
		check_s_hdr_type(s_hdrs);
		check_s_hdr_flags(s_hdrs);
		check_s_hdr_addr(s_hdrs);
		check_s_hdr_offset(s_hdrs);
		check_s_hdr_size(s_hdrs);
		check_s_hdr_link(s_hdrs);
		check_s_hdr_info(s_hdrs);
		check_s_hdr_align(s_hdrs);
		check_s_hdr_entsize(s_hdrs);
		ft_pdeb("\n");
		counter++;
	}
	return (SUCCESS);
}

t_error	read_s_hdrs_struct(t_nm *main)
{
	t_eh_shnum		shnum;
	t_eh_shoff		shoff;
	t_eh_shentsize	shentsize;
	int				counter;

	shnum = get_e_hdr_shnum(&main->e_hdr);
	if (!shnum)
		return (WRONG_SHNUM);
	shoff = get_e_hdr_shoff(&main->e_hdr);
	if (shoff >= (t_uint64)main->stat.st_size)
		return (WRONG_SHOFF);
	shentsize = get_e_hdr_shentsize(&main->e_hdr);
	main->s_hdrs = (t_elf_shdr *)ft_calloc(sizeof(t_elf_shdr), shnum);
	counter = 0;
	while (counter < shnum)
	{
		cast_s_hdr(
			main->file_ptr + shoff + (shentsize * counter),
			&main->s_hdrs[counter]
		);
		counter++;
	}
	return (SUCCESS);
}

t_error	read_s_hdrs_name(t_nm *main)
{
	t_eh_shnum		shnum;
	int				counter;
	t_eh_shstrndx	shstrndx;
	t_sh_offset		shstr_offset;
	t_sh_name		shstr_name_ndx;

	shstrndx = get_e_hdr_shstrndx(&main->e_hdr);
	shstr_offset = get_s_hdr_offset(&main->s_hdrs[shstrndx]);
	shnum = get_e_hdr_shnum(&main->e_hdr);
	counter = 0;
	main->s_hdrs_name = (char **)ft_calloc(sizeof(char *), shnum + 1);
	while (counter < shnum)
	{
		shstr_name_ndx = get_s_hdr_name(&main->s_hdrs[counter]);
		main->s_hdrs_name[counter] = main->file_ptr + shstr_offset + shstr_name_ndx;
		counter++;
	}
	return (SUCCESS);
}

t_error read_s_hdrs(t_nm *main)
{
	t_error	retv;

	CHECK_RET(retv, read_s_hdrs_struct, main);
	CHECK_RET(retv, read_s_hdrs_name, main);
	check_s_hdrs(main);
	return (SUCCESS);
}
