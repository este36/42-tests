/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:51:47 by emercier          #+#    #+#             */
/*   Updated: 2025/10/23 22:29:57 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <fcntl.h>
#include <bsd/string.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define ANSI_GREEN "\x1b[32m"
#define ANSI_RED "\x1b[31m"
#define ANSI_RESET "\x1b[0m"
#define OK() printf(ANSI_GREEN"OK"ANSI_RESET"\n")
#define ERROR() printf(ANSI_RED"Error!"ANSI_RESET"\n")

bool test_isprint(void)
{
	printf("test_isprint: ");
	for (int i = 0; i < 255; i++)
	{
		if ((ft_isprint(i) != 0) != (isprint(i) != 0))
		{
			ERROR();
			printf(
				"[input: %d]\nc_res: %d\nft_res: %d",
				i, isprint(i), ft_isprint(i)
			);
			return (false);
		}
	}
	OK();
	return (true);
}

bool test_isascii(void)
{
	printf("test_isascii: ");
	for (int i = 0; i < 255; i++)
	{
		if ((ft_isascii(i) != 0) != (isascii(i) != 0))
		{
			ERROR();
			printf(
				"[input: %d]\nc_res: %d\nft_res: %d",
				i, isascii(i), ft_isascii(i)
			);
			return (false);
		}
	}
	OK();
	return (true);
}

bool test_isalnum(void)
{
	printf("test_isalnum: ");
	for (int i = 0; i < 255; i++)
	{
		if ((ft_isalnum(i) != 0) != (isalnum(i) != 0))
		{
			ERROR();
			printf(
				"[input: %d]\nc_res: %d\nft_res: %d",
				i, isalnum(i), ft_isalnum(i)
			);
			return (false);
		}
	}
	OK();
	return (true);
}

bool test_isdigit(void)
{
	printf("test_isdigit: ");
	for (int i = 0; i < 255; i++)
	{
		if ((ft_isdigit(i) != 0) != (isdigit(i) != 0))
		{
			ERROR();
			printf(
				"[input: %d]\nc_res: %d\nft_res: %d",
				i, isdigit(i), ft_isdigit(i)
			);
			return (false);
		}
	}
	OK();
	return (true);
}

bool test_isalpha(void)
{
	printf("test_isalpha: ");
	for (int i = 0; i < 255; i++)
	{
		if ((ft_isalpha(i) != 0) != (isalpha(i) != 0))
		{
			ERROR();
			printf(
				"[input: %d]\nc_res: %d\nft_res: %d",
				i, isalpha(i), ft_isalpha(i)
			);
			return (false);
		}
	}
	OK();
	return (true);
}


bool _test_strrchr(const char *s, int c)
{
	const char	*c_res = strrchr(s, c);
	const char	*ft_res = ft_strrchr(s, c);
	if (c_res != ft_res)
	{
		ERROR();
		printf(
			"[input: s: %p \"%s\", c: '%c']\nc_res: %p\nft_res: %p",
			s, s, c, c_res, ft_res
		);
		return (false);
	}
	return (true);
}

bool	test_strrchr(void)
{
	printf("test_strrchr: ");
	if (!_test_strrchr("test", 'e'))
		return (false);
	if (!_test_strrchr("test6a", 310))
		return (false);
	if (!_test_strrchr("te", 0))
		return (false);
	if (!_test_strrchr("", 'a'))
		return (false);
	OK();
	return (true);
}

bool _test_strchr(const char *s, int c)
{
	const char	*c_res = strchr(s, c);
	const char	*ft_res = ft_strchr(s, c);
	if (c_res != ft_res)
	{
		ERROR();
		printf(
			"[input: s: %p \"%s\", c: '%c']\nc_res: %p\nft_res: %p",
			s, s, c, c_res, ft_res
		);
		return (false);
	}
	return (true);
}

bool	test_strchr(void)
{
	printf("test_strchr: ");
	if (!_test_strchr("test", 'e'))
		return (false);
	if (!_test_strchr("test6a", 310))
		return (false);
	if (!_test_strchr("te", 0))
		return (false);
	if (!_test_strchr("", 'a'))
		return (false);
	OK();
	return (true);
}

int	_test_ft_itoa(int n, char *expected)
{
	char	*res = ft_itoa(n);

	if (strcmp(res, expected) != 0)
	{
		printf("res: %s, expected: %s\n", res, expected);
		free(res);
		return (false);
	}
	free(res);
	return (true);
}

int	test_ft_itoa(void)
{
	printf("test_ft_itoa: ");
	if (!_test_ft_itoa(0x7FFFFFFF, "2147483647"))
		return (false);
	if (!_test_ft_itoa(0x80000000, "-2147483648"))
		return (false);
	if (!_test_ft_itoa(0, "0"))
		return (false);
	if (!_test_ft_itoa(1234, "1234"))
		return (false);
	if (!_test_ft_itoa(-9, "-9"))
		return (false);
	if (!_test_ft_itoa(9, "9"))
		return (false);
	if (!_test_ft_itoa(10, "10"))
		return (false);
	if (!_test_ft_itoa(-10, "-10"))
		return (false);
	if (!_test_ft_itoa(-2147483648LL, "-2147483648"))
		return (false);
	if (!_test_ft_itoa(2147483647, "2147483647"))
		return (false);
	OK();
	return (true);
}

static bool	str_arr_eq(const char **strs1, const char ** strs2)
{
	size_t	i;

	i = 0;
	if (!strs1 && !strs2)
		return (true);
	if ((!strs1 && strs2) || (strs1 && !strs2))
		return (false);
	while (strs1[i] && strs2[i] && i < 50)
	{
		if (strcmp(strs1[i], strs2[i]) != 0)
			return (false);
		i++;
	}
	if (strs1[i] || strs2[i])
		return (false);
	return (true);
}

static void	str_arr_print(const char **strs)
{
	size_t	i;

	i = 0;
	if (!strs)
	{
		printf("(nil)");
		return ;
	}
	printf("{");
	while (strs[i])
	{
		printf("\"%s\"", strs[i]);
		if (strs[i + 1])
			printf(", ");
		i++;
	}
	printf("}");
}

static void	str_arr_free(const char **strs)
{
	size_t	i;

	i = 0;
	while (strs && strs[i] && i < 50)
	{
		free((char *)strs[i]);
		i++;
	}
}

bool _test_ft_split(const char *s, int c, const char **exp)
{
	const char **res = (const char **)ft_split(s, c);

	if (!str_arr_eq(exp, res)) {
		printf("\n");
		printf("res: ");
		printf("\n");
		str_arr_print(res);
		printf("\n");
		printf("exp: ");
		printf("\n");
		str_arr_print(exp);
		printf("\n");
		str_arr_free(res);
		free((char **)res);
		return (false);
	}
	str_arr_free(res);
	free((char **)res);
	return (true);
}

bool	test_ft_split(void)
{
	const char	*r1[] = {"hello", "ca", "va", NULL};
	const char	*r2[] = {NULL};
	const char	*r3[] = {
		"lorem", "ipsum", "dolor", "sit",
		"amet,", "consectetur", "adipiscing", "elit.",
		"Sed", "non", "risus.", "Suspendisse", NULL,
	};
	const char	*r4[] = {
		"lorem", "ipsum", "dolor", "sit",
		"amet,", "consectetur", "adipiscing", "elit.",
		"Sed", "non", "risus.", "Suspendisse", NULL,
	};
	const char	*r5[] = {"nonempty", NULL};
	const char	*r6[] = {NULL};

	printf("test_ft_split: ");
	if (!_test_ft_split("hello,ca,,,,,va", ',', r1))
		return(false);
	if (!_test_ft_split("          ", ' ', r2))
		return(false);
	if (!_test_ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ', r3))
		return (false);
	if (!_test_ft_split("    lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse    ", ' ', r4))
		return(false);
	if (!_test_ft_split("nonempty", '\0', r5))
		return(false);
	if (!_test_ft_split("\0aa\0bbb", '\0', r6))
		return(false);
	OK();
	return (true);
}

bool	_test_atoi(const char *nptr)
{
	const int	c_res = atoi(nptr);
	const int	ft_res = ft_atoi(nptr);

	if (c_res != ft_res)
	{
		ERROR();
		printf("(input: \"%s\") c res: %d, ft res: %d", nptr, c_res, ft_res);
		return (false);
	}
	return (true);
}

bool	test_atoi(void)
{
	printf("test_atoi: ");
	if (!_test_atoi("1234"))
		return (false);
	if (!_test_atoi("+1234"))
		return (false);
	if (!_test_atoi("-1234"))
		return (false);
	if (!_test_atoi("\n\n\n  -46\b9 \n5d6"))
		return (false);
	OK();
	return (true);
}

bool	_test_ft_strtrim(char const *s1, char const *set, const char *expected)
{
	char *res = ft_strtrim(s1, set);

	if (strcmp(res, expected) != 0)
	{
		printf(
			"\n(input: s1:\"%s\", set: \"%s\")\nres: %s\nexpected: %s\n",
			s1, set, res, expected
		);
		free(res);
		return (false);
	}
	free(res);
	return (true);
}

bool	test_ft_strtrim(void)
{
	printf("test_ft_strtrim: ");
	if (!_test_ft_strtrim(
		"lorem ipsum dolor sit amet",
		"te",
		"lorem ipsum dolor sit am"
	))
		return (false);
	if (!_test_ft_strtrim(
		"lorem ipsum dolor sit amet",
		"tel",
		"orem ipsum dolor sit am"
	))
		return (false);
	OK();
	return (true);
}

bool _test_strlen(const char *s)
{
	const size_t c_res = strlen(s);
	const size_t ft_res = ft_strlen(s);
	if (c_res != ft_res)
	{
		ERROR();
		printf(
			"[input: \"%s\"]\nc_res: %zu, ft_res: %zu",
			s, c_res, ft_res
		);
		return (false);
	}
	return (true);
}

bool test_strlen()
{
	printf("test_strlen: ");
	if (!_test_strlen("Hello"))
		return (false);
	if (!_test_strlen(""))
		return (false);
	if (!_test_strlen("           "))
		return (false);
	if (!_test_strlen("\x23\x90\x25\x1\x09"))
		return (false);
	// 	if (!_test_strlen(NULL))
	// 		return (false);
	OK();
	return (true);
}

void print_memory(const void *ptr, size_t n)
{
	const unsigned char *p = ptr;
	const char *hex = "0123456789abcdef";

	for (size_t i = 0; i < n; i++)
	{
		putchar(hex[p[i] >> 4]);
		putchar(hex[p[i] & 0xf]);
		putchar(' ');

		if ((i + 1) % 8 == 0 || i + 1 == n)
		{
			size_t remain = 8 - ((i + 1) % 8);
			if (remain != 8 && i + 1 == n)
				for (size_t k = 0; k < remain; k++)
					printf("   ");

			putchar(' ');
			size_t start = i - ((i + 1) % 8 ? ((i + 1) % 8) - 1 : 7);
			for (size_t j = start; j <= i; j++)
				putchar(isprint(p[j]) ? p[j] : '.');
			putchar('\n');
		}
	}
}

bool _test_memset(void *s, int c, size_t n)
{
	void *s_dup = malloc(n);
	if (!s_dup) return (false);
	memcpy(s_dup, s, n);
	memset(s, c, n);
	ft_memset(s_dup, c, n);
	if (memcmp(s_dup, s, n) != 0)
	{
		printf(
			"[inputs: s: %p, c: %d, n: %zu]\nc_res: \n",
			s, c, n
		);
		print_memory(s, n);
		printf("\nft_res:\n");
		print_memory(s_dup, n);
		printf("\n");
		free(s_dup);
		return (false);
	}
	free(s_dup);
	return (true);
}

typedef struct s_test1
{
    uint32_t	a;
    bool		b;
    uint16_t	c;
    bool		d;
} t_test1;

typedef struct s_test2
{
    char	a;
    double	b;
    uint8_t	c;
} t_test2;

typedef struct s_test3
{
    uint8_t		arr[3];
    uint32_t	num;
    bool		flag;
} t_test3;

bool test_memset(void)
{
	printf("test_memset: ");
	t_test1 test1;
	t_test2 test2;
	t_test3 test3;
	char buf[1024];
	if (!_test_memset(&test1, 0xa0, sizeof(t_test1))) return (false);
	if (!_test_memset(&test2, 0xff, sizeof(t_test2))) return (false);
	if (!_test_memset(&test3, 0x00, sizeof(t_test3))) return (false);
    if (!_test_memset(buf, 0x00, 0)) return false;
    if (!_test_memset(buf, 0xff, 1)) return false;
    if (!_test_memset(buf, 0x7f, 256)) return false;
    if (!_test_memset(buf, 0x80, 512)) return false;
    if (!_test_memset(buf, 0xab, 1024)) return false;
	if (!_test_memset(buf + 1, 0x12, 255)) return false;
	if (!_test_memset(buf + 3, 0xcd, 100)) return false;
	OK();
	return (true);
}

bool _test_bzero(void *s, size_t n)
{
	void *s_dup = malloc(n);
	if (!s_dup) return (false);
	memcpy(s_dup, s, n);
	bzero(s, n);
	ft_bzero(s_dup, n);
	if (memcmp(s_dup, s, n) != 0)
	{
		ERROR();
		printf(
			"[inputs: s: %p, n: %zu]\nc_res: \n",
			s, n
		);
		print_memory(s, n);
		printf("\nft_res:\n");
		print_memory(s_dup, n);
		printf("\n");
		free(s_dup);
		return (false);
	}
	free(s_dup);
	return (true);
}


bool test_bzero(void)
{
	printf("test_bzero: ");
	t_test1 test1;
	t_test2 test2;
	t_test3 test3;
	char buf[1024];
	if (!_test_bzero(&test1, sizeof(t_test1))) return (false);
	if (!_test_bzero(&test2, sizeof(t_test2))) return (false);
	if (!_test_bzero(&test3, sizeof(t_test3))) return (false);
    if (!_test_bzero(buf, 0)) return false;
    if (!_test_bzero(buf, 1)) return false;
    if (!_test_bzero(buf, 256)) return false;
    if (!_test_bzero(buf, 512)) return false;
    if (!_test_bzero(buf, 1024)) return false;
	if (!_test_bzero(buf + 1, 255)) return false;
	if (!_test_bzero(buf + 3, 100)) return false;
	OK();
	return (true);
}

bool _test_memcpy(void *dest, const void *src, size_t n)
{
	void *dest_dup = malloc(n);
	if (!dest_dup)
		return (false);
	ft_memcpy(dest_dup, src, n);
	memcpy(dest, src, n);
	if (memcmp(dest_dup, dest, n) != 0)
	{
		ERROR();
		printf(
			"[inputs: dest: %p, src: %p, n: %zu]\nc_res: \n",
			dest, src, n
		);
		print_memory(dest, n);
		printf("\nft_res:\n");
		print_memory(dest_dup, n);
		printf("\n");
		free(dest_dup);
		return (false);
	}
	free(dest_dup);
	return (true);
}


bool test_memcpy(void)
{
    t_test1 src;
    t_test1 dst;
	memset(&dst, 0, sizeof(t_test1));
	memset(&src, 0, sizeof(t_test1));
	src.a = 0x12345678;
	src.b = true;
	src.c = 0xABCD;
	src.d = false;
    uint8_t buf_src[256] = {0};
	uint8_t buf_dst[256] = {0};
    for (size_t i = 0; i < 256; i++) buf_src[i] = i;

    printf("test_memcpy: ");
    if (!_test_memcpy(&dst, &src, sizeof(t_test1))) return false;
    if (!_test_memcpy(buf_dst, buf_src, 256)) return false;
    if (!_test_memcpy(buf_dst + 1, buf_src + 2, 100)) return false;
    OK();
    return true;
}

bool _test_memmove(const size_t dest_offset, const size_t src_offset, size_t n)
{
	const size_t buf_size = 512;
	unsigned char buf_c[buf_size];
	unsigned char buf_ft[buf_size];
    for (size_t i = 0; i < buf_size; i++) buf_c[i] = buf_ft[i] = i % 256;
	memmove(buf_c + dest_offset, buf_c + src_offset, n);
	ft_memmove(buf_ft + dest_offset, buf_ft + src_offset, n);
	if (memcmp(buf_c, buf_ft, buf_size) != 0)
	{
		ERROR();
		printf(
			"[inputs: dest_offest: %zu, src_offset: %zu, n: %zu]\nc_res: \n",
			dest_offset, src_offset, n
		);
		print_memory(buf_c , buf_size);
		printf("\nft_res:\n");
		print_memory(buf_ft , buf_size);
		printf("\n");
		return false;
	}
	return true;
}

bool test_memmove(void)
{
	printf("test_memmove: ");
	if (!_test_memmove(32, 64, 128)) return (false);
	if (!_test_memmove(64, 32, 128)) return (false);
	if (!_test_memmove(128, 129, 64)) return (false);
	if (!_test_memmove(129, 128, 64)) return (false);
	OK();
	return true;
}

bool _test_strlcpy(char *dest, const char *src, size_t n)
{
	void *dest_dup = malloc(n);
	if (!dest_dup)
		return (false);
	memcpy(dest_dup, dest, n);
	const size_t c_res = strlcpy(dest, src, n);
	const size_t ft_res = ft_strlcpy(dest_dup, src, n);

	size_t cmp_len = strlen(src) + 1;
	if (cmp_len > n) cmp_len = n;
	if (memcmp(dest_dup, dest, cmp_len) != 0 || c_res != ft_res)
	{
		ERROR();
		printf(
			"[inputs: dest: %p, src: %p, n: %zu]\nc_res: %zu, ft_res: %zu\n",
			dest, src, n, c_res, ft_res
		);
		printf("[Memory result]\nc_res: \n");
		print_memory(dest, n);
		printf("\nft_res:\n");
		print_memory(dest_dup, n);
		printf("\n");
		free(dest_dup);
		return (false);
	}
	free(dest_dup);
	return (true);
}

bool test_strlcpy(void)
{
	char buf1[64] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char buf2[32] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char buf3[16] = "aaaaaaaaaaaaaaa";
	printf("test_strlcpy: ");
	if (!_test_strlcpy(buf1, "\x12\x98\x22\x1\x23", 64)) return false;
	if (!_test_strlcpy(buf2, "", 32)) return false;
	if (!_test_strlcpy(buf3, "lololololololololollllllllllllloaaaaaaaaabbbbcccc", 16)) return false;
	OK();
	return true;
}

bool _test_strlcat(char *dest, const char *src, size_t n)
{
	void *dest_dup = calloc(1, n);
	if (!dest_dup)
		return (false);
	memcpy(dest_dup, dest, n);

	const size_t c_res = strlcat(dest, src, n);
	const size_t ft_res = ft_strlcat(dest_dup, src, n);

	if (memcmp(dest_dup, dest, n) != 0 || c_res != ft_res)
	{
		ERROR();
		printf(
			"[inputs: dest: %p, src: %p, n: %zu]\nc_res: %zu, ft_res: %zu\n",
			dest, src, n, c_res, ft_res
		);
		printf("[Memory result]\nc_res: \n");
		print_memory(dest, n);
		printf("\nft_res:\n");
		print_memory(dest_dup, n);
		printf("\n");
		free(dest_dup);
		return (false);
	}
	free(dest_dup);
	return (true);
}

bool test_strlcat(void)
{
	char buf1[64] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\0aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char buf2[32] = "aaaaaaaaaaaaaaa\0aaaaaaaaaaaaaaa";
	char buf3[16] = "aaaaaaaa\0aaaaaa";
	printf("test_strlcat: ");
	if (!_test_strlcat(buf1, "\x12\x98\x22\x1\x23", 64)) return false;
	if (!_test_strlcat(buf2, "", 32)) return false;
	if (!_test_strlcat(buf3, "lololololololololollllllllllllloaaaaaaaaabbbbcccc", 16)) return false;
	OK();
	return (true);
}

bool test_toupper(void)
{
	printf("test_toupper: ");
	for (int i = 0; i < 512; i++)
	{
		if (ft_toupper(i) != toupper(i))
		{
			ERROR();
			printf(
				"[input: %d]\nc_res: %d\nft_res: %d",
				i, toupper(i), ft_toupper(i)
			);
			return (false);
		}
	}
	OK();
	return (true);
}

bool test_tolower(void)
{
	printf("test_tolower: ");
	for (int i = 0; i < 512; i++)
	{
		if (ft_tolower(i) != tolower(i))
		{
			ERROR();
			printf(
				"[input: %d]\nc_res: %d\nft_res: %d",
				i, tolower(i), ft_tolower(i)
			);
			return (false);
		}
	}
	OK();
	return (true);
}

bool _test_strncmp(const char *s1, const char *s2, const size_t n)
{
	const int c_res = strncmp(s1, s2, n);
	const int ft_res = ft_strncmp(s1, s2, n);
	if ((c_res > 0) != (ft_res > 0))
	{
		ERROR();
		printf(
			"[input: s1: %p \"%s\", s2: %p \"%s\", n: %zu]\nc_res: %d\nft_res: %d",
			s1, s1, s2, s2, n, c_res, ft_res
		);
		return (false);
	}
	return (true);
}


bool test_strncmp()
{
	printf("test_strncmp: ");
	if (!_test_strncmp("Brother eww", "ew", 16)) return false;
	if (!_test_strncmp("Hey", "Hey", 64)) return false;
	if (!_test_strncmp("ewwwwwww12jkhv02", "ewww09s8df", 4)) return false;
	if (!_test_strncmp("doooomy", "doooomy", sizeof("doooomy"))) return false;
	OK();
	return (true);
}

bool	_test_memchr(const void *s, int c, size_t n)
{
	const char *c_res = memchr(s, c, n);
	const char *ft_res = ft_memchr(s, c, n);
	if (c_res != ft_res)
	{
		ERROR();
		printf(
			"c res: {ptr: %p, index: %zu}, ft res: {ptr: %p, index: %zu}\n",
			c_res, (size_t)(c_res - (char *)s),
			ft_res, (size_t)(ft_res - (char *)s)
		);
		return (false);
	}
	return (true);
}

bool	test_memchr(void)
{
	const char	*s1 = "Hello";
	const int	s2[] = {1, 43, -1, 4};

	printf("test_memchr: ");
	if (!_test_memchr(s1, 'o', sizeof(s1))) return (false);
	if (!_test_memchr(s1, 'o' + 512, sizeof(s1))) return (false);
	if (!_test_memchr(s2, -1, sizeof(s2))) return (false);
	OK();
	return (true);
}

bool _test_memcmp(const void *s1, const void *s2, const size_t n)
{
	const int c_res = memcmp(s1, s2, n);
	const int ft_res = ft_memcmp(s1, s2, n);
	if (c_res != ft_res)
	{
		ERROR();
		printf(
			"[input: s1: %p, s2: %p, n: %zu]\nc_res: %d\nft_res: %d",
			s1, s2, n, c_res, ft_res
		);

		printf("[Memory]\ns1: \n");
		print_memory(s1, n);
		printf("\ns2:\n");
		print_memory(s2, n);
		printf("\n");
		return (false);
	}
	return (true);
}

bool test_memcmp(void)
{
	char buf1[] = {123, 2, 0, 209, 1, -123, 3, 2 , -34};
	char buf2[] = {123, 2, 0, 209, 1, -123, 3, 2 , -34};
	printf("test_memcmp: ");
	if (!_test_memcmp(buf1, buf2, sizeof(buf1))) return false;
	if (!_test_memcmp(buf1 + 2, buf2 + 2, sizeof(buf1) - 2)) return false;
	if (!_test_memcmp("Hey", "Hey", 0)) return false;
	if (!_test_memcmp("Brother eww", "ew", 1)) return false;
	if (!_test_memcmp("ewwwwwww12jkhv02", "ewww09s8df", 4)) return false;
	if (!_test_memcmp("doooomy", "doooomy", sizeof("doooomy"))) return false;

	OK();
	return (true);
}

bool _test_strnstr(const char *big, const char *little, size_t len)
{
	const char *c_res = strnstr(big, little, len);
	const char *ft_res = ft_strnstr(big, little, len);
	if (c_res != ft_res)
	{
		ERROR();
		printf(
			"[inputs: big: %s, little: %s, len: %zu]\nc_res:\n%p \"%s\"\nft_res:\n%p \"%s\"\n",
			big, little, len, c_res, c_res, ft_res, ft_res
		);
		return (false);
	}
	return (true);
}

bool test_strnstr(void)
{
	const char big[] = 
"The strnstr() function locates the first	occurrence of the  null-terminated"
" string little in the string big, where not more than len characters"
" are searched.  Characters that appear after	a \\0 character  are"
" not  searched.  Since the strnstr() function is a FreeBSD specific API,"
" it should only be used when portability is not a	concern.";
	printf("test_strnstr: ");
	if (!_test_strnstr(big, "Characters", sizeof("Characters"))) return false;
	if (!_test_strnstr(big, "", 10)) return false;
	if (!_test_strnstr(big, "parmesan du tieks", 8)) return false;
	if (!_test_strnstr(big, "concern.", sizeof("concern."))) return false;
	if (!_test_strnstr(big, "\0that", 64)) return false;
	if (!_test_strnstr(big, "\0The", 4)) return false;
	if (!_test_strnstr("", "", 0)) return false;
	OK();
	return (true);
}

bool _test_calloc(size_t nmemb, size_t size)
{
	void *c_res = calloc(nmemb, size);
	void *ft_res = ft_calloc(nmemb, size);
	if ((!c_res || !ft_res) && c_res != ft_res)
	{
		ERROR();
		printf(
			"[inputs: nmemb: %zu, size: %zu]\nc_res: \n",
			nmemb, size 
		);
		if (c_res) free(c_res);
		if (ft_res) free(ft_res);
		return (false);
	}
	if (c_res && ft_res && memcmp(c_res, ft_res, size * nmemb) != 0)
	{
		ERROR();
		printf(
			"[inputs: nmemb: %zu, size: %zu]\nc_res: \n",
			nmemb, size 
		);
		print_memory(c_res, size * nmemb);
		printf("\nft_res:\n");
		print_memory(ft_res, size * nmemb);
		printf("\n");
		free(c_res);
		free(ft_res);
		return (false);
	}
	if (c_res) free(c_res);
	if (ft_res) free(ft_res);
	return (true);
}

bool test_calloc(void)
{
	printf("test_calloc: ");
	if (!_test_calloc(1, 512)) return false;
	if (!_test_calloc(0, 256)) return false;
	if (!_test_calloc(256, 0)) return false;
	if (!_test_calloc(1, 1)) return false;
	OK();
	return (true);
}


bool _test_strdup(const char *s)
{
	void *c_res = strdup(s);
	void *ft_res = ft_strdup(s);
	if ((!c_res || !ft_res) && c_res != ft_res)
	{
		ERROR();
		printf(
			"[input: s: %p \"%s\"]\n",
			 s, s 
		);
		if (c_res) free(c_res);
		if (ft_res) free(ft_res);
		return (false);
	}
	if (c_res && ft_res && strcmp(c_res, ft_res) != 0)
	{
		ERROR();
		printf(
			"[input: s: %p \"%s\"]\nc_res:\n",
			 s, s 
		);
		print_memory(c_res, strlen(c_res));
		printf("\nft_res:\n");
		print_memory(ft_res, strlen(ft_res));
		printf("\n");
		free(c_res);
		free(ft_res);
		return (false);
	}
	if (c_res) free(c_res);
	if (ft_res) free(ft_res);
	return (true);
}


bool test_strdup()
{
	printf("test_strdup: ");
	if (!_test_strdup("Hello")) return false;
	if (!_test_strdup("")) return false;
	if (!_test_strdup("\122\t\133\012asd")) return false;
	OK();
	return (true);
}

bool _test_ft_substr(char const *s, unsigned int start, size_t len, const char *expected)
{
	char *res = ft_substr(s, start, len);
	if (!res)
		return (false);
	if (strcmp(res, expected) != 0)
	{
		ERROR();
		printf(
			"[inputs: s: \"%s\", start: %d, len: %zu]\nres: \"%s\"\nexpected: \"%s\"\n",
			s, start, len, res, expected
		);
		free(res);
		return (false);
	}
	free(res);
	return (true);
}

bool test_ft_substr(void)
{
	printf("test_ft_substr: ");
	if (!_test_ft_substr("hello ca va", 0, 5, "hello")) return false;
	if (!_test_ft_substr("12345Salut12345", 5, 5, "Salut")) return false;
	if (!_test_ft_substr("", 0, 0, "")) return false;
	OK();
	return (true);
}

bool _test_ft_strjoin(char const *s1, char const *s2, const char *expected)
{
	char *res = ft_strjoin(s1, s2);
	if (!res)
		return (false);
	if (strcmp(res, expected) != 0)
	{
		ERROR();
		printf(
			"[inputs: s1: \"%s\", s2: \"%s\"]\nres: \"%s\"\nexpected: \"%s\"\n",
			s1, s2, res, expected
		);
		free(res);
		return (false);
	}
	free(res);
	return (true);
}

bool test_ft_strjoin(void)
{
	printf("test_ft_strjoin: ");
	if (!_test_ft_strjoin("Hello,", "oui", "Hello,oui")) return false;
	if (!_test_ft_strjoin("", "oui", "oui")) return false;
	if (!_test_ft_strjoin("aah", "", "aah")) return false;
	if (!_test_ft_strjoin("", "", "")) return false;
	OK();
	return (true);
}

char _strmapi_f(unsigned int index, char c)
{
	return (index % 2 == 0 ? toupper(c) : tolower(c));
}

bool _test_ft_strmapi(char const *s, const char *expected)
{
	char *res = ft_strmapi(s, _strmapi_f);
	if (!res)
		return false;
	if (strcmp(res, expected) != 0)
	{
		ERROR();
		printf(
			"[input: s: \"%s\"]\nres: \"%s\"\nexpected: \"%s\"\n",
			s, res, expected
		);
		free(res);
		return (false);
	}
	free(res);
	return (true);
}

bool test_ft_strmapi(void)
{
	printf("test_ft_strmapi: ");
	if (!_test_ft_strmapi("Hello", "HeLlO")) return false;
	if (!_test_ft_strmapi("", "")) return false;
	if (!_test_ft_strmapi("12345", "12345")) return false;
	if (!_test_ft_strmapi("bonjourrrreuh", "BoNjOuRrRrEuH")) return false;
	OK();
	return (true);
}

void _striteri_f(unsigned int index, char *c)
{
	*c = (index % 2 == 0 ? toupper(*c) : tolower(*c));
	// printf("\n['%c', index: %d]", *c, index);
}

bool _test_ft_striteri(char *s, const char *expected)
{
	char *res = strdup(s);
	if (!res)
		return false;
	ft_striteri(res, _striteri_f);
	if (strcmp(res, expected) != 0)
	{
		ERROR();
		printf(
			"[input: s: \"%s\"]\nres: \"%s\"\nexpected: \"%s\"\n",
			s, res, expected
		);
		free(res);
		return (false);
	}
	free(res);
	return (true);
}

bool test_ft_striteri(void)
{
	printf("test_ft_striteri: ");
	if (!_test_ft_striteri("Hello", "HeLlO")) return false;
	if (!_test_ft_striteri("", "")) return false;
	if (!_test_ft_striteri("12345", "12345")) return false;
	if (!_test_ft_striteri("bonjourrrreuh", "BoNjOuRrRrEuH")) return false;
	OK();
	return (true);
}

#define TEST_FILE_PATH "/tmp/fd_test_file"

int get_test_file(void)
{
	int fd = open(TEST_FILE_PATH, O_RDWR | O_CREAT | O_TRUNC, 0644);
	assert(fd >= 0);
	return fd;
}

bool test_file_eq(int fd, const char *str, size_t len)
{
	lseek(fd, 0, SEEK_SET);
	char *buf = calloc(1, len);
	if (!buf)
		return (false);
	if ((size_t)read(fd, buf, len) != len || memcmp(buf, str, len) != 0)
	{
		ERROR();
		printf("result:\n");
		print_memory(buf, len);
		printf("\n");
		printf("expected:\n");
		print_memory(str, len);
		printf("\n");
		free(buf);
		return (false);
	}
	free(buf);
	return (true);
}

bool _test_ft_putchar_fd(int c)
{
	int fd = get_test_file();
	ft_putchar_fd(c, fd);
	return (test_file_eq(fd, (char *)&c, 1));
}

bool test_ft_putchar_fd(void)
{
	printf("test_ft_putchar_fd: ");
	if (!_test_ft_putchar_fd('a')) return (false);
	if (!_test_ft_putchar_fd('\0')) return (false);
	if (!_test_ft_putchar_fd('\002')) return (false);
	if (!_test_ft_putchar_fd('\001')) return (false);
	OK();
	return (true);
}

bool _test_ft_putstr_fd(const char *str)
{
	int fd = get_test_file();
	ft_putstr_fd((char *)str, fd);
	return (test_file_eq(fd, str, strlen(str)));
}

bool test_ft_putstr_fd(void)
{
	printf("test_ft_putstr_fd: ");
	if (!_test_ft_putstr_fd("Hello")) return (false);
	if (!_test_ft_putstr_fd("bonjoureeuh")) return (false);
	if (!_test_ft_putstr_fd("bewbew")) return (false);
	if (!_test_ft_putstr_fd("\xff\x01\x02\xff")) return (false);
	OK();
	return (true);
}

bool _test_ft_putendl_fd(const char *str)
{
	int fd = get_test_file();
	ft_putendl_fd((char *)str, fd);
	const size_t str_len = strlen(str);
	char *expected = calloc(1, str_len + 2);
	memcpy(expected, str, str_len);
	expected[str_len] = '\n';
	bool test_result = test_file_eq(fd, expected, str_len + 1);
	free(expected);
	return (test_result);
}

bool test_ft_putendl_fd(void)
{
	printf("test_ft_putendl_fd: ");
	if (!_test_ft_putendl_fd("Hello")) return (false);
	if (!_test_ft_putendl_fd("bonjoureeuh")) return (false);
	if (!_test_ft_putendl_fd("bewbew")) return (false);
	if (!_test_ft_putendl_fd("\xff\x01\x02\xff")) return (false);
	OK();
	return (true);
}

bool _test_ft_putnbr_fd(int n, const char *expected)
{
	int fd = get_test_file();
	ft_putnbr_fd(n, fd);
	return (test_file_eq(fd, expected, strlen(expected)));
}

bool test_ft_putnbr_fd(void)
{
	printf("test_ft_putnbr_fd: ");
	if (!_test_ft_putnbr_fd(0x7FFFFFFF, "2147483647")) return (false);
	if (!_test_ft_putnbr_fd(0x80000000, "-2147483648")) return (false);
	if (!_test_ft_putnbr_fd(0, "0")) return (false);
	if (!_test_ft_putnbr_fd(1234, "1234")) return (false);
	if (!_test_ft_putnbr_fd(-9, "-9")) return (false);
	if (!_test_ft_putnbr_fd(9, "9")) return (false);
	if (!_test_ft_putnbr_fd(10, "10")) return (false);
	if (!_test_ft_putnbr_fd(-10, "-10")) return (false);
	if (!_test_ft_putnbr_fd(-2147483648LL, "-2147483648")) return (false);
	if (!_test_ft_putnbr_fd(2147483647, "2147483647")) return (false);
	if (!_test_ft_putnbr_fd(-2147483647, "-2147483647")) return (false);
	OK();
	return (true);
}

bool test_ft_lstnew(void)
{
	printf("test_ft_lstnew: ");
	t_list *res = ft_lstnew(NULL);
	if (!res)
		return (false);
	if (res->next != NULL)
	{
		ERROR();
		printf("res->next != null\n");
		return (false);
		free(res);
	}
	if (res->content != NULL)
	{
		ERROR();
		printf("res->content != NULL after calling ft_lstnew(NULL).");
		free(res);
		return (false);
	}
	OK();
	free(res);
	return (true);
}

void list_print(t_list *n)
{
	while (n)
	{
		printf("(");
		if (n->content != NULL) printf("%d", *((int *)n->content));
		else printf("NULL");
		printf(")->");
		n = n->next;
	}
	printf("NULL\n");
}

void list_free(t_list *n)
{
	while (n)
	{
		t_list *next = n->next;
		if (n->content != NULL)
			free(n->content);
		free(n);
		n = next;
	}
}

bool list_eq(t_list *n1, t_list *n2)
{
	while (n1 && n2)
	{
		if ((n1->content == NULL || n2->content == NULL) && n2->content != n1->content)
			return (false);
		if (n1->content != NULL && *((int *)n1->content) != *((int *)n2->content))
			return (false);
		n1 = n1->next;
		n2 = n2->next;
	}
	if ((n1 == NULL || n2 == NULL) && n2 != n1)
		return (false);
	return (true);
}

bool test_ft_lstadd_front(void)
{
    printf("test_ft_lstadd_front: ");
    t_list *n = ft_lstnew(NULL);
    t_list *next = ft_lstnew(NULL);
    ft_lstadd_front(&n, next);
    if (n != next)
    {
        ERROR();
        printf("node n is not the new head.\n");
        free(n);
        free(next);
        return false;
    }
    t_list *last = ft_lstnew(NULL);
    ft_lstadd_front(&n, last);
    if (n != last || n->next != next)
    {
        ERROR();
        printf("node n is not the new head after second add.\n");
        free(last->next);
        free(last);
        free(next);
        return false;
    }
    list_free(n);
    OK();
    return true;
}

bool test_ft_lstsize(void)
{
    printf("test_ft_lstsize: ");
    t_list *n = ft_lstnew(NULL);
    ft_lstadd_front(&n, ft_lstnew(NULL));
    ft_lstadd_front(&n, ft_lstnew(NULL));
    ft_lstadd_front(&n, ft_lstnew(NULL));
    ft_lstadd_front(&n, ft_lstnew(NULL));
    ft_lstadd_front(&n, ft_lstnew(NULL));
	const size_t size = ft_lstsize(n);
	if (size != 6)
	{
		ERROR();
		printf("n: Node list of size 6:\nReturn value of ft_lstsize(n) is %zu.\n", size);
		list_free(n);
		return (false);
	}
	list_free(n);
    OK();
    return (true);
}

bool test_ft_lstlast(void)
{
    printf("test_ft_lstlast: ");
    t_list *n = ft_lstnew(NULL);
    ft_lstadd_front(&n, ft_lstnew(NULL));
    ft_lstadd_front(&n, ft_lstnew(NULL));
	if (ft_lstlast(n) != n->next->next)
	{
		ERROR();
		printf("Last node is not ft_lstlast(n).\n");
		list_free(n);
		return (false);
	}
	list_free(n);
    OK();
    return (true);
}

bool test_ft_lstadd_back(void)
{
	printf("test_ft_lstadd_back: ");
    t_list *n = ft_lstnew(NULL);
    ft_lstadd_front(&n, ft_lstnew(NULL));
    ft_lstadd_front(&n, ft_lstnew(NULL));
	t_list *last = ft_lstnew(NULL);
	ft_lstadd_back(&n, last);
	if (n->next->next->next != last)
	{
		ERROR();
		printf("Last node is not 'last' after ft_lstadd_back(&n, last).\n");
		list_free(n);
		list_free(last);
		return false;
	}
	// list_print(n);
	list_free(n);
	OK();
	return true;
}

bool test_ft_lstdelone(void)
{
	printf("test_ft_lstdelone: ");
    t_list *n = ft_lstnew(NULL);
    ft_lstadd_front(&n, ft_lstnew(NULL));
	t_list *saved_next = n->next;
	ft_lstdelone(n, free);
	int *content = malloc(sizeof(int));
	if (!content)
		return false;
	*content = 69;
	saved_next->content = content;
	// list_print(saved_next);
	list_free(saved_next);
	OK();
	return (true);
}

int *alloc_int(int n)
{
	int *res = malloc(sizeof(int));
	if (!res)
		return NULL;
	*res = n;
	return res;
}

bool test_ft_lstclear(void)
{
	printf("test_ft_lstclear: ");
    t_list *n = ft_lstnew(NULL);
    ft_lstadd_front(&n, ft_lstnew(alloc_int(69)));
    ft_lstadd_front(&n, ft_lstnew(alloc_int(42)));
	ft_lstclear(&n, free);
	if (n != NULL)
	{
		ERROR();
		printf("n was not set to NULL after ft_lstclear(&n, del)");
		return (false);
	}
	OK();
	return (true);
}

static void iter_f(void *content)
{
	*((int *)content) *= 2 ;
}

bool test_ft_lstiter(void)
{
	printf("test_ft_lstiter: ");
    t_list *n = ft_lstnew(alloc_int(25));
    ft_lstadd_front(&n, ft_lstnew(alloc_int(5)));
    ft_lstadd_front(&n, ft_lstnew(alloc_int(0)));
    ft_lstadd_front(&n, ft_lstnew(alloc_int(10)));
    t_list *expected = ft_lstnew(alloc_int(50));
    ft_lstadd_front(&expected, ft_lstnew(alloc_int(10)));
    ft_lstadd_front(&expected, ft_lstnew(alloc_int(0)));
    ft_lstadd_front(&expected, ft_lstnew(alloc_int(20)));
	ft_lstiter(n, iter_f);
	if (!list_eq(n, expected))
	{
		ERROR();
		printf("[inputs: lst: (10)->(0)->(5)->(25)->NULL, f: (content) => content *= 2]\nres:\n");
		list_print(n);
		printf("expected: \n");
		list_print(expected);
		list_free(n);
		list_free(expected);
		return (false);
	}
	list_free(n);
	list_free(expected);
	OK();
	return (true);
}

static void *map_f(void *content)
{
	if (!content)
		return NULL;
	int *cpy = alloc_int(*((int *)content));
	*((int *)cpy) *= 2;
	return (cpy);
}

bool test_ft_lstmap(void)
{
	printf("test_ft_lstmap: ");
    t_list *n = ft_lstnew(alloc_int(25));
    ft_lstadd_front(&n, ft_lstnew(alloc_int(5)));
    ft_lstadd_front(&n, ft_lstnew(alloc_int(0)));
    ft_lstadd_front(&n, ft_lstnew(alloc_int(10)));
    t_list *expected = ft_lstnew(alloc_int(50));
    ft_lstadd_front(&expected, ft_lstnew(alloc_int(10)));
    ft_lstadd_front(&expected, ft_lstnew(alloc_int(0)));
    ft_lstadd_front(&expected, ft_lstnew(alloc_int(20)));
	t_list *res = ft_lstmap(n, map_f, free);
	if (!list_eq(res, expected))
	{
		ERROR();
		printf("[inputs: lst: (10)->(0)->(5)->(25)->NULL, f: (content) => content *= 2]\nres:\n");
		list_print(res);
		printf("expected: \n");
		list_print(expected);
		list_free(res);
		list_free(n);
		list_free(expected);
		return (false);
	}
	list_free(res);
	list_free(n);
	list_free(expected);
	OK();
	return (true);
}



int	main(void)
{
	if (!test_isalpha()) return 1;
	if (!test_isdigit()) return 1;
	if (!test_isalnum()) return 1;
	if (!test_isascii()) return 1;
	if (!test_isprint()) return 1;
	if (!test_strlen()) return 1;
	if (!test_memset()) return 1;
	if (!test_bzero()) return 1;
	if (!test_memcpy()) return 1;
	if (!test_memmove()) return 1;
	if (!test_strlcpy()) return 1;
	if (!test_strlcat()) return 1;
	if (!test_toupper()) return 1;
	if (!test_tolower()) return 1;
	if (!test_strchr()) return 1;
	if (!test_strrchr()) return 1;
	if (!test_strncmp()) return 1;
	if (!test_memchr()) return 1;
	if (!test_memcmp()) return 1;
	if (!test_strnstr()) return 1;
	if (!test_atoi()) return 1;
	if (!test_calloc()) return 1;
	if (!test_strdup()) return 1;
	if (!test_ft_substr()) return 1;
	if (!test_ft_strjoin()) return 1;
	if (!test_ft_strtrim()) return 1;
	if (!test_ft_split()) return 1;
	if (!test_ft_itoa()) return 1;
	if (!test_ft_strmapi()) return 1;
	if (!test_ft_striteri()) return 1;
	if (!test_ft_putchar_fd()) return 1;
	if (!test_ft_putstr_fd()) return 1;
	if (!test_ft_putendl_fd()) return 1;
	if (!test_ft_putnbr_fd()) return 1;
	if (!test_ft_lstnew()) return 1;
	if (!test_ft_lstadd_front()) return 1;
	if (!test_ft_lstsize()) return 1;
	if (!test_ft_lstlast()) return 1;
	if (!test_ft_lstadd_back()) return 1;
	if (!test_ft_lstdelone()) return 1;
	if (!test_ft_lstclear()) return 1;
	if (!test_ft_lstiter()) return 1;
	if (!test_ft_lstmap()) return 1;
	return (0);
}
