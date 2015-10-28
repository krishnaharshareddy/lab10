#include <fcntl.h> 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char* argv[]) {
  int jump=atoi(argv[1]);
  int i=atoi(argv[2]);
  int fd = open("/dev/sda",O_RDONLY);
  int r;
  off_t pos;
  long diff;
  struct timeval init,fin;
  unsigned char buff[1];
  srand(time(NULL));
  r = rand() % 1000000;
  //~ printf("%d\n",r);
  pos=lseek(fd,r,SEEK_SET);
  //~ printf("%d\n",(int)pos);
  read(fd,buff,1);
  //~ printf("%d\n",(int)buff[0]);
  pos=lseek(fd,(off_t)jump,SEEK_CUR);
  //~ printf("%d\n",(int)pos);
  gettimeofday(&init, 0);
  read(fd,buff,1);
  //~ printf("%d\n",(int)buff[0]);
  gettimeofday(&fin, 0);
  diff =(fin.tv_sec-init.tv_sec)*1000000+(fin.tv_usec-init.tv_usec);
  printf("%d,%lu\n",i,diff);
  close(fd);
}
  
