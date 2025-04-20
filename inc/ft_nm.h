/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2025/04/20 22:37:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "libft.h"

# define CHECK_RET(var, func, ...) \
	if ((var = func(__VA_ARGS__))) \
		return (var);

# include <elf.h>

# include <sys/stat.h>
/* fstat()
 */
# include <sys/mman.h>
/* mmap()
 * munmap()
 */

typedef enum	e_error
{
	SUCCESS,
	/** Init target */
	ERR_TARGET_OPEN,
	ERR_TARGET_MAP,
	ERR_TARGET_STAT,
	ERR_TARGET_SIZE,
	/** Elf identification header parsing */
	ERR_IDENT_MAGIC_NUMBER,
	ERR_IDENT_KNOWN_NUMBER,
	ERR_IDENT_CLASS,
	ERR_IDENT_ENDIANESS,
	ERR_IDENT_VERSION,
	ERR_IDENT_ABI,
	ERR_IDENT_ABI_VERSION,
	/** Elf header parsing */
	ERR_CAST_HDR,
	ERR_HDR_TYPE,
	ERR_HDR_MACHINE,
	ERR_EHDR_VERSION,
	/** Elf Symbole parsing*/
	WARN_SYM_SKIPPED,
	WRONG_SHNUM,
	WRONG_SHOFF,
	NOT_FOUND_SYMTAB,
}	t_error;

typedef struct	s_id_str
{
	t_int32		id;
	char		*str;
}	t_id_str;

typedef struct	s_elf_hdr_ident
{
	t_bool	good_magic_number;
	t_uint8	endianess;
	t_uint8	version;
	t_uint8	abi;
	t_uint8	abi_version;
	t_bool	padding;
}	t_elf_hdr_ident;

# include "ft_nm_e_hdr.h"
# include "ft_nm_s_hdr.h"
# include "ft_nm_sym.h"
# include "ft_nm_str.h"

typedef struct s_sym
{
	t_sym_value		value;
	t_sym_size		size;
	t_sym_shndx		shndx;
	t_sym_info		info;
	t_sym_info		bind;
	t_sym_info		type;
	t_elf_shdr		*shdr;
	t_eh_flags		shdr_flags;
	char			*shdr_name;
	char			str_type;
	char			*name;
}	t_sym;

typedef struct	s_nm
{
	char*				file_path;
	char*				file_ptr;
	struct stat			stat;
	t_elf_hdr_ident		e_ident;
	t_elf_ehdr			e_hdr;
	t_elf_shdr*			s_hdrs;
	char**				s_hdrs_name;
	int					sym_nb;
	t_sym*				syms;
}	t_nm;


# define	ELF_FMT_NB					"%-8d (%#x)"

# define	ELF_MAGIC_NUMBER			0x7f454c46

typedef int	(t_compare_func)(char *a, char *b);

/* ########################################################################## */
/* FILES */
/* ##### */

// data/free.c

void			free_target(void);
void			free_prog(void);

// data/parsing/cmd/help.c

void			help_header(void);
void			help_part_1(void);
void			help_footer(void);
t_bin			help(void);

// data/parsing/cmd/usage.c

t_bin			usage(void);

// data/parsing/parse.c

t_bin			parse_opts(int ac, char **av);

// data/parsing/post_parsing/post_parse_main.c

t_bin			post_parse_main(void);

// data/parsing/post_parsing/post_parse_target_files.c

t_error			post_parse_target(void);

// data/singleton/target.c

void			sing_init_target_assign_value(char **target, t_opts *opts);
char			**sing_init_target(void);
char			**sing_get_target(void);

// error.c

t_error			ft_nm_error(t_error retv, char *target);

// main.c

t_bin			init(int ac, char **av);
t_bin			run(void);
int				main(int ac, char **av);

// target/e_hdr/attr/entry.c

t_eh_entry		get_e_hdr_entry(t_elf_ehdr *e_hdr);
t_error			check_e_hdr_entry(t_elf_ehdr *e_hdr);

// target/e_hdr/attr/flags.c

t_eh_flags		get_e_hdr_flags(t_elf_ehdr *e_hdr);
t_error			check_e_hdr_flags(t_elf_ehdr *e_hdr);

// target/e_hdr/attr/header_size.c

t_eh_ehsize		get_e_hdr_ehsize(t_elf_ehdr *e_hdr);
t_error			check_e_hdr_ehsize(t_elf_ehdr *e_hdr);

// target/e_hdr/attr/machine.c

t_eh_machine	get_e_hdr_machine(t_elf_ehdr *e_hdr);
t_error			check_e_hdr_machine(t_elf_ehdr *e_hdr);

// target/e_hdr/attr/phoff.c

t_eh_entry		get_e_hdr_phoff(t_elf_ehdr *e_hdr);
t_error			check_e_hdr_phoff(t_elf_ehdr *e_hdr);

// target/e_hdr/attr/prog_header_num.c

t_eh_phentsize	get_e_hdr_phentsize(t_elf_ehdr *e_hdr);
t_error			check_e_hdr_phentsize(t_elf_ehdr *e_hdr);

// target/e_hdr/attr/prog_header_size.c

t_eh_phnum		get_e_hdr_phnum(t_elf_ehdr *e_hdr);
t_error			check_e_hdr_phnum(t_elf_ehdr *e_hdr);

// target/e_hdr/attr/sect_header_num.c

t_eh_shnum		get_e_hdr_shnum(t_elf_ehdr *e_hdr);
t_error			check_e_hdr_shnum(t_elf_ehdr *e_hdr);

// target/e_hdr/attr/sect_header_size.c

t_eh_shentsize	get_e_hdr_shentsize(t_elf_ehdr *e_hdr);
t_error			check_e_hdr_shentsize(t_elf_ehdr *e_hdr);

// target/e_hdr/attr/sect_header_txt_index.c

t_eh_shstrndx	get_e_hdr_shstrndx(t_elf_ehdr *e_hdr);
t_error			check_e_hdr_shstrndx(t_elf_ehdr *e_hdr);

// target/e_hdr/attr/shoff.c

t_eh_shoff		get_e_hdr_shoff(t_elf_ehdr *e_hdr);
t_error			check_e_hdr_shoff(t_elf_ehdr *e_hdr);

// target/e_hdr/attr/type.c

t_eh_type		get_e_hdr_type(t_elf_ehdr *e_hdr);
t_error			check_e_hdr_type(t_elf_ehdr *e_hdr);

// target/e_hdr/attr/version.c

t_eh_type		get_e_hdr_version(t_elf_ehdr *e_hdr);
t_error			check_e_hdr_version(t_elf_ehdr *e_hdr);

// target/e_hdr/cast.c

t_error			cast_e_hdr(char *file_ptr, t_elf_ehdr *e_hdr);

// target/e_hdr/check.c

t_bool			is_good_e_hdr(t_elf_ehdr *e_hdr);

// target/e_hdr/read.c

t_error			read_e_hdr(char *file_ptr, t_elf_ehdr *e_hdr);

// target/e_ident/check_padding.c

t_error			check_e_ident_padding(char *file_ptr, t_elf_hdr_ident *elf_hdr);

// target/e_ident/read.c

t_error			read_e_ident(char *file_ptr, t_elf_hdr_ident *e_ident);

// target/e_ident/read_abi.c

t_error			read_e_ident_abi(char *file_ptr, t_elf_hdr_ident *elf_hdr);

// target/e_ident/read_abi_version.c

t_error			read_e_ident_abi_version(char *file_ptr, t_elf_hdr_ident *elf_hdr);

// target/e_ident/read_class.c

t_error			read_e_ident_class(char *file_ptr);

// target/e_ident/read_endianess.c

t_error			read_e_ident_endianess(char *file_ptr, t_elf_hdr_ident *e_ident);

// target/e_ident/read_mag.c

t_error			read_e_ident_known_mag(int magic_number);
t_error			read_e_ident_mag(char *file_ptr, t_elf_hdr_ident *e_ident);

// target/e_ident/read_version.c

t_error			read_e_ident_version(char *file_ptr, t_elf_hdr_ident *e_ident);

// target/init.c

t_error			init_target(char *target, t_nm *main);

// target/map.c

t_error			map_target(int fd, t_int32 size, char **ptr);

// target/open.c

t_error			open_target(char *target, int *fd);

// target/process.c

void			free_process(t_nm main);
t_error			process_target(char *target);

// target/read_shstr.c

t_error			read_s_shstr(t_nm *main);

// target/s_hdr/attr/addr.c

t_sh_addr		get_s_hdr_addr(t_elf_shdr *s_hdr);
t_error			check_s_hdr_addr(t_elf_shdr *s_hdr);

// target/s_hdr/attr/align.c

t_sh_align		get_s_hdr_align(t_elf_shdr *s_hdr);
t_error			check_s_hdr_align(t_elf_shdr *s_hdr);

// target/s_hdr/attr/entsize.c

t_sh_entsize	get_s_hdr_entsize(t_elf_shdr *s_hdr);
t_error			check_s_hdr_entsize(t_elf_shdr *s_hdr);

// target/s_hdr/attr/flags.c

t_sh_type		get_s_hdr_flags(t_elf_shdr *s_hdr);
t_error			check_s_hdr_flags(t_elf_shdr *s_hdr);

// target/s_hdr/attr/info.c

t_sh_info		get_s_hdr_info(t_elf_shdr *s_hdr);
t_error			check_s_hdr_info(t_elf_shdr *s_hdr);

// target/s_hdr/attr/link.c

t_sh_link		get_s_hdr_link(t_elf_shdr *s_hdr);
t_error			check_s_hdr_link(t_elf_shdr *s_hdr);

// target/s_hdr/attr/name.c

t_sh_name		get_s_hdr_name(t_elf_shdr *s_hdr);
t_error			check_s_hdr_name(t_elf_shdr *s_hdr);

// target/s_hdr/attr/offset.c

t_sh_offset		get_s_hdr_offset(t_elf_shdr *s_hdr);
t_error			check_s_hdr_offset(t_elf_shdr *s_hdr);

// target/s_hdr/attr/size.c

t_sh_size		get_s_hdr_size(t_elf_shdr *s_hdr);
t_error			check_s_hdr_size(t_elf_shdr *s_hdr);

// target/s_hdr/attr/type.c

t_sh_type		get_s_hdr_type(t_elf_shdr *s_hdr);
t_error			check_s_hdr_type(t_elf_shdr *s_hdr);

// target/s_hdr/cast.c

t_error			cast_s_hdr(char *file_ptr, t_elf_shdr *s_hdr);

// target/s_hdr/check.c

t_bool			is_good_s_hdr(t_elf_shdr *s_hdr);

// target/s_hdr/free.c


// target/s_hdr/get_section.c

int				get_section_index_byname(t_nm *main, char *name);
t_elf_shdr		*get_section_header_byname(t_nm *main, char *name);
t_elf_shdr		*get_section_header_byndx(t_nm *main, t_eh_shstrndx ndx);
char			*get_section_str(t_nm *main, char *name, int at);
char			*get_section_name_byndx(t_nm *main, t_eh_shstrndx ndx);

// target/s_hdr/reads.c

t_error			check_s_hdrs(t_nm *main);
t_error			read_s_hdrs_struct(t_nm *main);
t_error			read_s_hdrs_name(t_nm *main);
t_error			read_s_hdrs(t_nm *main);

// target/stat.c

t_error			get_stat(int fd, struct stat *stat);

// target/sym/attr/info.c

t_sym_info		get_sym_info(t_elf_sym *sym);
t_error			check_sym_info(t_elf_sym *sym);

// target/sym/attr/name.c

t_sym_name		get_sym_name(t_elf_sym *sym);
t_error			check_sym_name(t_elf_sym *sym);

// target/sym/attr/other.c

t_sym_other		get_sym_other(t_elf_sym *sym);
t_error			check_sym_other(t_elf_sym *sym);

// target/sym/attr/shndx.c

t_sym_shndx		get_sym_shndx(t_elf_sym *sym);
t_error			check_sym_shndx(t_elf_sym *sym);

// target/sym/attr/size.c

t_sym_size		get_sym_size(t_elf_sym *sym);
t_error			check_sym_size(t_elf_sym *sym);

// target/sym/attr/value.c

t_sym_value		get_sym_value(t_elf_sym *sym);
t_error			check_sym_value(t_elf_sym *sym);

// target/sym/cast.c

t_error			cast_sym(char *file_ptr, t_elf_sym *sym);

// target/sym/check.c

t_bool			is_good_sym(t_elf_sym *sym);

// target/sym/ft_stralnumcmp.c

int				ft_stralnumcasecmp(char *s1, char *s2);

// target/sym/print.c

t_bool			sym_should_print_value(t_sym *symbole);
void			print_sym_value(t_sym *symbole);
void			print_sym_type(char type);
void			print_sym_name(t_sym *symbole);
t_bool			is_sym_debug(t_sym *symbole, t_nm *main);
void			print_syms_sort(t_nm *main);
t_error			print_syms(t_nm *main);

// target/sym/read.c

void			check_sym(t_elf_sym sym);
t_error			read_sym(t_nm *main, t_sym *symbole);
t_error			read_syms_loop(t_nm *main);
t_error			read_syms(t_nm *main);

// target/sym/sort.c

int				compare_sym_name(const void *sym_a, const void *sym_b);
int				compare_sym_value(const void *sym_a, const void *sym_b);
int				compare_sym_name_rev(const void *sym_a, const void *sym_b);
int				compare_sym_value_rev(const void *sym_a, const void *sym_b);
void			sort_syms(t_sym *begin, t_size n, t_sort_comp comp);

// target/sym/type.c

char			get_sym_type(t_sym *symbole);

/* ########################################################################## */

#endif // FT_NM_H
