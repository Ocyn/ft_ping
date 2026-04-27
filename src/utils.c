#include "ft_ping.h"

void lorem(char *arg)
{
	printf("Lorem [%s] Ipsum\n", arg);
}

int	return_error(char *log)
{
	char prefix[] = "ping: ";
	write(2, prefix, strlen(prefix));
	write(2, log, strlen(log));
	write(2, "\n", 1);
	return 1;
}