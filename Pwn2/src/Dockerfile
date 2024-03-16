FROM ubuntu:22.04

RUN apt-get update && apt-get install socat -y

RUN adduser --disabled-password ctf 
ADD flag.txt /flag.txt
ADD unpwnable /unpwnable

WORKDIR /
USER ctf

CMD ["socat", "-d", "-d", "TCP4-LISTEN:1338,reuseaddr,fork", "EXEC:'/unpwnable'"]