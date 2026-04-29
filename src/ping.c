#include "ft_ping.h"

int	init_packet(t_icmp_header *packet)
{
	packet->type = 8;
	packet->code = 0;
	packet->checksum = 0;
	// packet->echo.id = 
	// packet->echo.sequence = 
	// packet->frag.mtu = 
	
	packet->checksum = eval_checksum(*packet);
	return 0;
}

int	init_socket()
{
	return 0;
}

unsigned long	eval_checksum(t_icmp_header header)
{
	unsigned long	cs = header.echo.id + \
	header.echo.sequence + \
	header.frag.mtu + \
	header.frag.__glibc_reserved;

	return cs;
}

int	send_ping()
{
	return 0;
}

int	recieve_ping()
{
	return 0;
}