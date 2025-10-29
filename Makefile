CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT = ../libft/libft.a
LIBFTPRINTF = ../ft_printf/libftprintf.a

GNL_SRCS =\
../get_next_line/get_next_line.c\
../get_next_line/get_next_line_utils.c\

all: get_next_line

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
	cc $(CFLAGS) -D BUFFER_SIZE=1 gnl/gnl.c $(GNL_SRCS) -o $@

test_gnl_10:
	cc $(CFLAGS) -D BUFFER_SIZE=10 gnl/gnl.c $(GNL_SRCS) -o $@

test_gnl_1M:
	cc $(CFLAGS) -D BUFFER_SIZE=1000000 gnl/gnl.c $(GNL_SRCS) -o $@

clean:
	@echo "[INFO: Removing binaries...]"
	@rm -f test_*

fclean: clean
	$(MAKE) -C ../libft/ fclean || true;
	$(MAKE) -C ../ft_printf/ fclean || true;

re: clean all

.PHONY: test_libft test_ft_printf all clean fclean re libft
