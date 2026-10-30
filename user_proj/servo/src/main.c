#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <servo.h>

#define LINE_LEN 64
#define ALLOC_LEN 16
#define CMD_LEN 16
#define MIN_CHANNEL 1
#define MAX_CHANNEL 2
#define MAX_ANGLE 180

int main(void) {
  // Syscall tests
  // // test write and the SVC dispatch path
  // printf("Hello World from User.\n");
  // fflush(stdout);

  // //test sbrk, malloc
  // char *heap_buf = malloc(ALLOC_LEN);
  // if (heap_buf == NULL) {
  //   printf("malloc failed\n");
  //   return 1;
  // }
  // for (int i = 0; i < ALLOC_LEN - 1; i++) {
  //   heap_buf[i] = 'A' + i;
  // }
  // heap_buf[ALLOC_LEN - 1] = '\0';
  // printf("malloc ok at %p: %s\n", (void *)heap_buf, heap_buf);
  // free(heap_buf);

  // //test read, echo, backspace, and Enter
  // char line[LINE_LEN];
  // printf("Type a line: ");
  // fflush(stdout);
  // if (fgets(line, sizeof(line), stdin) == NULL) {
  //   printf("\nread failed or EOF\n");
  //   return 0;
  // }
  // printf("You typed: %s", line);
  // return 0;

  char line[LINE_LEN];
  char cmd[CMD_LEN];
  int channel = 0;
  int angle = 0;

  printf("Welcome to Servo Controller!\n");
  printf("Commands\n");
  printf("enable <ch>: Enable servo channel\n");
  printf("disable <ch>: Disable servo channel\n");
  printf("set <ch> <angle>: Set servo angle\n");
  printf("> ");
  
  while (fgets(line, sizeof(line), stdin) != NULL) {
    int parsed_count = sscanf(line, "%15s %d %d", cmd, &channel, &angle);
    int channel_ok = parsed_count >= 2 && channel >= MIN_CHANNEL && channel <= MAX_CHANNEL;
    int status = -1;

    if (channel_ok && parsed_count == 2 && strcmp(cmd, "enable") == 0) {
      status = servo_enable(channel, 1);
    } else if (channel_ok && parsed_count == 2 && strcmp(cmd, "disable") == 0) {
      status = servo_enable(channel, 0);
    } else if (channel_ok && parsed_count == 3 && angle >= 0 && angle <= MAX_ANGLE &&
                strcmp(cmd, "set") == 0) {
      status = servo_set(channel, angle);
    }

    if (parsed_count > 0 && status < 0) {
      printf("Invalid command\n");
    }
  }
  return 0;
}