FROM ubuntu:22.04

RUN apt-get update && apt-get install socat -y

RUN adduser --disabled-password ctf 
ADD flag.txt /home/ctf/flag.txt
ADD unpwnable /home/ctf/unpwnable

WORKDIR /home/ctf
USER ctf

CMD ["socat", "-t", "60", "-T", "60", "TCP4-LISTEN:1338,reuseaddr,fork", "EXEC:'/home/ctf/unpwnable'"]