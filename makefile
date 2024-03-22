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

$CFLAGS = -Wall -Wextra -Werror

SRC = src/check_map.c src/check_map1.c \
			src/flood_fill.c  src/draw_map.c\
			src/game_play.c src/exits.c\
			utils/get_next_line.c utils/get_next_line_utils.c \
			src/so_long.c src/anim/animation_coin.c\

CC = cc

NAME = map.a

SO_LONG = so_Long

OBJ = $(SRC:.c=.o)

all: $(SO_LONG)

$(SO_LONG): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(SO_LONG)
	echo "\e[1;32m SO_LONG ready 🎮\e[0m" 


clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(SO_LONG)

re : fclean all
