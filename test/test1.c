#include <stdlib.h>
#include <stdio.h>

int main()
{ 
  write(1, "test8\n",6);
  int i; 
  char *addr; 

  i = 0; 
  while (i < 1024) 
  { 
   addr = (char*)malloc(1024); 
   
   addr[0] = 42;
   i++; 
  } 
  return (0); 
}