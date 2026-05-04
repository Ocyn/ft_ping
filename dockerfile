FROM debian:bullseye
RUN apt-get update && apt-get install -y \
	inetutils-ping \
	gcc \
	sudo \
	make

WORKDIR /app
COPY . /app

RUN make re

RUN chown root:root ft_ping && chmod u+s ft_ping

RUN chmod +x ft_ping


RUN echo "Running ft_ping to test its functionality..." && \
	./ft_ping google.com

RUN echo "ft_ping terminated, launching ping for comparison..."

CMD [ "ping", "-c", "4", "google.com" ]

RUN echo "ft_ping and ping tests completed. You can compare the outputs above to see if ft_ping is working correctly."

