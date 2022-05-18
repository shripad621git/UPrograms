#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SHMSZ 30
void main()
{
char c;
int shmid;
key_t key;
char *shm, *s;
key = 5858;
if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
perror("shmget");
exit(1);
}
if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
perror("shmat");
exit(1);
}
s = shm;
FILE *fptr;
fptr=fopen("test.txt","r");
while(c!=EOF)
{
c=fgetc(fptr);
*s++=c;
}
*s=NULL;
/* for (c = 'a'; c <= 'z'; c++)
*s++ = c;
*s = NULL; */
while (*shm != '#')
sleep(1);
exit(0);
}
