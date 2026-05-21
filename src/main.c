#include "ft_ping.h"


int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	
	int socket = 0;
	t_data	data;

	if (process_input(ac, av))
	return 1;
	data.params = parse_arg(av);
	if (init_ping(&data))
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

int init_ping(t_data *data)
{
	
	printf("PING %s XX(xx) octets de données.\n", data->target);
	t_hostent	*host = find_hostname(data->target);
	if (!host)
		return 1;
	data->socket = init_socket();
	if (data->socket == -1)
		return return_error("Init socket: ");
	if (data->packet == NULL)
		return return_error("Packet malloc: ");
	if (init_packet(data->packet))
		return return_error("init packet: ");
	printf("\n\n\nPtdrr je deconne c\'est pas encore fonctionnel c\'est du placeholder.\n\n");
	printf("\n\n\n\n\n\n\n\nFils de pute\n\n");
	return 0;
}