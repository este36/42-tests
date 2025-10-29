/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:03:54 by emercier          #+#    #+#             */
/*   Updated: 2025/10/29 00:39:18 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>

#include "../../get_next_line/get_next_line.h"

void print_memory(const void *ptr, size_t n)
{
	const unsigned char *p = ptr;
	const char *hex = "0123456789abcdef";

	for (size_t i = 0; i < n; i++) {
		putchar(hex[p[i] >> 4]);
		putchar(hex[p[i] & 0xf]);
		putchar(' ');

		if ((i + 1) % 16 == 0 || i + 1 == n) {
			size_t remain = 16 - ((i + 1) % 16);
			if (remain != 16 && i + 1 == n)
				for (size_t k = 0; k < remain; k++)
					printf("   ");

			putchar(' ');
			size_t start = i - ((i + 1) % 16 ? ((i + 1) % 16) - 1 : 15);
			for (size_t j = start; j <= i; j++)
				putchar(isprint(p[j]) ? p[j] : '.');
			putchar('\n');
		}
	}
}

#define PRINT_USAGE()\
	printf("Usage: gnl <file-path|'--test'> [test-number|'--debug']\n");

int	main(int argc, char **argv)
{
	char *line = NULL;
	if (argc < 2 || argc > 3) {
		PRINT_USAGE();
		return (0);
	}
	if (argc == 2 && strcmp(argv[1], "--stdin") == 0) {
		while (1)
		{
			line = get_next_line(0);
			if (!line)
				return (0);
			printf("%s", line);
		}
	}
	else if (argc == 3 && strcmp(argv[1], "--test") == 0) {
		switch (atoi(argv[2])) {
		case 1: {
			int empty_file = open("gnl/files/empty", O_RDONLY);
			line = get_next_line(empty_file);
			line = get_next_line(empty_file);
			printf("%s", line);
		} break;
		case 2: {
			line = get_next_line(1000);
			printf("%s", line);
		} break;
		case 3: {
			line = get_next_line(-1);
			printf("%s", line);
		} break;
		default: break;
		}
		return (0);
	}

	int file = open(argv[1], O_RDONLY);

	if (argc == 3 && strcmp(argv[2], "--debug") == 0) {
		char *file_buf;
		size_t pos = 0;
		size_t file_len = lseek(file, 0, SEEK_END);
		lseek(file, 0, SEEK_SET);
		file_buf = malloc(file_len);
		if (!file_buf)
			return (1);
		do {
			line = get_next_line(file);
			if (line) {
				size_t line_len = strlen(line);
				memcpy(file_buf + pos, line, line_len);
				pos += line_len;
				free(line);
			}
		} while (line != NULL);
		print_memory(file_buf, file_len);
		return (0);
	}
	do {
		line = get_next_line(file);
		if (line) {
			printf("%s", line);
			free(line);
		}
	} while (line != NULL);
	return (0);
}
