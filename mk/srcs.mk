# SRCS
SRC_C := data/free.c \
		 data/parsing/cmd/help.c \
		 data/parsing/cmd/usage.c \
		 data/parsing/parse.c \
		 data/parsing/post_parsing/post_parse_main.c \
		 data/parsing/post_parsing/post_parse_target_files.c \
		 data/singleton/target.c \
		 ft_stralnumcmp.c \
		 main.c \
		 target/error.c \
		 target/print.c \
		 target/process.c \
		 target/sort.c

SRC_C				:= $(addprefix $(SRC_DIR)/,$(SRC_C))

CFLAGS				+= -DPROG_NAME='"$(TARGET)"'

# OBJ
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
OBJ_C_NB			:= $(words $(OBJ_C))
OBJ_C_NB_LEN		:= $(shell printf "$(OBJ_C_NB)" | wc -c)
