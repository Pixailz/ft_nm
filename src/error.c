/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:55:27 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 22:14:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	ft_nm_error_too_short(char *target)
{
	ft_perr("%s: %s: file too short\n", PROG_NAME, target);
}

static void	ft_nm_error_file_format(char *target)
{
	ft_perr("%s: %s: file format not recognized\n", PROG_NAME, target);
}

static void	ft_nm_error_no_sym(char *target)
{
	ft_perr("%s: %s: no symbols\n", PROG_NAME, target);
}

t_error ft_nm_error(t_error retv, char *target)
{
	ft_pdeb("Return value from process {%d}\n", retv);
	switch (retv)
	{
		case (WRONG_SHOFF):
		case (ERR_TARGET_SIZE):
			ft_nm_error_too_short(target);
			/* fallthrough */
		case (ERR_IDENT_CLASS):
		case (ERR_IDENT_ENDIANESS):
		case (ERR_IDENT_MAGIC_NUMBER):
		case (ERR_IDENT_VERSION):
		case (WRONG_SHNUM):
			ft_nm_error_file_format(target);
			return (1);

		case (ERR_IDENT_KNOWN_NUMBER):
		case (NOT_FOUND_SYMTAB):
		case (ERR_TARGET_OPEN):
		case (ERR_HDR_TYPE):
		case (ERR_EHDR_VERSION):
		case (ERR_HDR_MACHINE):
			ft_nm_error_no_sym(target);
			return (0);

		case (ERR_TARGET_MAP):
			return (1);

		default:
			return (retv);
	}
}