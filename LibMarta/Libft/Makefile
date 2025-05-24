# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 16:16:34 by mgrandia          #+#    #+#              #
#    Updated: 2025/01/16 16:58:37 by mgrandia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror -g

INC = -I./

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
      ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
      ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
      ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
      ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
      ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
      ft_putnbr_fd.c

BSRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
       ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJDIR = obj

OBJS = $(SRC:%.c=$(OBJDIR)/%.o)
BOBJS = $(BSRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(BOBJS)
	ar rc $(NAME) $(OBJS) $(BOBJS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(FLAGS) -c $< -I $(INC) -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all

bonus: $(OBJS) $(BOBJS)
	ar rc $(NAME) $(OBJS) $(BOBJS)

.PHONY: all clean fclean re
