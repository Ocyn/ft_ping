#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <netinet/ip_icmp.h>
# include <sys/time.h>
# include <netdb.h>

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

typedef struct s_data 
{
	t_icmp_header	header;
	char			*params;
	char			*host;
}	t_data;

typedef struct hostent	t_hostent;
typedef struct timeval	t_timeval;

void lorem(char *arg); // A retirer avant rendu final
int	process_input(int ac, char **av);
int init_ping(char **av);
int	return_error(char *log);

int	init_packet(t_icmp_header *packet);
int	init_socket();
unsigned short	eval_checksum(void *header, int size);
t_hostent	*find_hostname(char *input);

#endif