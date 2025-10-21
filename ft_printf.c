/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:02:21 by emercier          #+#    #+#             */
/*   Updated: 2025/10/21 16:14:44 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
		case DO_PRINT_ARGS: { printf("%s", #__VA_ARGS__); } break; \
		case DO_FT: { ret = ft_printf(__VA_ARGS__); } break; \
		case DO_C: { ret = printf(__VA_ARGS__); } break; \
		default: break; \
	} \
	if (arg1 == DO_FT || arg1 == DO_C) \
		printf("[return value: %d]", ret); \
} while (0) \

#define PRINT_USAGE() printf("Usage : [--ft|--c] [0-9]\n")

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
		case 1: { _PRINTF("rawdata %c %10c %-10c %c", 'a', 'a', 'a', 'a'); } break;
		case 2: { _PRINTF("%s, %s, %10.5s", "hey", "\123\01\02\03", "Salut!"); } break;
		case 3: { _PRINTF("rawdata %p rawdata", (void *)0xbabeffcc11); } break;
		case 4: { _PRINTF("rawdata %d rawdata", 42); } break;
		case 5: { _PRINTF("rawdata %i rawdata", 69); } break;
		case 6: {
			_PRINTF("rawdata %08u, %-8u, %8u, %u rawdata", 0xff, 0xff, 0xff, 0xffffffff);
		} break;
		case 7: { _PRINTF("rawdata %x rawdata", 0xffffffff); } break;
		case 8: { _PRINTF("rawdata %X rawdata", 0xffffffff); } break;
		case 9: { _PRINTF("rawdata %% rawdata"); } break;
		default: { PRINT_USAGE(); } break;
	}
	return (0);
}
