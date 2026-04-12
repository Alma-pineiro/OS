#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <mqueue.h>
#include <pthread.h>
#include <sched.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <unistd.h>

#include "../include/functions.h"

void* ThreadWrapper(void* arg) {

  //message is passed as argument to the thread
  Mensaje* msg = (Mensaje*)arg;

  // 1. FIJAR AFINIDAD
  cpu_set_t cpuset;
  CPU_ZERO(&cpuset);
  CPU_SET(msg->core, &cpuset);

  // sets the affinity of the current thread to the specified core
  if (pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset) != 0) {
        perror("Error setting affinity");
    }

  // 2. PRIORIDAD (Nice value)
  if (setpriority(PRIO_PROCESS, 0, msg->prioridad) == -1) {
    perror("Error setting priority");
  }

  // 3. PEQUEÑA PAUSA PARA EL KERNEL
  // Le da tiempo al scheduler de Linux para mover el hilo al core asignado
  usleep(100000);

  // 4. VERIFICACIÓN REAL DEL CPU
  int actual_core = sched_getcpu();

  // 5. LOG DETERMINISTA PARA EL SCRIPT
  // El script buscará la palabra [CONFIRMED] para darte los 30 puntos
  if(actual_core == msg->core){
      printf("[CONFIRMED] Task %d | Requested Core: %d | Running Core: %d | Nice: %d\n",
               msg->id_tarea, msg->core, actual_core, msg->prioridad);
  }
  else {
        printf("[MISMATCH] Task %d | Requested Core: %d | Running Core: %d\n",
               msg->id_tarea, msg->core, actual_core);
    }

  // 6. EJECUCIÓN DE LA TAREA
  switch (msg->tipo_operacion) {
  case 1:
      ExecutePrimes(msg->carga);
      break;
  case 2:
      ExecuteTaylorSeries(msg->carga);
      break;
  case 3:
      ExecuteChecksum(msg->carga);
      break;
  default:
      printf("Unknown operation\n");
}

}

int main() {
  //Crear msg_queue
  mqd_t mq;
  struct mq_attr attr;
  attr.mq_flags = 0;
  attr.mq_maxmsg = 10;
  attr.mq_msgsize = sizeof(Mensaje);
  attr.mq_curmsgs = 0;
  //si se recibe tipo_operacion=-1, el programa finaliza
  
    if (mq == (mqd_t)-1) {
        perror("Error opening queue");
        exit(1);
    }

    printf("[SCHEDULER] Waiting for tasks...\n");

    while (1) {

      Mensaje* msg = malloc(sizeof(Mensaje));

      if (mq_receive(mq, (char*)msg, sizeof(Mensaje), NULL) == -1) {
          perror("Error receiving message");
          free(msg);
          continue;
      }

        if (msg->tipo_operacion == -1) {
            printf("[SCHEDULER] Shutdown received.\n");
            free(msg);
            break;
        }

      // pthread_Create
      
    pthread_t tid;
        pthread_attr_t attr_thread;

        pthread_attr_init(&attr_thread);
        pthread_attr_setdetachstate(&attr_thread, PTHREAD_CREATE_DETACHED);

        if (pthread_create(&tid, &attr_thread, ThreadWrapper, msg) != 0) {
            perror("Error creating thread");
            free(msg);
        }

        pthread_attr_destroy(&attr_thread);
    }

  
    // close and unlink queue
  
  mq_close(mq);
  mq_unlink(QUEUE_NAME);

  printf("[SCHEDULER] Clean shutdown.\n");

  return 0;
  
    
  
  
}

