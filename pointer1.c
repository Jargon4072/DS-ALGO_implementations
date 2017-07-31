#include <stdio.h>
#include <stdlib.h>

void channgemessage(char* message1,int size)
{
  char newmessage[]="hare rama";
  if(size>sizeof(newmessage))
  {
    for(int i=0;i<sizeof(newmessage);i++)
    {
      message1[i]=newmessage[i];
    }
  }
  else{
    printf("hari bol\n" );
  }
}

int main(void)
{
  char message1[]="hare krishna";
  channgemessage(&message1,sizeof(message1));
  printf("%s\n",message1 );
}
