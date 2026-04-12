#include "../include/functions.h"

#include <math.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

void ExecutePrimes(int64_t n) {
  int64_t count = 0;
  int tid = syscall(SYS_gettid);
  for (int64_t i = 2; i < n; i++) {
    int primo = 1;
    for (int64_t j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        primo = 0;
        break;
      }
    }
    if (primo) count++;
  }
  printf("  [THREAD | TID: %d] Task Primes completed. Found: %ld\n", tid,
         count);
}

void ExecuteTaylorSeries(int64_t n) {
  int tid = syscall(SYS_gettid);
  double x = 1.0, suma = 0.0;
  for (int64_t i = 0; i < n; i++) {
    suma += pow(-1, i) * pow(x, 2 * i + 1) / tgamma(2 * i + 2);
  }
  printf("  [THREAD | TID: %d] Task Taylor completed. Result: %f\n", tid, suma);
}

void ExecuteChecksum(int64_t n) {
  int64_t checksum = 0;
  int tid = syscall(SYS_gettid);
  for (int64_t i = 0; i < n; i++) {
    checksum ^= i;
  }
  printf("  [THREAD | TID: %d] Task Checksum completed. Result: %ld\n", tid,
         checksum);
}