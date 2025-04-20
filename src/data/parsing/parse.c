/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/18 19:43:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_bin	parse_opts(int ac, char **av)
{
	ft_optadd_cmd(	"help",				'?',	help);
	ft_optadd_cmd(	"usage",			0,		usage);
	ft_optadd(		"no-sort",			'p',	OPT_FLAG);
	ft_optadd(		"debug-syms",		'a',	OPT_FLAG);
	ft_optadd(		"numeric-sort",		'n',	OPT_FLAG);
	ft_optadd(		"extern-only",		'g',	OPT_FLAG);
	ft_optadd(		"undefined-only",	'u',	OPT_FLAG);
	ft_optadd(		"reverse-sort",		'r',	OPT_FLAG);
	ft_optparse(ac, av);
	return (ft_opt_post_parse(post_parse_main));
}
