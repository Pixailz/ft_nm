/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_version.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 08:42:14 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/07 15:15:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

# define ELF_NB_FILE_VERSION	1

t_id_str FILE_VERSION[ELF_NB_FILE_VERSION] = {
	{EV_CURRENT , "Current"},
};

t_error read_e_ident_version(char *file_ptr, t_elf_hdr_ident *e_ident)
{
	int		counter;
	char	ptr;

	ptr = *(file_ptr + EI_VERSION);
	counter = 0;
	while (counter < ELF_NB_FILE_VERSION)
	{
		if (ptr == FILE_VERSION[counter].id)
		{
			ft_pdeb(ELF_STR_EHDR_IDENT_VERSION SEP "%s\n", FILE_VERSION[counter].str);
			e_ident->version = FILE_VERSION[counter].id;
			return (SUCCESS);
		}
		counter++;
	}
	ft_pdeb(ELF_STR_EHDR_IDENT_VERSION SEP "Unknown\n");
	return (ERR_IDENT_VERSION);
}
