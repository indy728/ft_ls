# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcornea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/01 20:44:23 by alcornea          #+#    #+#              #
#    Updated: 2017/05/01 20:44:24 by alcornea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC =	main.c \
 			read_arguments.c \
			list.c \
			read_dir.c \
			get_info.c \
			check_permissions.c \
			check_time.c \
		  insert_elem.c \
			print.c \
			sort_elem.c \

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
			make -C libft
			gcc -g -o $(NAME) $(FLAGS) $(SRC) -lft -L./libft

clean:
			make clean -C libft

fclean:
			make fclean -C libft
			rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
