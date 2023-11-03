#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void display_elf_header(const char *filename);
void print_elf_info(Elf64_Ehdr *header);
void close_file(int fd);

/**
 * main - Entry point of the ELF header information display program.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the program's arguments.
 *
 * Return: 0 on success, or an appropriate exit status on failure.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	display_elf_header(argv[1]);
	return (0);
}

/**
 * display_elf_header - Opens an ELF file, reads its ELF header
 * and displays the required information.
 * @filename: The name of the ELF file.
 */

void display_elf_header(const char *filename)
{
	int fd;
	Elf64_Ehdr header;

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", filename);
		exit(98);
	}

	if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", filename);
		close_file(fd);
		exit(98);
	}

	print_elf_info(&header);
	close_file(fd);
}

/**
 * print_elf_info - Prints the ELF header information.
 * @header: Pointer to the ELF header structure.
 */

void print_elf_info(Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf(" Magic: ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", header->e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}

	printf("\n");
	printf("Class: ");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
	}

	printf("Data: ");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
	}

	printf("Version: %d", header->e_ident[EI_VERSION]);
	switch (header->e_ident[EI_VERSION])
	{
		case EV_NONE:
			printf(" (invalid)\n");
			break;
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
	}

	printf("OS/ABI: ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
	}

	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

	printf("Type: ");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_type);
	}

	printf("Entry point address: 0x%lx\n", header->e_entry);
}

/**
 * close_file - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to close.
 */

void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
		exit(98);
	}
}
