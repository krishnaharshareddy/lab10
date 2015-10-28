#include <fcntl.h> 
#include <stdio.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>

int main()
{
  int fd = open("/dev/sda",O_RDONLY);
  unsigned char buff[2];
  read(fd,buff,2);
  printf("%d\n",(int)buff[0]);
  printf("%d\n",(int)buff[1]);
}
