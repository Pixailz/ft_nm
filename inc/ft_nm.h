/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/21 14:46:15 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "libft.h"

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

// error.c

t_elf_error	ft_nm_error(t_elf_error retv, char *target);

// main.c

t_bin		init(int ac, char **av);
t_bin		run(void);
int			main(int ac, char **av);

// target/init.c

t_elf_error	init_target(char *target, t_elfbin *main);

// target/map.c

t_elf_error	map_target(int fd, t_int32 size, char **ptr);

// target/open.c

t_elf_error	open_target(char *target, int *fd);

// target/process.c

void		free_process(t_elfbin main);
t_elf_error	process_target(char *target);

// target/read_shstr.c

t_elf_error	read_s_shstr(t_elfbin *main);

// target/stat.c

t_elf_error	get_stat(int fd, struct stat *stat);

// target/sym/attr/info.c

t_sym_info	ft_get_sym_info(t_elf_sym *sym);
t_elf_error	ft_check_sym_info(t_elf_sym *sym);

// target/sym/attr/name.c

t_sym_name	ft_get_sym_name(t_elf_sym *sym);
t_elf_error	ft_check_sym_name(t_elf_sym *sym);

// target/sym/attr/other.c

t_sym_other	ft_get_sym_other(t_elf_sym *sym);
t_elf_error	ft_check_sym_other(t_elf_sym *sym);

// target/sym/attr/shndx.c

t_sym_shndx	ft_get_sym_shndx(t_elf_sym *sym);
t_elf_error	ft_check_sym_shndx(t_elf_sym *sym);

// target/sym/attr/size.c

t_sym_size	ft_get_sym_size(t_elf_sym *sym);
t_elf_error	ft_check_sym_size(t_elf_sym *sym);

// target/sym/attr/value.c

t_sym_value	ft_get_sym_value(t_elf_sym *sym);
t_elf_error	ft_check_sym_value(t_elf_sym *sym);

// target/sym/cast.c

t_elf_error	cast_sym(char *file_ptr, t_elf_sym *sym);

// target/sym/check.c

t_bool		is_good_sym(t_elf_sym *sym);

// target/sym/ft_stralnumcmp.c

int			ft_stralnumcasecmp(char *s1, char *s2);

// target/sym/print.c

t_bool		sym_should_print_value(t_sym *symbole);
void		print_sym_value(t_sym *symbole);
void		print_sym_type(char type);
void		print_sym_name(t_sym *symbole);
t_bool		is_sym_debug(t_sym *symbole, t_elfbin *main);
void		print_syms_sort(t_elfbin *main);
t_elf_error	print_syms(t_elfbin *main);

// target/sym/read.c

void		ft_check_sym(t_elf_sym sym);
t_elf_error	ft_read_sym(t_elfbin *main, t_sym *symbole);
t_elf_error	ft_read_syms_loop(t_elfbin *main);
t_elf_error	ft_read_syms(t_elfbin *main);

// target/sym/sort.c

int			compare_sym_name(const void *sym_a, const void *sym_b);
int			compare_sym_value(const void *sym_a, const void *sym_b);
int			compare_sym_name_rev(const void *sym_a, const void *sym_b);
int			compare_sym_value_rev(const void *sym_a, const void *sym_b);
void		sort_syms(t_sym *begin, t_size n, t_sort_comp comp);

// target/sym/type.c

char		ft_get_sym_type(t_sym *symbole);

/* ########################################################################## */

#endif // FT_NM_H
