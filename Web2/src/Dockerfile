FROM node:20.14-slim
WORKDIR /srv/app
COPY ./package.json ./server.js ./
COPY public ./public/
RUN npm install
CMD ["node", "server.js"]