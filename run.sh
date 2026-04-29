docker build -f dockerfile -t ft_ping . && \
	docker run --rm --cap-add=NET_ADMIN ft_ping