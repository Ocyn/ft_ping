#include "ft_ping.h"


int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	
	if (process_input(ac, av))
		return 1;
	if (init_ping(av))
		return 1;
	return 0;
}

int	process_input(int ac, char **av)
{
	if (ac < 2)
		return (
			return_error("usage error: Adresse de destination requise")
		);
	if (!av)
		return (return_error("Process error: AV introuvable"));
	
	return 0;
}

int init_ping(char **av)
{
	char *target = av[1];
	printf("PING %s XX(84) octets de données.\n", target);
	printf("\n\n\nPtdrr je deconne c\'est pas encore fonctionnel c\'est du placeholder.\n\n");
	printf("\n\n\n\n\n\n\n\nFils de pute\n\n");
	return 0;
}