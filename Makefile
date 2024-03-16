DOCKER_COMPOSE=docker compose
COMPOSE_PATH=/src/docker-compose.yml
SERVICES = Web1 Web2 Web3 Crypto2 Pwn1 Pwn2 Pwn3 Reverse3

up:
	@for service in $(SERVICES); do \
		project_name=$$(echo $$service | tr '[:upper:]' '[:lower:]'); \
		$(DOCKER_COMPOSE) -p $$project_name -f $$service$(COMPOSE_PATH) up -d; \
	done

down:
	@for service in $(SERVICES); do \
		project_name=$$(echo $$service | tr '[:upper:]' '[:lower:]'); \
		$(DOCKER_COMPOSE) -p $$project_name -f $$service$(COMPOSE_PATH) down; \
	done

clean:
	@for service in $(SERVICES); do \
		lower_service=$$(echo $$service | tr '[:upper:]' '[:lower:]'); \
		docker container stop $$service; \
		docker container rm $$service; \
		docker image rm $$lower_service; \
	done