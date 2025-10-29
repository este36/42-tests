CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT = ../libft/libft.a
LIBFTPRINTF = ../ft_printf/libftprintf.a
LIBGNL = ../get_next_line/libgnl.a

all: ft_printf

libft: test_libft
	@echo "[Libft Tests]"
	@./test_libft

test_libft: $(LIBFT)
	@echo "[INFO: Compiling $@...]"
	@$(CC) $(CFLAGS) libft/libft.c $^ -lbsd  -o $@

$(LIBFT):
	$(MAKE) -C ../libft/ bonus

ft_printf: test_ft_printf
	@echo "[ft_printf tests]"
	node ft_printf/ft_printf.js

test_ft_printf: $(LIBFTPRINTF)
	@echo "[INFO: Compiling $@...]"
	@$(CC) $(CFLAGS) ft_printf/ft_printf.c $^ -o $@

$(LIBFTPRINTF):
	$(MAKE) -C ../ft_printf re

get_next_line: test_gnl_1 test_gnl_10 test_gnl_1M
	@echo "[get_next_line tests]"
	@echo "[BUFFER_SIZE == 1]"
	@node gnl/gnl.js test_gnl_1
	@echo "[BUFFER_SIZE == 10]"
	@node gnl/gnl.js test_gnl_10
	@echo "[BUFFER_SIZE == 1M]"
	@node gnl/gnl.js test_gnl_1M

test_gnl_1:
	printf '1' > ../get_next_line/buffer_size.txt
	$(MAKE) -C ../get_next_line/ re;
	cc $(CFLAGS) gnl/gnl.c $(LIBGNL) -o $@

test_gnl_10:
	printf '10' > ../get_next_line/buffer_size.txt
	$(MAKE) -C ../get_next_line/ re;
	cc $(CFLAGS) gnl/gnl.c $(LIBGNL) -o $@

test_gnl_1M:
	printf '1000000' > ../get_next_line/buffer_size.txt
	$(MAKE) -C ../get_next_line/ re;
	cc $(CFLAGS) gnl/gnl.c $(LIBGNL) -o $@

clean:
	@echo "[INFO: Removing binaries...]"
	@rm -f test_*

fclean: clean
	$(MAKE) -C ../libft/ fclean || true;
	$(MAKE) -C ../ft_printf/ fclean || true;
	$(MAKE) -C ../get_next_line/ fclean || true;

re: clean all

.PHONY: test_libft test_ft_printf all clean fclean re libft
