/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 16:32:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "libft_binary/elf.h"
# include "libft_print.h"
# include "libft_sort.h"
# include "libft_parsing.h"
# include "libft_check.h"

/* ########################################################################## */
/* FILES */
/* ##### */

// data/free.c

void		free_target(void);
void		free_prog(void);

// data/parsing/cmd/help.c

void		help_header(void);
void		help_part_1(void);
void		help_footer(void);
t_bin		help(void);

// data/parsing/cmd/usage.c

t_bin		usage(void);

// data/parsing/parse.c

t_bin		parse_opts(int ac, char **av);

// data/parsing/post_parsing/post_parse_main.c

t_bin		post_parse_main(void);

// data/parsing/post_parsing/post_parse_target_files.c

t_elf_error	post_parse_target(void);

// data/singleton/target.c

void		sing_init_target_assign_value(char **target, t_opts *opts);
char		**sing_init_target(void);
char		**sing_get_target(void);

// ft_stralnumcmp.c

int			ft_stralnumcasecmp(char *s1, char *s2);

// main.c

t_bin		init(int ac, char **av);
t_bin		run(void);
int			main(int ac, char **av);

// target/error.c

t_elf_error	ft_nm_error(t_elf_error retv, char *target);

// target/print.c

t_bool		sym_should_print_value(t_sym *symbole);
void		print_sym_value(t_sym *symbole);
void		print_sym_type(char type);
void		print_sym_name(t_sym *symbole);
t_bool		is_sym_debug(t_sym *symbole, t_elfbin *bin);
void		print_syms_sort(t_elfbin *bin);
t_elf_error	print_syms(t_elfbin *bin);

// target/process.c

t_elf_error	process_target(char *target);

// target/sort.c

int			compare_sym_name(const void *sym_a, const void *sym_b);
int			compare_sym_value(const void *sym_a, const void *sym_b);
int			compare_sym_name_rev(const void *sym_a, const void *sym_b);
int			compare_sym_value_rev(const void *sym_a, const void *sym_b);
void		sort_syms(t_sym *begin, t_size n, t_sort_comp comp);

/* ########################################################################## */

#endif // FT_NM_H
