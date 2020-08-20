#include <stdio.h>
#include <unistd.h>

int main(void){

 for(int i=0; i<=100; i++){
  printf("\rContando: %d%%", i);
  fflush(stdout);
  usleep(50000);
 }

 

 return 0;
}
