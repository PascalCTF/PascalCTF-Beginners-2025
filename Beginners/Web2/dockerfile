FROM node:20.14-slim
WORKDIR /srv/app
COPY ./package.json ./server.js ./.env ./
COPY public ./public/
RUN npm install