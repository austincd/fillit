#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adaly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/07 21:02:21 by adaly             #+#    #+#              #
#    Updated: 2017/05/15 17:41:10 by adaly            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME= fillit
SRCS= fillit.c ft_tetrominos.c drafting.c placing.c next.c main.c print.c
LIBFT= libft/*.c
OBJS= fillit.o ft_tetrominos.o drafting.o placing.o next.o main.o print.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all