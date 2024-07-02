/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 06:02:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/07/02 22:44:45 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_bin	usage(void)
{
	ft_dprintf(1, "\
Usage: %s [--verbose] [--help] [--usage] [--version] ARGS ...\n", PROG_NAME);
	return (0);
}
