# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamartin <xamartin@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 16:31:52 by xamartin          #+#    #+#              #
#    Updated: 2021/02/25 17:12:45 by xamartin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re test no

# VAR
NAME = particule_system
CC = gcc
RM = rm -f

# PATH
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
LIB_PATH = ./external_lib/
INC_PATH = ./includes/ $(LIB_PATH)glfw/include/ $(LIB_PATH)glad/include

# FLAGS
GCC_FLGS = -Wall -Wextra -Werror -o3
GCC_LIBS = -L $(LIB_PATH)/glfw/src -lglfw3 -framework AppKit -framework OpenGL -framework OpenCL -framework IOKit -framework CoreVideo

# FILES
SRC_NAME =	main.c \
			render/clock.c \
			render/events.c \
			render/callback.c \
			render/init/matrix.c \
			render/init/shader.c \
			render/init/graphic.c \
			tools/device_info.c \

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = glfw/src
GLAD = glad/src/glad.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L$(LIB_PATH),$(LIB_NAME))
LIB_GLAD = $(addprefix $(LIB_PATH),$(GLAD))


#RULES
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(GCC_FLGS) $(LIB) $(LIB_GLAD) $(INC) $(OBJ) $(GCC_LIBS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(GCC_FLGS) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

delete:
	$(RM) $(OBJ)
	$(RM) $(NAME)

no: delete all
