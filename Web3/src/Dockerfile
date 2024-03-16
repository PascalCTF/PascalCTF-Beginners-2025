FROM node:20.14.0-slim
WORKDIR /srv/app
COPY package.json .
RUN npm install --production
COPY src/ ./src/
COPY views/ ./views

CMD ["node", "src/server.js"]