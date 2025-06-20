#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  int   pipefd[2];
  char  buf;
  pid_t cpid;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <string>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if (pipe(pipefd) < 0) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  cpid = fork();

  if (cpid < 0) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (cpid == 0) { // child reads from pipe
    close(pipefd[1]);

    while (read(pipefd[0], &buf, 1) > 0)
      write(STDOUT_FILENO, &buf, 1);

    write(STDOUT_FILENO, "\n", 1);
    close(pipefd[0]);
    _exit(EXIT_SUCCESS);
  } else {
    close(pipefd[0]);
    write(pipefd[1], argv[1], strlen(argv[1]));
    close(pipefd[1]);
    wait(NULL);
    exit(EXIT_SUCCESS);
  }

  return 0;
}
