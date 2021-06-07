# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 10:29:48 by erlajoua          #+#    #+#              #
#    Updated: 2021/06/07 10:29:49 by erlajoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

SRCS = main.cpp main_list.cpp main_stack.cpp main_queue.cpp main_vector.cpp main_map.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

COMPILER = clang++

.cpp.o:
	$(COMPILER) ${FLAGS} -c $< -o ${<:.cpp=.o}

$(NAME): $(OBJS)
	${COMPILER} $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
