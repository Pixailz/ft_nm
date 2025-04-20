/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_section.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:25:44 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/15 17:02:23 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int	get_section_index_byname(t_nm *main, char *name)
{
	t_eh_shnum	shnum = -1;
	int			idx;

	shnum = get_e_hdr_shnum(&main->e_hdr);
	idx = 0;
	while (idx < shnum)
	{
		if (ft_strcmp(main->s_hdrs_name[idx], name) == 0)
			return (idx);
		idx++;
	}
	return (-1);
}

t_elf_shdr	*get_section_header_byname(t_nm *main, char *name)
{
	int			idx;

	idx = get_section_index_byname(main, name);
	if (idx == -1)
		return (FT_NULL);
	return (&main->s_hdrs[idx]);
}

t_elf_shdr	*get_section_header_byndx(t_nm *main, t_eh_shstrndx ndx)
{
	t_eh_shnum	shnum = -1;

	shnum = get_e_hdr_shnum(&main->e_hdr);
	if (ndx >= shnum)
		return (FT_NULL);
	return (&main->s_hdrs[ndx]);
}

char	*get_section_str(t_nm *main, char *name, int at)
{
	t_elf_shdr	*shtab;

	shtab = get_section_header_byname(main, name);
	if (shtab == FT_NULL)
		return (FT_NULL);
	return (main->file_ptr + get_s_hdr_offset(shtab) + at);
}

char	*get_section_name_byndx(t_nm *main, t_eh_shstrndx ndx)
{
	t_eh_shnum	shnum = -1;

	shnum = get_e_hdr_shnum(&main->e_hdr);
	if (ndx >= shnum)
		return (FT_NULL);
	return (main->s_hdrs_name[ndx]);
}