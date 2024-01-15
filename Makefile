# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnanke <mnanke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 18:03:45 by mnanke            #+#    #+#              #
#    Updated: 2024/01/02 22:14:58 by mnanke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c\
		mandelbrot.c

CC = cc

HEAD_FILE = fractol.h

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

# .SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
$(OBJS): %.o: %.c $(HEAD_FILE)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:fclean all
	

.PHONY: all clean fclean re