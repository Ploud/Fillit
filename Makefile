# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 16:51:36 by hben-yah          #+#    #+#              #
#    Updated: 2018/04/03 16:51:38 by hben-yah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit
SRCS	=	main.c \
			fillit.c \
			exception.c \
			reader.c \
			checker.c \
			printer.c
OBJS	=	$(SRCS:.c=.o)
INCL	=	./
LIBR	=	./Libft/libft.a
FLAG	=	-Wall -Wextra -Werror -g

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@make -C ./Libft
			@gcc $(FLAG) $(OBJS) -I $(INCL) $(LIBR) -o $(NAME)

$(OBJS)	: 	$(SRCS)
			@gcc $(FLAG) -c $(SRCS)

clean	:
			@make -C ./Libft clean
			@rm -f $(OBJS)

fclean	:	clean
			@make -C ./Libft fclean
			@rm -f $(NAME)

re		:	fclean all
