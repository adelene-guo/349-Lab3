#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define UNUSED __attribute__((unused))
#define LINE_LEN 64
#define ALLOC_LEN 16

#include <servo.h>

int main(UNUSED int argc, UNUSED char const *argv[]){
  /* Test 1: write and the SVC dispatch path */
  printf("Hello World from User.\n");
  fflush(stdout);

  /* Test 2: sbrk, via malloc */
  char *heap_buf = malloc(ALLOC_LEN);
  if (heap_buf == NULL) {
    printf("malloc failed\n");
    return 1;
  }
  for (int i = 0; i < ALLOC_LEN - 1; i++) {
    heap_buf[i] = 'A' + i;
  }
  heap_buf[ALLOC_LEN - 1] = '\0';
  printf("malloc ok at %p: %s\n", (void *)heap_buf, heap_buf);
  free(heap_buf);

  /* Test 3: read, with echo, backspace and Enter */
  char line[LINE_LEN];
  printf("Type a line: ");
  fflush(stdout);
  if (fgets(line, sizeof(line), stdin) == NULL) {
    printf("\nread failed or EOF\n");
    return 1;
  }
  printf("You typed: %s", line);

  return 0;
}