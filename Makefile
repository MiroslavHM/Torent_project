CC = gcc
CFLAGS = -Wall -I./shared

CLIENT_SRC = client/client.c shared/common.c
SERVER_SRC = server/server.c shared/common.c

all: client server

client: $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o client/client $(CLIENT_SRC)

server: $(SERVER_SRC)
	$(CC) $(CFLAGS) -o server/server $(SERVER_SRC)

clean:
	rm -f client/client server/server
