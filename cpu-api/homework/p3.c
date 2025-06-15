#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  void wait(void);

  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello\n");
  } else {
    wait();
    printf("goodbye\n");
  }

  return 0;
}
