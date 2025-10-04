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

#define ANSI_GREEN "\x1b[32m"
#define ANSI_RESET "\x1b[0m"

int	test_strchr(void)
{
	const char	*test = "TEST";
	const char	*result_c = strchr(test, 'T');
	const char	*result_ft = ft_strchr(test, 'T');
	const char	*result_c_2 = strchr(test, 'A');
	const char	*result_ft_2 = ft_strchr(test, 'A');

	printf("test_strchr: ");
	if (result_c != result_ft)
	{
		printf("c: %p, ft: %p\n", result_c, result_ft);
		return (false);
	}
	if (result_c_2 != result_ft_2)
	{
		printf("c: %p, ft: %p\n", result_c_2, result_ft_2);
		return (false);
	}
	printf(ANSI_GREEN"OK\n"ANSI_RESET);
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
	printf(ANSI_GREEN"OK\n"ANSI_RESET);
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
	printf(ANSI_GREEN"OK\n"ANSI_RESET);
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
	printf(ANSI_GREEN"OK\n"ANSI_RESET);
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
	printf(ANSI_GREEN"OK\n"ANSI_RESET);
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
	printf(ANSI_GREEN"OK\n"ANSI_RESET);
	return (true);
}

int	main(void)
{
	if (!test_strchr())
		return (1);
	if (!test_ft_itoa())
		return (1);
	if (!test_ft_split())
		return (1);
	if (!test_memchr())
		return (1);
	if (!test_atoi())
		return (1);
	if (!test_ft_strtrim())
		return (1);
	return (0);
}
