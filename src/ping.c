#include "ft_ping.h"

int	init_packet(t_icmp_header *packet)
{
	memset(packet, 0, 64);
	packet->type = 8;
	packet->code = 0;
	packet->checksum = htons(0);
	packet->echo.id = htons(getpid());
	packet->echo.sequence = htons(1);
	// packet->frag.mtu = 
	
	packet->checksum = eval_checksum(packet, 64);
	return 0;
}

int	init_socket()
{
	// Socket Raw requiere sudo to work
	int	sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sock == -1)
		return return_error("Socket init failed");
	return sock;
}

unsigned short	eval_checksum(void *header, int size)
{
	unsigned short *ptr = header;
	unsigned long acc = 0;
	while (size > 1)
	{
		acc += *ptr;
		ptr++;
		size -= 2;
	}
	
	if (size == 1)
		acc += (unsigned char)*ptr << 8;
	acc = (acc >> 16) + (acc & 0xFFFF);
	acc = (acc >> 16) + (acc & 0xFFFF);
	return (unsigned short)~acc;
}

int	send_ping()
{
	return 0;
}

int	recieve_ping()
{
	return 0;
}