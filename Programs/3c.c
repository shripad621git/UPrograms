#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{ 
  char old[100];
  char new[100];
  char ch;
  printf("Enter the old and new pathname: \n");
  gets(old);
  gets(new);
  int n = link(old,new);
  if(n==0)
  {
     printf("Linked successfully\n");
  }
  else
 {
   printf("Linked unsuccessfully\n");
 }
 printf("Do you want to unlink the new file?\n1:Y\n2:N\n");
 scanf("%c",&ch);
 if(ch=='Y'||ch=='y')
 {
   int m = unlink(new);
   if(m==0)
   {
      printf("Unlinked successfully\n");
   }
   else
   {
     printf("Unlinked unsuccessfully\n");
   }
 }
 else
 {
   printf("Not Unlinked\n");
 }
}
