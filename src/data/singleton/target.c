/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:18:36 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/13 11:56:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	sing_init_target_assign_value(char **target, t_opts *opts)
{
	t_opt_value	*ptr;
	int			counter;

	counter = 0;
	ptr = opts->value;
	while (ptr)
	{
		if (ptr->value)
			target[counter++] = ptr->value;
		ptr = ptr->next;
	}
}

char	**sing_init_target(void)
{
	t_opts		*opts;
	t_size		opts_len;
	char		**retv;

	opts = ft_get_opts(FALSE);
	opts_len = ft_opts_len(opts);
	if (!opts_len)
	{
		retv = (char **)ft_calloc(sizeof(char), 2);
		retv[0] = "a.out";
		return (retv);
	}
	retv = (char **)ft_calloc(opts_len + 1, sizeof(char *));
	sing_init_target_assign_value(retv, opts);
	return (retv);
}

char	**sing_get_target(void)
{
	static char	**target = FT_NULL;

	if (!target)
		target = sing_init_target();
	return (target);
}