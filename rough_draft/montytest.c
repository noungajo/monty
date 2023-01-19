#include "monty.h"

int push_value;

int main(int argc, char *argv[])
{
	FILE* file;
	char *line, *command;
	int checker;
	size_t size, line_num;
	ssize_t read = 0;

	line = NULL;
	size = 0;
	line_num = 1;
	if (argc != 2)
		exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read = getline(&line, &size, file);
	while (read != -1)
	{
		command = find_command(line);
		if (command == NULL)
		{
			printf("L%lu: usage: push integer\n", line_num);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		checker = check_codes(command);
		if (checker == 1)
		{
			printf("L%lu: unknown instruction %s\n", line_num, command);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		line_num++;
		read = getline(&line, &size, file);
	}
	free(line);
	fclose(file);
	return (0);
}

char *find_command(char *line)
{
	char *command, *push_arg;

        command = strtok(line, "\n \t\r");
	if (strcmp(command, "push") == 0)
	{
		push_arg = strtok(NULL, "\n \t\r");
		if (push_arg == NULL)
			return (NULL);
		int_check(push_arg);
	}
	return (command);
}

int check_codes(char *command)
{
	char *opcodes = "push";
	size_t i, arr_size;

	arr_size = 1;
	i = 0;
	while (i < arr_size)
	{
		if (strcmp(command, opcodes) == 0)
			printf("Pushing\n");
		else
			return (1);
		i++;
	}
	printf("push_value: %d\n", push_value);
	return (0);
}

int int_check(char *push_arg)
{
	int i;

	i = 0;
	while (push_arg[i] != '\0')
	{
		if (isalpha(push_arg[i]))
			return (1);
		i++;
	}
	push_value = atoi(push_arg);
	printf("push_value: %d\n", push_value);
	return (0);
}
