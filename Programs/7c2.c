#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#define MSGSZ 128
typedef struct msgbuf
{ long mtype;
char mtext[MSGSZ];
}message_buf;
main()
{
int msqid;
int msgflg = IPC_CREAT |0666; 
key_t key;
message_buf sbuf;
size_t buf_length;
key = 1234;
(void) fprintf(stderr, "\nmsgget: Calling msgget(%#lx,\ %#o)\n",key, msgflg);
if ((msqid = msgget(key, msgflg )) < 0)
{ 
perror("msgget");
exit(1);
}
else
(void) fprintf(stderr,"msgget: msgget succeeded: msqid = %d\n",msqid); 
if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
printf("%d, %d, %s, %d\n", msqid, sbuf.mtype, sbuf.mtext, buf_length);
perror("msgsnd");
exit(1);
}
else
printf("Message: \"%s\" Sent\n", sbuf.mtext);
exit(0);
}
