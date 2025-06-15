#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("hello world  (pid:%d)\n", (int) getpid());
  int x = 101;
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello child  (pid:%d)\n", (int) getpid());
    x = 303;
    printf("child  x = %d\n", x);
  } else {
    x = 404;
    printf("hello parent (pid:%d) of %d\n", (int) getpid(), rc);
    printf("parent x = %d\n", x);
  }

  return 0;
}
