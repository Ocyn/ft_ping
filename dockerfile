FROM debian:bullseye
RUN apt-get update && apt-get install -y \
	inetutils-ping

CMD [ "ping", "google.com" ]

