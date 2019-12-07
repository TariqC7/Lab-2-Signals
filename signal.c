/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  printf("Turing was great!\n");
  alarm(1); //exit after printing
}

void handler_time(int signum){ //signal handler for execution time
  double time_spent;
  clock_t start = clock(); //start the clock
  signal(SIGALRM, handler); 
  clock_t end = clock(); 
  time_spent += (double)(end - start) / CLOCKS_PER_SEC;
  printf("Total execution time in seconds: %f\n", time_spent);
  exit(1);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); 
  signal(SIGINT,handler_time); 

  alarm(1); //Schedule a SIGALRM for 1 second
  while(1){
    pause(); 
  } 
  return 0; //never reached
}