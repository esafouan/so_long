SRC = so_long.c get_next_line.c get_next_line_utils.c ft_split.c keypress_a.c keypress_d.c keypress_s.c keypress_w.c put_elements.c chheck_map.c read_file.c put_10E.c ft_printf.c ft_printf_utils.c ft_printf_utils_2.c flood4col.c flood4exit.c calculx.c calculy.c
OBJFILES = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
NAME = so_long
all: $(NAME)

$(NAME): $(OBJFILES)
	cc $(CFLAGS) $(OBJFILES) -lmlx -framework OpenGl -framework Appkit -o $(NAME)

clean:
	rm -rf $(OBJFILES)

fclean: clean
	rm -rf $(NAME)
re:fclean all