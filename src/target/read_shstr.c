/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:19:51 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/07 17:41:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

// char	*get_s_str_at(char *file_ptr, t_sh_offset offset)
// {
// 	return ((char *)(s_hdr + offset));
// }

t_error	read_s_shstr(t_nm *main)
{
	t_eh_shstrndx	shstrndx;
	t_elf_shdr		shstr_hdr;
	t_sh_offset		shstr_offset;
	t_sh_name		shstr_name_ndx;
	char			*shstr_name;

	shstrndx = get_e_hdr_shstrndx(&main->e_hdr);
	shstr_hdr = main->s_hdrs[shstrndx];
	shstr_offset = get_s_hdr_offset(&shstr_hdr);
	shstr_name_ndx = get_s_hdr_name(&shstr_hdr);
	shstr_name = main->file_ptr + shstr_offset + shstr_name_ndx;
	ft_printf("shstrndx:            %d\n", shstrndx);
	ft_printf("shstr_offset:        %d\n", shstr_offset);
	ft_printf("s_shstr.sh_name_ndx: %d\n", shstr_name_ndx);
	ft_printf("s_shstr.sh_name:     %s\n", shstr_name);
	return (SUCCESS);
}