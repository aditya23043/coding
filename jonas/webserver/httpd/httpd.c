/* httpd.c */
/* NOTE: fd means File Descriptor */

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define LISTENADDR "127.0.0.1"

char *error;

int server_init(int portno);
int client_accept(int server_fd);
void client_connection(int server_fd, int client_fd);

int main(int argc, char *argv[]) {

  int server_fd, client_fd;
  char *port;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <listening port>\n", argv[0]);
    return -1;
  } else {
    port = argv[1];
  }

  server_fd = server_init(atoi(port));
  if (!server_fd) {
    fprintf(stderr, error);
    return -1;
  }

  fprintf(stdout, "Listening on %s:%s\n", LISTENADDR, port);
  while (1) {
    client_fd = client_accept(server_fd);
    if (!client_fd) {
      fprintf(stderr, "%s\n", error);
      continue;
    }
    fprintf(stdout, "Incoming connection\n");
    if (fork() == 0) {
      client_connection(server_fd, client_fd);
      // server's and client's file descriptor
    }
    /* fork()
     * for the main process, return the new process's ID
     * for the new process, return 0
     */
  }

  // the program will never reach this point
  return -1;
}

/* returns 0 on error or socket fd on success */
int server_init(int portno) {

  int server_fd;
  struct sockaddr_in server;

  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    error = "socket() error";
    return 0;
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(LISTENADDR);
  server.sin_port = htons(portno);

  int return_val = bind(server_fd, (struct sockaddr *)&server, sizeof(server));
  if (return_val) {
    close(server_fd);
    error = "bind() error";
    return 0;
  }

  return_val = listen(server_fd, 5);
  if (return_val) {
    close(server_fd);
    error = "listen() error";
    return 0;
  }

  return server_fd;
}

/* returns 0 on error or client's fd on success */
int client_accept(int server_fd) {
  int client_fd;
  socklen_t addrlen;
  struct sockaddr_in client;

  addrlen = 0;

  memset(&client, 0, sizeof(client));
  client_fd = accept(server_fd, (struct sockaddr *)&client, &addrlen);
  if (client_fd < 0) {
    error = "accept() error";
    return 0;
  }

  return client_fd;
}

void client_connection(int server_fd, int client_fd) { return; }
