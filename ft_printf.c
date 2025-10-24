/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:02:21 by emercier          #+#    #+#             */
/*   Updated: 2025/10/23 22:26:03 by emercier         ###   ####lausanne.ch   */
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
	DO_ALL,
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
		fprintf(stderr, "[return value: %d]", ret); \
} while (0) \

#define PRINT_USAGE() printf("Usage : <--ft|--c> <number>\n")

#define W_FMT(val) " %10" val " %*" val " %-10" val " %-*" val " %-2" val
#define W_ARGS(val) (val),		  10, (val),  (val),   		10, (val), (val)

#define W_ZERO_FMT(val) " %010" val " %0*" val 
#define W_ZERO_ARGS(val) (val),		  10, (val)

#define W_PREC_FMT(val) " %10.5" val " %*.*" val " %-10.5" val " %-*.*" val
#define W_PREC_ARGS(val) (val),		  10, 5, (val),  (val),   		10, 20, (val)

int test(int arg1, int test_num)
{
	switch (test_num)
	{
 		case -1: {
 			fclose(stdout);
 			_PRINTF("Hello");
			_PRINTF("%c%c", 'a', 'a');
			_PRINTF("%s%s", "Hello", (char *)0 );
			_PRINTF("%p%p", (void *)0xbabeffcc11, (void *)0);
			_PRINTF("%d %d %d",  42, -42, INT_MIN);
			_PRINTF("%i %i %i",  69, -69, INT_MIN);
			_PRINTF("%u",  0xffffffff);
			_PRINTF("%x",  0xffffffff);
			_PRINTF("%X",  0xffffffff);
			_PRINTF("%%");
 		} break;
		case 0: {
			_PRINTF("Hello");
		} break;
		case 1: {
			_PRINTF("%c%c", 'a', 'a');
		} break;
		case 2: {
			_PRINTF("%s%s", "Hello", (char *)0 );
		} break;
		case 3: {
			_PRINTF("%p%p", (void *)0xbabeffcc11, (void *)0);
		} break;
		case 4: {
			_PRINTF("%d %d %d",  42, -42, INT_MIN);
		} break;
		case 5: {
			_PRINTF("%i %i %i",  69, -69, INT_MIN);
		} break;
		case 6: {
			_PRINTF("%u",  0xffffffff);
		} break;
		case 7: {
			_PRINTF("%x",  0xffffffff);
		} break;
		case 8: {
			_PRINTF("%X",  0xffffffff);
		} break;
		case 9: {
			_PRINTF("%%");
		} break;
		case 10: {
			_PRINTF("%c, %c, %s, %s, %p, %p, %d, %i, %u, %x, %X, %%",
				'a', (char)0, "Hello", (char *)0, (void *)0xbabeffcc11, (void *)0, 42, 69,
				0xffffffff, 0xffffffff, 0xffffffff);
		} break;
		case 11: {
			_PRINTF(W_FMT("c"), W_ARGS('a'));
		} break;
		case 12: {
			_PRINTF(W_FMT("c"), W_ARGS(0));
		} break;
		case 13: {
			_PRINTF(W_FMT("s"), W_ARGS("Hello"));
		} break;
		case 14: {
			_PRINTF(W_FMT("s"), W_ARGS((char *)0));
		} break;
		case 15: {
			_PRINTF(W_FMT("p"), W_ARGS((void *)0xbabeffcc11));
		} break;
		case 16: {
			_PRINTF(W_FMT("p"), W_ARGS((void *)0));
		} break;
		case 17: {
			_PRINTF( "\n" W_FMT("d") W_FMT("d") "\n" W_FMT("d"),  W_ARGS(42), W_ARGS(INT_MIN), W_ARGS(-24));
		} break;
		case 18: {
			_PRINTF( "\n" W_FMT("i") W_FMT("i") "\n" W_FMT("i"), W_ARGS(69), W_ARGS(INT_MIN), W_ARGS(-24));
		} break;
		case 19: {
			_PRINTF(W_FMT("u"), W_ARGS(0xffffffff));
		} break;
		case 20: {
			_PRINTF(W_FMT("x"), W_ARGS(0xffffffff));
		} break;
		case 21: {
			_PRINTF(W_FMT("X"), W_ARGS(0xffffffff));
		} break;
		case 22: {
			_PRINTF(W_ZERO_FMT("d"), W_ZERO_ARGS(0));
		} break;
		case 23: {
			_PRINTF(W_ZERO_FMT("i"), W_ZERO_ARGS(0));
		} break;
		case 24: {
			_PRINTF(W_ZERO_FMT("u"), W_ZERO_ARGS(0xffffffff));
		} break;
		case 25: {
			_PRINTF(W_ZERO_FMT("x"), W_ZERO_ARGS(0xffffffff));
		} break;
		case 26: {
			_PRINTF(W_ZERO_FMT("X"), W_ZERO_ARGS(0xffffffff));
		} break;
		case 27: {
			_PRINTF(W_ZERO_FMT("d") "%04d", W_ZERO_ARGS(-42), -4825);
		} break;
		case 28: {
			_PRINTF(W_ZERO_FMT("d") W_ZERO_FMT("d"), W_ZERO_ARGS(42), W_ZERO_ARGS(INT_MIN));
		} break;
		case 29: {
			_PRINTF(W_ZERO_FMT("i") "%04i", W_ZERO_ARGS(-42), -4825);
		} break;
		case 30: {
			_PRINTF(W_ZERO_FMT("i") W_ZERO_FMT("i"), W_ZERO_ARGS(69), W_ZERO_ARGS(INT_MIN));
		} break;
		case 31: {
			_PRINTF(W_PREC_FMT("d"), W_PREC_ARGS(0));
		} break;
		case 32: {
			_PRINTF(W_PREC_FMT("i"), W_PREC_ARGS(0));
		} break;
		case 33: {
			_PRINTF(W_PREC_FMT("u"), W_PREC_ARGS(0xffffffff));
		} break;
		case 34: {
			_PRINTF(W_PREC_FMT("x"), W_PREC_ARGS(0xffffffff));
		} break;
		case 35: {
			_PRINTF(W_PREC_FMT("X"), W_PREC_ARGS(0xffffffff));
		} break;
		case 36: {
			_PRINTF(W_PREC_FMT("d") "%04.2d", W_PREC_ARGS(-42), -4825);
		} break;
		case 37: {
			_PRINTF(W_PREC_FMT("d") W_PREC_FMT("d"), W_PREC_ARGS(42), W_PREC_ARGS(INT_MIN));
		} break;
		case 38: {
			_PRINTF(W_PREC_FMT("i") "%04i", W_PREC_ARGS(-42), -4825);
		} break;
		case 39: {
			_PRINTF(W_PREC_FMT("i") W_PREC_FMT("i"), W_PREC_ARGS(69), W_PREC_ARGS(INT_MIN));
		} break;
		case 40: {
			_PRINTF(W_PREC_FMT("s"), W_PREC_ARGS("Hello"));
		} break;
		case 41: {
			_PRINTF(W_PREC_FMT("s"), W_PREC_ARGS((char *)0));
		} break;
		case 42: {
			printf("TEST END");
		} break;
		default: { PRINT_USAGE(); } break;
	}
	return (0);
}

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

	if (strcmp(argv[2], "--do-all") == 0)
	{
		for (int i = 0; i < 44; i++)
			test(arg1, i);
	}
	else
		test(arg1, atoi(argv[2]));
	return (0);
}
