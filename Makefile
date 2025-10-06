CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT = ../libft/libft.a


all: libft

libft: test_libft
	@echo "[Libft Tests]"
	@./test_libft

test_libft: $(LIBFT)
	@echo "[INFO: Compiling $@...]"
	@$(CC) $(CFLAGS) libft.c -lbsd -lft -L../libft/ -o $@

$(LIBFT):
	$(MAKE) -C ../libft/ bonus

clean:
	@echo "[INFO: Removing binaries...]"
	@rm -f test_*

fclean: clean
	$(MAKE) -C ../libft/ fclean

re: clean all

.PHONY: all clean fclean re libft
