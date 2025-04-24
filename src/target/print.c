/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:54:21 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/25 00:12:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

extern t_uint8		NM_CLASS;

t_bool sym_should_print_value(t_sym *symbole)
{
	t_bool	print_value;

	print_value = TRUE;
	switch(symbole->type)
	{
		case('a'):
		case('A'):
		case('b'):
		case('B'):
		case('d'):
		case('D'):
		case('n'):
		case('N'):
		case('r'):
		case('R'):
		case('t'):
		case('T'):
		case('V'):
		case('W'):
			print_value = TRUE;
			break;

		case('U'):
		case('w'):
		case('v'):
			print_value = FALSE;
			break;
	}
	return (print_value);
}

void	print_sym_value(t_sym *symbole)
{
	if (sym_should_print_value(symbole))
	{
		if (NM_CLASS == ELFCLASS64)
			ft_printf("%016x ", symbole->view.get_value(&symbole->view));
		else
			ft_printf("%08x ", symbole->view.get_value(&symbole->view));
	}
	else
	{
		if (NM_CLASS == ELFCLASS64)
			ft_printf("%16s ", "");
		else
			ft_printf("%8s ", "");
	}
}

void	print_sym_type(char type)
{
	ft_printf("%c ", type);
}

void	print_sym_name(t_sym *symbole)
{
	ft_printf("%s\n", symbole->name);
}

t_bool	is_sym_debug(t_sym *symbole, t_elfbin *bin)
{
	switch (symbole->type)
	{
		case('a'):
		{
			if (!symbole->view.get_value(&symbole->view))
				return (TRUE);
		}
	}
	for (int i = 0; bin->s_hdrs_name[i]; i++)
	{
		if (ft_strcmp(bin->s_hdrs_name[i], symbole->name) == 0)
			return (TRUE);
	}
	return (FALSE);
}

void	print_syms_sort(t_elfbin *bin)
{
	if (!ft_is_optpresent("no-sort"))
	{

		if (ft_is_optpresent("numeric-sort"))
		{
			if (ft_is_optpresent("reverse-sort"))
				sort_syms(bin->syms, bin->sym_nb, compare_sym_value_rev);
			else
				sort_syms(bin->syms, bin->sym_nb, compare_sym_value);
		}
		else
		{
			if (ft_is_optpresent("reverse-sort"))
				sort_syms(bin->syms, bin->sym_nb, compare_sym_name_rev);
			else
				sort_syms(bin->syms, bin->sym_nb, compare_sym_name);
		}
	}
	else
	{
		if (ft_is_optpresent("numeric-sort"))
		{
			if (ft_is_optpresent("reverse-sort"))
				sort_syms(bin->syms, bin->sym_nb, compare_sym_value_rev);
			else
				sort_syms(bin->syms, bin->sym_nb, compare_sym_value);
		}
	}
}

t_elf_error	print_syms(t_elfbin *bin)
{
	int		counter;
	t_sym	*symbole;
	t_bool	display_all;
	t_bool	display_global_only;
	t_bool	display_undefined_only;

	display_all = FALSE;
	if (ft_is_optpresent("debug-syms"))
		display_all = TRUE;
	print_syms_sort(bin);
	counter = 0;
	display_global_only = ft_is_optpresent("extern-only");
	display_undefined_only = ft_is_optpresent("undefined-only");
	while (counter < bin->sym_nb)
	{
		symbole = &bin->syms[counter++];
		if (!display_all && is_sym_debug(symbole, bin))
			continue;
		if (display_global_only && symbole->bind == STB_LOCAL)
			continue;
		if (
			display_undefined_only &&
			symbole->view.get_shndx(&symbole->view) != SHN_UNDEF
		)
			continue;

		print_sym_value(symbole);
		print_sym_type(symbole->type);
		print_sym_name(symbole);
	}
	return (SUCCESS);
}