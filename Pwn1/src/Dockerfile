FROM ubuntu:22.04

RUN apt-get update && apt-get install socat -y

RUN adduser --disabled-password ctf 
ADD flag.txt /home/ctf/flag.txt
ADD worm /home/ctf/worm

WORKDIR /home/ctf
USER ctf

CMD ["socat", "-d", "TCP4-LISTEN:1337,reuseaddr,fork", "EXEC:'/home/ctf/worm'"]