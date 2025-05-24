# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 16:16:34 by mgrandia          #+#    #+#              #
#    Updated: 2025/04/12 16:08:09 by mgrandia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror -g

INC = -I./

SRC = ft_printf.c printf_utils.c ft_uitoa.c decimal_print.c\
      hexa_print.c pointer_print.c text_print.c

GNL_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJDIR = obj

OBJS = $(SRC:%.c=$(OBJDIR)/%.o) $(GNL_SRC:%.c=$(OBJDIR)/%.o)

LIBFT = ./Libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./Libft

$(NAME): $(OBJS) ft_printf.h
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(FLAGS) -c $< -I $(INC) -I./Libft -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS)
	make -C ./Libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./Libft fclean
	
re: fclean all

.PHONY: all clean fclean re

