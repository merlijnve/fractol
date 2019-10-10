# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-eng <mvan-eng@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/07/19 11:58:17 by mvan-eng       #+#    #+#                 #
#    Updated: 2019/09/30 17:45:12 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror

FILES = main loop_strcmp keypress draw imgpxlput calc_iterations hsv_to_int \
mpress

LIBS = libft/libft.a

SRC = $(FILES:%=srcs/%.c)

all: $(NAME)

$(NAME):
	#cd libft && make
	gcc $(FLAGS) $(SRC) $(LIBS) -L ./minilibx_macos/ -lmlx -framework \
	OpenGL -framework AppKit

clean:
	#cd libft && make clean

fclean: clean
	rm -f $(NAME)
	#cd libft && make fclean

re: fclean all
