/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:25:44 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 21:19:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static t_elf_shdr		*sym_hdr;
static t_sh_offset		sym_offset;
static t_sh_entsize		sym_entsize;
static t_sh_align		sym_align;
t_elf_sym				sym;

/*
typedef struct s_sym
{
	t_sym_value		value;
	t_sym_size		size;
	t_sym_shndx		shndx;
	t_sym_info		info;
	char			type;
	char			*name;
}	t_sym;
*/

void	check_sym(t_elf_sym sym)
{
	check_sym_name(&sym);
	check_sym_value(&sym);
	check_sym_size(&sym);
	check_sym_info(&sym);
	check_sym_other(&sym);
	check_sym_shndx(&sym);
	ft_pdeb("\n");
}

t_error read_sym(t_nm *main, t_sym *symbole)
{
	symbole->bind = ELF_ST_BIND(symbole->info);
	symbole->type = ELF_ST_TYPE(symbole->info);
	symbole->shndx = get_sym_shndx(&sym);
	symbole->name = get_section_str(main, ".strtab", get_sym_name(&sym));
	symbole->shdr = get_section_header_byndx(main, symbole->shndx);
	symbole->shdr_name = get_section_name_byndx(main, symbole->shndx);
	if (ft_strncmp(symbole->name, "", 1) == 0 && symbole->shdr_name)
		symbole->name = symbole->shdr_name;

	ft_pdeb(
		"sym [%s]{.type %d, bind %d, hdr {name %s, type %d, flags %d}}\n",
		symbole->name, symbole->type, symbole->bind, symbole->shdr_name, get_s_hdr_type(symbole->shdr), get_s_hdr_flags(symbole->shdr)
	);

	symbole->value = get_sym_value(&sym);
	symbole->type = get_sym_type(symbole);
	return (SUCCESS);
}

t_error	read_syms_loop(t_nm *main)
{
	int			index;
	int			padding;
	int			counter;

	counter = 0;
	index = sym_offset + sym_entsize;
	while (counter < main->sym_nb)
	{
		cast_sym(main->file_ptr + index, &sym);
		index += sym_entsize;
		if ((padding = index % sym_align))
			index += sym_align - padding;
		ft_bzero(&main->syms[counter], sizeof(t_sym));
		main->syms[counter].info = get_sym_info(&sym);
		read_sym(main, &main->syms[counter]);
		check_sym(sym);
		counter++;
	}
	return (SUCCESS);
}

t_error	read_syms(t_nm *main)
{
	sym_hdr = get_section_header_byname(main, ".symtab");
	if (sym_hdr == FT_NULL)
		return (NOT_FOUND_SYMTAB);
	sym_offset = get_s_hdr_offset(sym_hdr);
	sym_entsize = get_s_hdr_entsize(sym_hdr);
	sym_align = get_s_hdr_align(sym_hdr);
	main->sym_nb = get_s_hdr_size(sym_hdr) / sym_entsize;
	main->sym_nb--;
	ft_pdeb("sym_nb %d\n", main->sym_nb - 1);
	main->syms = (t_sym *)ft_calloc(sizeof(t_sym), main->sym_nb + 1);
	return (read_syms_loop(main));
}
