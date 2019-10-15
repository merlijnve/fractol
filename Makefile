# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-eng <mvan-eng@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/07/19 11:58:17 by mvan-eng       #+#    #+#                 #
#    Updated: 2019/10/15 14:33:42 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror

FILES = main loop_strcmp keys draw img_put calc_iterations hsv_to_int \
draw_line

LIBS = libft/libft.a

SRC = $(FILES:%=srcs/%.c)

all: $(NAME)

$(NAME):
	#cd libft && make
	gcc $(FLAGS) $(SRC) $(LIBS) -L ./minilibx_macos/ -lmlx -framework \
	OpenGL -framework AppKit -g

clean:
	#cd libft && make clean

fclean: clean
	rm -f $(NAME)
	#cd libft && make fclean

re: fclean all
