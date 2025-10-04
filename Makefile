CC = cc
CFLAGS = -g -Wall -Wextra

LIBFT = ../libft/libft.a


all: test_libft
	@echo "[Libft Tests]"
	@./test_libft

test_libft: $(LIBFT)
	$(CC) $(CFLAGS) libft.c -lft -L../libft/ -o $@

$(LIBFT):
	$(MAKE) -C ../libft/ bonus

clean:
	$(MAKE) -C ../libft/ fclean

re: clean all
