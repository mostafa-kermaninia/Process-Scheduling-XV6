#include "types.h"
#include "stat.h"
#include "user.h"

#define NPROC 5

int
fibonacci(int n){
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int
main(void)
{
  int pid, n = 40;

  for(int i = 0; i < NPROC; i++){
    printf(1, "scheduletest: starting fibonacci\n");
    pid = fork();
    if(pid < 0){
      printf(1, "scheduletest: fork failed\n");
      exit();
    }
    if(pid == 0){
      printf(1, "fibonacci(%d) = %d\n", n, fibonacci(n));
      exit();
    }
  }

  for(int i = 0; i < NPROC; i++)
    wait();

  exit();
}
