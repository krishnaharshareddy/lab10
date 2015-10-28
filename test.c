#include "stdio.h"

int main()
{
  FILE* fp;
  fp = fopen("/dev/sda","r");
  if(fp != NULL) {
    char buff[2];
    fgets(buff,2,fp);
    printf("%s\n",buff);
    printf("%d\n",(int)buff[0]);
  }
}
  
