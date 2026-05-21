#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <netinet/ip_icmp.h>
# include <sys/time.h>
# include <netdb.h>

# define DATA_PAYLOAD "An idiot admire complexity, a genius admire simplicity"

// struct icmphdr;
typedef struct	s_icmp_header
{
	uint8_t type;
	uint8_t code;
	uint16_t checksum;
	union
	{
		struct
		{
		uint16_t	id;
		uint16_t	sequence;
		} echo;	
		uint32_t	gateway;
		struct
		{
		uint16_t	__glibc_reserved;
		uint16_t	mtu;
		} frag;
	};
}	t_icmp_header;

typedef struct s_params
{
	bool	verbose;
	bool	help;
}	t_params;

typedef struct s_packet
{
	t_icmp_header	header;
	char			payload[56];
}	t_packet;

typedef struct s_data
{
	t_packet		packet;
	// char			*params;
	t_params		params;
	int				*socket;
	char			*target;
	char			*host;
}	t_data;

typedef struct hostent	t_hostent;
typedef struct timeval	t_timeval;

void lorem(char *arg); // A retirer avant rendu final
int	process_input(int ac, char **av);
int init_ping(char **av, int *socket, t_packet *packet);
int	return_error(char *log);

int	init_packet(t_packet *packet);
int	init_socket();
unsigned short	eval_checksum(void *header, int size);
t_hostent	*find_hostname(char *input);

t_params	parse_arg(char **tab);

#endif