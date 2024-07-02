# SRCS
SRC_C := data/parsing/cmd/help.c \
		 data/parsing/cmd/usage.c \
		 data/parsing/parse.c \
		 main.c

SRC_C				:= $(addprefix $(SRC_DIR)/,$(SRC_C))

CFLAGS				+= -DPROG_NAME='"$(TARGET)"'

# OBJ
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
OBJ_C_NB			:= $(words $(OBJ_C))
OBJ_C_NB_LEN		:= $(shell printf "$(OBJ_C_NB)" | wc -c)
