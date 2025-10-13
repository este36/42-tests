CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT = ../libft/libft.a
LIBFTPRINTF = ../ft_printf/libftprintf.a


all: libft ft_printf

libft: test_libft
	@echo "[Libft Tests]"
	@./test_libft

test_libft: $(LIBFT)
	@echo "[INFO: Compiling $@...]"
	@$(CC) $(CFLAGS) libft.c -lbsd -lft -L../libft/ -o $@

$(LIBFT):
	$(MAKE) -C ../libft/ bonus

ft_printf: test_ft_printf
	@echo "[ft_printf Tests]"
	docker run --rm -it -v ~/42/tests/:/mnt -w /mnt node bash -c "node ft_printf.js"

test_ft_printf: $(LIBFTPRINTF)
	@echo "[INFO: Compiling $@...]"
	@$(CC) $(CFLAGS) ft_printf.c -lftprintf -L../ft_printf/ -o $@

$(LIBFTPRINTF):
	$(MAKE) -C ../ft_printf re
	
clean:
	@echo "[INFO: Removing binaries...]"
	@rm -f test_*

fclean: clean
	$(MAKE) -C ../libft/ fclean
	$(MAKE) -C ../ft_printf/ fclean

re: clean all

.PHONY: all clean fclean re libft
