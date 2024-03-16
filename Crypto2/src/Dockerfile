FROM python:3.10-alpine

RUN apk add --no-cache socat
ADD crypto2.py /challenge.py

CMD ["socat", "-d", "TCP4-LISTEN:420,reuseaddr,fork", "EXEC:'python3 /challenge.py'"]