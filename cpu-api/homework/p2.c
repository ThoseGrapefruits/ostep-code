#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("hello world  (pid:%d)\n", (int) getpid());
  FILE *fd = fopen("./test.txt", "a+");
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello child  (pid:%d)\n", (int) getpid());
    fprintf(fd, "child %d\n", (int) getpid());
  } else {
    printf("hello parent (pid:%d) of %d\n", (int) getpid(), rc);
    fprintf(fd, "parent %d\n", (int) getpid());
  }

  return 0;
}
