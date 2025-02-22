NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
ISSLIB_DIR = $(SRC_DIR)/isslib

CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_SRC = $(SRC_DIR)/server.c

ISSLIB_SRC = $(ISSLIB_DIR)/ft_atoi.c \
			$(ISSLIB_DIR)/ft_bzero.c \
			$(ISSLIB_DIR)/ft_memset.c \
			$(ISSLIB_DIR)/ft_putchar_fd.c \
			$(ISSLIB_DIR)/ft_putnbr_fd.c \
			$(ISSLIB_DIR)/ft_putstr_fd.c \
			$(ISSLIB_DIR)/ft_strlen.c

ISSLIB_OBJ = $(ISSLIB_SRC:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_SRC) $(ISSLIB_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_SERVER): $(SERVER_SRC) $(ISSLIB_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ISSLIB_OBJ)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
