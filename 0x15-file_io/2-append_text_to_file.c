#include "main.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the  filename
 * @text_content: added content
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len, bytes_written;

	if (filename == NULL || text_content == NULL)
	{
		return (-1);
	}

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
	{
		return (-1);
	}

	len = strlen(text_content);
	bytes_written = write(fd, text_content, len);

	if (bytes_written == -1 || bytes_written != len)
	{
		close(fd);
		return (-1);
	}

	close(fd);

	return (1);
}
