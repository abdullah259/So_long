CC = gcc
CFLAGS = -Werror -Wextra -Wall -g

NAME=so_long

SRC = so_long.c game.c get_next_line.c get_next_line_utils.c ft_split.c parsing.c map_fl.c map_mid.c map_last_l.c get_map.c \
      moving.c checking.c map_printing.c ft_putnbr.c check_rules.c destroy.c free_sp.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I Minilibx -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ) Minilibx/libmlx.a
	$(CC) -o so_long $(OBJ) ./minilibx/libmlx.a -LMinilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

Minilibx/libmlx.a :
	make -C Minilibx

re: fclean all

clean :
	rm -rf $(OBJ)
	make -C Minilibx clean

fclean : clean
	rm -rf $(NAME)
	make -C Minilibx clean

.PHONY: all clean fclean