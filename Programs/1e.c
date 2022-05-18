#include<stdio.h>
#include<stdlib.h>
int main()
{
char str[256], buf[256];
printf("Enter command ");
scanf("%s",str);
sprintf(buf, "/bin/sh -c %s", str);
system(buf);
return 0;
}
