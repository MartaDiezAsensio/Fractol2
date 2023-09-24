# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/17 19:20:10 by mdiez-as          #+#    #+#              #
#    Updated: 2023/09/24 15:17:38 by mdiez-as         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# Compiler
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories
SRCDIR	= src
INCDIR	= includes
OBJDIR	= obj

# src / obj files
SRC		= src/main.c \
		  src/window.c \
		  src/image.c \
		  src/mouse.c \
		  src/keyboard.c \
		  src/zoom.c \
		  src/fractal.c \
		  src/palette.c \
		  src/draw.c \
		  src/color.c \
		  src/viewport.c \
		  src/burningship.c  \
		  src/julia.c  \
		  src/mandelbrot.c

#OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
OBJ		= $(patsubst src/%.c, $(OBJDIR)/%.o, $(SRC))

# MinilibX Library
MLX		= MinilibX
MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

# Libft Library
FT		= libft
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft -l pthread


all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean
	rm a.out

re: fclean all
