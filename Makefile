# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 20:50:03 by dokim2            #+#    #+#              #
#    Updated: 2022/10/05 16:06:39 by dokim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

SOLONG_NAME = so_long.a

GET_NEXT_LINE_DIR = ./get_next_line
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx_opengl_20191021
MLX = $(MLX_DIR)/mlx.h

SOLONG_FILE = so_long.c utils.c print_error.c show_map.c img_init.c key_press.c exit_game.c check_direction.c check_map_1darr.c
#SOLONG_BONUS_FILE = bonus/so_long_bonus.c bonus/utils_bonus.c bonus/print_error_bonus.c bonus/show_map_bonus.c bonus/img_init_bonus.c bonus/key_press_bonus.c bonus/exit_game_bonus.c bonus/check_direction_bonus.c

INCS	= so_long.h

DO_BONUS = 0
ifeq ($(DO_BONUS), 1)
	SOLONG_OBJECT = $(SOLONG_BONUS_FILE:.c=.o)
	INCS = ./bonus/so_long_bonus.h
else
	SOLONG_OBJECT = $(SOLONG_FILE:.c=.o)
	INCS = so_long.h
endif

all : $(NAME)

$(NAME) : $(SOLONG_OBJECT) $(GET_NEXT_LINE) $(FT_PRINTF) $(LIBFT) $(INCS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(SOLONG_OBJECT) $(GET_NEXT_LINE) $(FT_PRINTF) $(LIBFT) -L minilibx_opengl_20191021 -lmlx -framework OPENGL -framework Appkit -o $(NAME)

$(GET_NEXT_LINE) :
	make -C $(GET_NEXT_LINE_DIR)

$(FT_PRINTF) : 
	make -C $(FT_PRINTF_DIR)

$(LIBFT) : 
	make -C $(LIBFT_DIR)

#bonus :
#	make DO_BONUS=1
	
clean :
	rm -f $(SOLONG_OBJECT)
	rm -f $(SOLONG_BONUS_FILE:.c=.o)
	make -C $(MLX_DIR) clean


fclean : clean
	make -C $(GET_NEXT_LINE_DIR) fclean
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)

re : fclean all
.PHONY : all clean fclean re bonus