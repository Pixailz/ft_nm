# SRCS
SRC_C := data/free.c \
		 data/parsing/cmd/help.c \
		 data/parsing/cmd/usage.c \
		 data/parsing/parse.c \
		 data/parsing/post_parsing/post_parse_main.c \
		 data/parsing/post_parsing/post_parse_target_files.c \
		 data/singleton/target.c \
		 error.c \
		 main.c \
		 target/e_hdr/attr/entry.c \
		 target/e_hdr/attr/flags.c \
		 target/e_hdr/attr/header_size.c \
		 target/e_hdr/attr/machine.c \
		 target/e_hdr/attr/phoff.c \
		 target/e_hdr/attr/prog_header_num.c \
		 target/e_hdr/attr/prog_header_size.c \
		 target/e_hdr/attr/sect_header_num.c \
		 target/e_hdr/attr/sect_header_size.c \
		 target/e_hdr/attr/sect_header_txt_index.c \
		 target/e_hdr/attr/shoff.c \
		 target/e_hdr/attr/type.c \
		 target/e_hdr/attr/version.c \
		 target/e_hdr/cast.c \
		 target/e_hdr/check.c \
		 target/e_hdr/read.c \
		 target/e_ident/check_padding.c \
		 target/e_ident/read.c \
		 target/e_ident/read_abi.c \
		 target/e_ident/read_abi_version.c \
		 target/e_ident/read_class.c \
		 target/e_ident/read_endianess.c \
		 target/e_ident/read_mag.c \
		 target/e_ident/read_version.c \
		 target/init.c \
		 target/map.c \
		 target/open.c \
		 target/process.c \
		 target/read_shstr.c \
		 target/s_hdr/attr/addr.c \
		 target/s_hdr/attr/align.c \
		 target/s_hdr/attr/entsize.c \
		 target/s_hdr/attr/flags.c \
		 target/s_hdr/attr/info.c \
		 target/s_hdr/attr/link.c \
		 target/s_hdr/attr/name.c \
		 target/s_hdr/attr/offset.c \
		 target/s_hdr/attr/size.c \
		 target/s_hdr/attr/type.c \
		 target/s_hdr/cast.c \
		 target/s_hdr/check.c \
		 target/s_hdr/free.c \
		 target/s_hdr/get_section.c \
		 target/s_hdr/reads.c \
		 target/stat.c \
		 target/sym/attr/info.c \
		 target/sym/attr/name.c \
		 target/sym/attr/other.c \
		 target/sym/attr/shndx.c \
		 target/sym/attr/size.c \
		 target/sym/attr/value.c \
		 target/sym/cast.c \
		 target/sym/check.c \
		 target/sym/ft_stralnumcmp.c \
		 target/sym/print.c \
		 target/sym/read.c \
		 target/sym/sort.c \
		 target/sym/type.c

SRC_C				:= $(addprefix $(SRC_DIR)/,$(SRC_C))

CFLAGS				+= -DPROG_NAME='"$(TARGET)"'

# OBJ
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
OBJ_C_NB			:= $(words $(OBJ_C))
OBJ_C_NB_LEN		:= $(shell printf "$(OBJ_C_NB)" | wc -c)
