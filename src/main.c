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
	printf("PING %s XX(xx) octets de données.\n", target);
	t_hostent	*host = find_hostname(target);
	if (!host)
		return 1;
	if (init_socket())
		return return_error("Init socket: ");
	t_icmp_header *packet = malloc(64);
	if (packet == NULL)
		return return_error("Packet malloc: ");
	if (init_packet(packet))
		return return_error("init packet: ");
	printf("\n\n\nPtdrr je deconne c\'est pas encore fonctionnel c\'est du placeholder.\n\n");
	printf("\n\n\n\n\n\n\n\nFils de pute\n\n");
	return 0;
}