/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:33:57 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 16:43:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"


int	compare_sym_name(const void *sym_a, const void *sym_b)
{
	return (ft_strcmp(((t_sym *)sym_a)->name, ((t_sym *)sym_b)->name));
}

int	compare_sym_value(const void *sym_a, const void *sym_b)
{
	t_sym	*sa;
	t_sym	*sb;
	t_bool	ta;
	t_bool	tb;

	sa = (t_sym *)sym_a;
	sb = (t_sym *)sym_b;
	ta = !sym_should_print_value(sa);
	tb = !sym_should_print_value(sb);
	if (ta && tb)
		return (ft_strcmp(sa->name, sb->name));
	else if (ta)
		return (-1);
	else if (tb)
		return (1);

	if (sa->value == sb->value)
		return (ft_strcmp(sa->name, sb->name));
	return (sa->value > sb->value);
}


int	compare_sym_name_rev(const void *sym_a, const void *sym_b)
{
	return (compare_sym_name(sym_b, sym_a));
}

int	compare_sym_value_rev(const void *sym_a, const void *sym_b)
{
	return (compare_sym_value(sym_b, sym_a));
}

#include <string.h>

void	sort_syms(t_sym *begin, t_size n, t_sort_comp comp)
{
	qsort(begin, n, sizeof(t_sym), comp);
	// ft_qsort(begin, n, sizeof(t_sym), comp);
}