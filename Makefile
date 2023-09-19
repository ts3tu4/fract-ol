# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnanke <mnanke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 18:03:45 by mnanke            #+#    #+#              #
#    Updated: 2023/09/19 18:11:34 by mnanke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol.h

SRCS = main.c\
		check_input/check_input.c

CC = cc

HEAD_FILE = fractol.h

CFLAGS = -Wall -Wextra -Werror -g

OBJS = $(SRCS:.c=.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	cc -o $(NAME)  $(OBJS)
$(OBJS): %.o: %.c $(HEAD_FILE)
	$(CC) $(CFLAGS) -c $< -o

clean:
	rm -rf $(OBJS) $(OBJSDIR_DEBUG)

fclean: clean
	rm -rf $(NAME) $(NAME_DEBUG)

re:fclean all
	

.PHONY: all clean fclean re