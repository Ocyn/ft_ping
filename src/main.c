#include "ft_ping.h"


int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	if (ac < 2)
		return (
			return_error("usage error: Adresse de destination requise")
		);
	char *target = av[1];
	printf("PING %s XX(84) octets de données.\n", target);
	printf("\n\n\nPtdrr je deconne c\'est pas encore fonctionnel c\'est du placeholder.\n\n");
	printf("\n\n\n\n\n\n\n\nFils de pute\n\n");
	return 0;
}
