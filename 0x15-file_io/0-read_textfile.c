#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 *
 * @filename: filename
 * @letters:  the number of letters it should read and print
 *
 * Return: 0 if filena,e is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t fle, byts;
	char *buf;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	fle = read(fd, buf, letters);
	byts = write(STDOUT_FILENO, buf, fle);

	close(fd);

	free(buf);

	return (byts);
}
