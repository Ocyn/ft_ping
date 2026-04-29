#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <netinet/ip_icmp.h>
# include <sys/time.h>

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

struct timeval;

void lorem(char *arg); // A retirer avant rendu final
int	process_input(int ac, char **av);
int init_ping(char **av);
int	return_error(char *log);

unsigned long	eval_checksum(t_icmp_header header);

#endif