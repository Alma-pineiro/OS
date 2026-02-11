#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main() {
  pid_t pid;

  // first fork
  pid = fork();

  if (pid == 0) {
    pid_t p = getpid();

    int exc = execlp("gcc", "gcc", "../tests/source_code.c", "-o",
                     "../build/manager", NULL);
    exit(EXIT_SUCCESS);
  }
  waitpid(pid, NULL, 0);
  // First child cloned after the first fork.
  pid_t child1 = fork();
  if (child1 == 0) {
    pid_t child1_pid = getpid();
    char pid_str[16];
    snprintf(pid_str, sizeof(pid_str), "%d", child1_pid);
    sleep(1);
    int exc_child_1 = execlp("./manager", "manager", pid_str, NULL);
    exit(EXIT_SUCCESS);
  }
  // Second chiled clones from the first fork
  pid_t child2 = fork();
  if (child2 == 0) {
    pid_t child2_pid = getpid();
    char pid_str[16];
    snprintf(pid_str, sizeof(pid_str), "%d", child2_pid);
    sleep(1);
    int exc_child_2 = execlp("./manager", "manager", pid_str, NULL);
    exit(EXIT_SUCCESS);
  }

  waitpid(child1, NULL, 0);
  waitpid(child2, NULL, 0);
}