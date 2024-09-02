FROM python:3.10-alpine

RUN pip install ./src/requirements.txt
ADD ./src/crypto2.py /challenge.py

CMD ["socat", "-t", "60", "-T", "60", "TCP4-LISTEN:420,reuseaddr,fork", "EXEC:'python3 /challenge.py'"]