# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:09:13 by dokim2            #+#    #+#              #
#    Updated: 2022/03/31 18:25:42 by dokim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRC		= get_next_line.c get_next_line_utils.c
SRC_B	= get_next_line_bonus.c get_next_line_utils_bonus.c
OBJECT	= $(SRC:.c=.o)
OBJECT_B = $(SRC_B:.c=.o)
INCS	= get_next_line.h
INCS_B	= get_next_line_bonus.h
NAME = get_next_line.a
DO_BONUS = 0
ifeq ($(DO_BONUS), 1)
	OBJECTS = $(OBJECT) $(OBJECT_B) 
else
	OBJECTS = $(OBJECT)
endif

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)
$(NAME) : $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
bonus :
	make DO_BONUS=1
all : $(NAME)
clean :
	rm -f $(OBJECT) $(OBJECT_B)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re bonus