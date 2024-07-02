/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:26:32 by brda-sil          #+#    #+#             */
/*   Updated: 2024/07/02 22:45:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_bin	run(int ac, char **av)
{
	int	ret;

	ret = parse_opts(ac, av);
	if (ret == BIT_01)
		return (ft_opt_exec_cmd());
	else if (ret != 0)
		return (ret);
	return (ret);
}

int	main(int ac, char **av)
{
	char	ret = 0;

	ret = run(ac, av);
	ft_free_opts();
	return (ret);
}
