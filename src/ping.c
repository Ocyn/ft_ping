#include "ft_ping.h"

int	init_packet(t_packet *packet)
{
	t_icmp_header	*header = &packet->header;
	memset(header, 0, 64);
	header->type = 8;
	header->code = 0;
	header->checksum = htons(0);
	header->echo.id = htons(getpid());
	header->echo.sequence = htons(0); 
	
	header->checksum = eval_checksum(header, 64);
	memset(packet->payload, 0, sizeof(t_packet));
	strcpy(packet->payload, DATA_PAYLOAD);
	printf("DEBUG packet paylaod = [%s]\n", packet->payload);
	return 0;
}

int	init_socket()
{
	// Socket Raw requiere sudo to work
	int	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
	if (sock == -1)
	{
		perror("socket");
		return -1;
	}
	return sock;
}

// TODO, a refaire
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

int	send_ping(t_packet *packet)
{
	(void) packet;
	return 0;
}

int	recieve_ping()
{
	return 0;
}
