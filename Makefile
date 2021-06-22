CC = gcc
CFLAGS  = -g -Wall


SERVER = server
CLIENT_1 = client_1
CLIENT_2 = client_2



all: $(SERVER) $(CLIENT_1) $(CLIENT_2)

$(SERVER): $(SERVER).c
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER).c

$(CLIENT_1): $(CLIENT_1).c
	$(CC) $(CFLAGS) -o $(CLIENT_1) $(CLIENT_1).c

$(CLIENT_2): $(CLIENT_2).c
	$(CC) $(CFLAGS) -o $(CLIENT_2) $(CLIENT_2).c


clean:
	$(RM) $(TARGET) $(CLIENT_1) $(CLIENT_2)


