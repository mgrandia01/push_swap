# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 16:16:34 by mgrandia          #+#    #+#              #
#    Updated: 2025/05/03 14:49:36 by mgrandia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror -g -MMD -MP

INC = -I./

SRC = errors.c simple_numbers.c simple_utils.c list.c positions.c main.c radix.c optimization.c push_swap_utils.c

OBJDIR = obj

OBJS = $(SRC:%.c=$(OBJDIR)/%.o)

LIBFT = ./LibMarta/libftprintf.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./LibMarta

$(NAME): $(OBJS) $(LIBFT) 
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: %.c Makefile| $(OBJDIR)
	$(CC) $(FLAGS) -c $< -I $(INC) -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS)
	make -C ./LibMarta clean

fclean: clean
	rm -rf $(NAME)
	make -C ./LibMarta fclean
	
re: fclean all

.PHONY: all clean fclean re

#dependencies
-include $(ALL_OBJ:.o=.d)
