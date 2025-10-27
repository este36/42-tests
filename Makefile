CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT = ../libft/libft.a
LIBFTPRINTF = ../ft_printf/libftprintf.a


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
	@echo "[ft_printf Tests]"
	node ft_printf/ft_printf.js

test_ft_printf: $(LIBFTPRINTF)
	@echo "[INFO: Compiling $@...]"
	@$(CC) $(CFLAGS) ft_printf/ft_printf.c $^ -o $@

$(LIBFTPRINTF):
	$(MAKE) -C ../ft_printf re
	
clean:
	@echo "[INFO: Removing binaries...]"
	@rm -f test_*

fclean: clean
	$(MAKE) -C ../libft/ fclean || true;
	$(MAKE) -C ../ft_printf/ fclean || true;

re: clean all

.PHONY: test_libft test_ft_printf all clean fclean re libft
