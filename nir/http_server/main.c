#include <fcntl.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

/* Man Pages
 * socket
 * bind
 * sockaddr_in
 * htons
 * listen
 * accept
 * recv
 * strchr
 * open
 * sendfile
 * close
 */

#define PORT 8080

void check(int exp, const char *msg);

int main(int argc, char *argv[]) {

  int server_socket, client_socket;

  /* AF_INET -> IPV4
   * SOCK_STREAM -> reliable, bidirectional byte stream (Stream Socket = TCP)
   * 0 -> automatically assign the socket protocol */
  check(server_socket = socket(AF_INET, SOCK_STREAM, 0),
        "Failed to create server socket!");

  const struct sockaddr_in addr_s = {
      .sin_family = AF_INET, // family
      .sin_port =
          htons(PORT), // port number
                       // htons (host to network short) converts a 16 bit
                       // unsigned short int from host byte order to network
                       // byte order 8080 in hex is 0x1f90 but the network byte
                       // order is reversed so, htons(8080) returns 0x901f
      .sin_addr.s_addr = INADDR_ANY // IPV4 address. 0 binds on all network
                                    // interfaces which is alright
  };

  check(bind(server_socket, (struct sockaddr *)&addr_s, sizeof(addr_s)),
        "Failed to bind to port!");
  // had to typecast addr_s struct which is a sockaddr_in pointer to sockaddr
  // pointer because bind takes that
  // Note: If you dont explicitly type cast,
  // clang will show warning but gcc shows error both with c99 standard

  // file descriptor and backlog
  // backlog: number of connections that can be waiting at the same time until
  // the server starts rejecting new connections
  check(listen(server_socket, 10), "Listen Failed!");

  while (true) {

    printf("Waiting for connections...");

    // accepts the connection coming from the clients
    check(client_socket = accept(server_socket, 0, 0), "Accept Failed!");
    // addr returns info about the client connecting but we dont need that so
    // NULL and the addr len is also set to NULL

    printf("Connected Successfully!");

    // receive the string that the client is sending
    char buffer[256] = {0};
    recv(client_socket, buffer, 256, 0);

    // HTTP request is stored in the buffer
    // GET /file.html ....
    // we just need the filename so we will skip the first 5 chars and change
    // the space after that to null byte \0
    char *filename = buffer + 5;
    *strchr(filename, ' ') = 0;

    int opened_fd = open(filename, O_RDONLY);

    // file not found
    if (opened_fd == -1) {

      const char *fnf_msg = "HTTP/1.1 404 Not Fount\r\n"
                            "Content-Type: text/html\r\n"
                            "\r\n"
                            "<html><body>"
                            "File Not Found!"
                            "</body></html>";
      write(client_socket, fnf_msg, strlen(fnf_msg));

    } else {

      // using fstat to find file attributes / metadata to get the file size
      struct stat file_stat;
      fstat(opened_fd, &file_stat);

      char header[256];
      snprintf(header, sizeof(header),
               "HTTP/1.1 200 OK\r\n"
               "Content-Type: text/html\r\n"
               "Content-Length: %ld\r\n"
               "\r\n",
               file_stat.st_size);

      write(client_socket, header, strlen(header));

      sendfile(client_socket, opened_fd, 0, file_stat.st_size);
      // output fd, input fd, offset, count

      close(opened_fd);
    }

    close(client_socket);
  }

  close(server_socket);

  return 0;
}

void check(int exp, const char *msg) {
  if (exp == -1) {
    fputs(msg, stderr);
    exit(1);
  }
}
