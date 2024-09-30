FROM python:3.10-alpine

WORKDIR /service
COPY misc3.py service.py
COPY requirements.txt .
COPY flag.txt .
RUN pip install -r requirements.txt

CMD ["python", "service.py"]