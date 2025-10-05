/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:51:47 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:28:12 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define ANSI_GREEN "\x1b[32m"
#define ANSI_RESET "\x1b[0m"
#define OK() printf(ANSI_GREEN"OK"ANSI_RESET"\n")

bool test_isprint(void)
{
	printf("test_isprint: ");
	for (int i = 0; i < 255; i++)
	{
		if ((ft_isprint(i) != 0) != (isprint(i) != 0))
		{
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

bool	_test_memchr(const void *s, int c, size_t n)
{
	const char *c_res = memchr(s, c, n);
	const char *ft_res = ft_memchr(s, c, n);
	if (c_res != ft_res)
	{
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
	const char	c1 = 'o';
	const int	s2[] = {1, 43, -1, 4};
	const int	c2 = -1;

	printf("test_memchr: ");
	if (!_test_memchr(s1, c1, sizeof(s1)))
		return (false);
	if (!_test_memchr(s2, c2, sizeof(s2)))
		return (false);
	OK();
	return (true);
}

bool	_test_atoi(const char *nptr)
{
	const int	c_res = atoi(nptr);
	const int	ft_res = ft_atoi(nptr);

	if (c_res != ft_res)
	{
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

void print_memory(void *s, size_t n)
{
	const char *hex = "0123456789abcdef";
	for (size_t i = 0; i < n; i++)
	{
		write(1, &hex[((unsigned char *)s)[i] >> 4], 1);
		write(1, &hex[((unsigned char *)s)[i] & 0xf], 1);
		write(1, " ", 1);
		if ((i + 1) % 8 == 0)
		    write(1, "\n", 1);
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
	if (!_test_memset(&test1, 0xa0, sizeof(t_test1)))
		return (false);
	if (!_test_memset(&test2, 0xff, sizeof(t_test2)))
		return (false);
	if (!_test_memset(&test3, 0x00, sizeof(t_test3)))
		return (false);
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
	if (!_test_bzero(&test1, sizeof(t_test1)))
		return (false);
	if (!_test_bzero(&test2, sizeof(t_test2)))
		return (false);
	if (!_test_bzero(&test3, sizeof(t_test3)))
		return (false);
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
    printf("test_memcpy: ");
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

    if (!_test_memcpy(&dst, &src, sizeof(t_test1))) return false;
    if (!_test_memcpy(buf_dst, buf_src, 256)) return false;
    if (!_test_memcpy(buf_dst + 1, buf_src + 2, 100)) return false;
    OK();
    return true;
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
	if (!test_strrchr()) return 1;
	if (!test_strchr()) return 1;
	if (!test_ft_itoa()) return 1;
	if (!test_ft_split()) return 1;
	if (!test_memchr()) return 1;
	if (!test_atoi()) return 1;
	if (!test_ft_strtrim()) return 1;
	return (0);
}
