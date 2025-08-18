#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

/*
 * socket
 * bind
 * sockaddr_in
 * listen
 */

int main(int argc, char **argv) {

  const int PORT = atoi(argv[1]);

  /*                          IPV4        TCP     auto */
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  const struct sockaddr_in addr_s = {
      .sin_family = AF_INET,
      .sin_addr.s_addr = INADDR_ANY,
      .sin_port = htons(PORT),
  };

  bind(server_socket, &addr_s, sizeof(addr_s));

  return 0;
}
