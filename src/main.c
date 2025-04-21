/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:26:32 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:00:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_bool			OPT_EXECUTED = FALSE;

t_bin	init(int ac, char **av)
{
	int	retv;

	retv = parse_opts(ac, av);
	if (retv == BIT_01)
	{
		OPT_EXECUTED = TRUE;
		return (ft_opt_exec_cmd());
	}
	else if (retv != 0)
		return (retv);
	return (retv);
}

t_bin	run(void)
{
	int		retv;
	int		counter;
	char	**target;

	target = sing_get_target();
	counter = 0;
	while (target[counter])
	{
		if ((retv = process_target(target[counter])))
			return (ft_nm_error(retv, target[counter]));
		counter++;
	}
	return (retv);
}

int	main(int ac, char **av)
{
	t_elf_error	retv;

	CHECK_RET(retv, init, ac, av);
	if (OPT_EXECUTED)
		return (retv);
	retv = run();

	free_prog();
	return (retv);
}
