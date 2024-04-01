# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 08:39:12 by adam              #+#    #+#              #
#    Updated: 2024/03/20 22:15:22 by akhobba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRC = src/check_map.c src/check_map1.c \
			src/flood_fill.c  src/draw_map.c\
			src/game_play.c src/exits.c\
			utils/get_next_line.c utils/get_next_line_utils.c \
			src/so_long.c src/puts.c src/strncmp.c\
			src/animation.c src/error.c

CC = cc
NAME = map.a

SO_LONG = so_long

SO_LONG_BONUS = so_long_bonus

OBJ = $(SRC:.c=.o)

SRC_BONUS = src_bonus/check_map_bonus.c src_bonus/check_map1_bonus.c \
			src_bonus/flood_fill_bonus.c  src_bonus/draw_map_bonus.c\
			src_bonus/game_play_bonus.c src_bonus/exits_bonus.c\
			src_bonus/so_long_bonus.c src_bonus/puts_bonus.c src_bonus/strncmp_bonus.c\
			src_bonus/animation_bonus.c src_bonus/error_bonus.c\
			utils/get_next_line.c utils/get_next_line_utils.c \

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(SO_LONG)

$(SO_LONG): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(SO_LONG)
	@echo "SO_LONG ready 🎮" 

bonus : $(SO_LONG_BONUS)

$(SO_LONG_BONUS): $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(SO_LONG_BONUS)
	@echo "SO_LONG bonus ready 🎮" 

clean :
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean : clean
	rm -f $(SO_LONG)
	rm -f $(SO_LONG_BONUS)

re : fclean all
