/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:38:28 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/18 19:44:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	help_header(void)
{
	usage();
}

void	help_part_1(void)
{
	ft_putendl_fd("\
 List symbols in [file(s)] (a.out by default).\n\
  -?, --help                 Give this help list\n\
      --usage                Give a short usage message\n\
  -V, --version              Print program version\n\
  -n, --numeric-sort         Sort symbols numerically by their addresses, rather\n\
                             than alphabetically by their names.\n\
  -g, --extern-only          Display only external symbols\n\
  -u, --undefined-only       Display only undefined symbols\n\
  -a, --debug-syms           Display debugger-only symbols\n\
  -r, --reverse-sort         Reverse the sense of the sort\n\
  -p, --no-sort              Do not sort the symbols\n\
", 1);
}

void	help_footer(void)
{
	ft_putendl_fd("Report bugs to <pixailz1@gmail.com>.", 1);
}

t_bin	help(void)
{
	help_header();
	help_part_1();
	help_footer();
	return (0);
}
