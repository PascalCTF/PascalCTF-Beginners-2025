FROM python:3-alpine

RUN addgroup -S appgroup && adduser -S appuser -G appgroup

RUN apk update && apk add python3-dev
ADD ./server.py /app/server.py
RUN pip install --no-cache-dir flask

WORKDIR /app
USER appuser

CMD ["python3", "server.py"]