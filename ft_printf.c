/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:02:21 by emercier          #+#    #+#             */
/*   Updated: 2025/10/21 22:03:26 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <ctype.h>

typedef enum arg1
{
	ARG_UNSET,
	DO_C,
	DO_FT,
	DO_PRINT_ARGS
} t_arg1;

#define _PRINTF(...) \
do { \
	int ret; \
	switch (arg1) \
	{ \
		case DO_PRINT_ARGS: { \
			printf("%s\n", #__VA_ARGS__); \
			} break; \
		case DO_FT: { ret = ft_printf(__VA_ARGS__); } break; \
		case DO_C: { ret = printf(__VA_ARGS__); } break; \
		default: break; \
	} \
	if (arg1 == DO_FT || arg1 == DO_C) \
		printf("[return value: %d]", ret); \
} while (0) \

#define PRINT_USAGE() printf("Usage : [--ft|--c] [0-9]\n")

#define W_FMT(val) " %10" val " %*" val " %-10" val " %-*" val
#define W_ARGS(val) val,		  10, val,  val,   		10, val

int main(int argc, char **argv)
{
	t_arg1 arg1 = ARG_UNSET;
	if (argc <= 2)
	{
		PRINT_USAGE();
		return (0);
	}
	if (strcmp(argv[1], "--print-args") == 0)
		arg1 = DO_PRINT_ARGS;
	else if (strcmp(argv[1], "--ft") == 0)
		arg1 = DO_FT;
	else if (strcmp(argv[1], "--c") == 0)
		arg1 = DO_C;
	else
	{
		PRINT_USAGE();
		return (0);
	}
	
	switch (atoi(argv[2]))
	{
		case 1: {
			_PRINTF("%c, %c, %s, %s, %p, %p, %d, %i, %u, %x, %X, %%",
				'a', (char)0, "Hello", (char *)0, (void *)0xbabeffcc11, (void *)0, 42, 69,
				0xffffffff, 0xffffffff, 0xffffffff);
		} break;
		case 2: {
			_PRINTF(W_FMT("c"), W_ARGS('a'));
		} break;
		default: { PRINT_USAGE(); } break;
	}
	return (0);
}
