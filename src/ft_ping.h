#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <netinet/ip_icmp.h>

struct icmphdr;

void lorem(char *arg); // A retirer avant rendu final
int	process_input(int ac, char **av);
int init_ping(char **av);
int	return_error(char *log);

#endif