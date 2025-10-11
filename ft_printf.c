/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:02:21 by emercier          #+#    #+#             */
/*   Updated: 2025/10/11 17:42:54 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <stdio.h>
#include <string.h>

#define TEST_1 "%d", 0xff

int main(int argc, char **argv)
{
	int	is_ft = 0;

	if (argc <= 1)
	{
		printf("Usage : [--ft|--c] [0-9]\n");
		return (0);
	}
	if (strcmp(argv[1], "--ft") == 0)
		is_ft = 1;
	else if (strcmp(argv[1], "--c") == 0)
		is_ft = 0;
	
	switch (atoi(argv[2]))
	{
		case 1:
		{
			if (is_ft)
				ft_printf(TEST_1);
			else
				printf(TEST_1);
		} break;
	}
	return (0);
}
