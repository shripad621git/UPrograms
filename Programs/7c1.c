#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdlib.h>
#include <time.h>
static void do_msgctl();
extern void exit();
extern void perror();
static char warning_message[] = "If you remove read permission for yourself, this program will fail frequently!";
main()
{
struct msqid_ds buf; 
int cmd,msqid;
(void) fprintf(stderr,"All numeric input is expected to follow C conventions:\n");
(void) fprintf(stderr,"\t0x... is interpreted as hexadecimal,\n");
(void) fprintf(stderr, "\t0... is interpreted as octal,\n");
(void) fprintf(stderr, "\totherwise, decimal.\n");
(void) fprintf(stderr,"Please enter arguments for msgctls() as requested.");
(void) fprintf(stderr, "\nEnter the msqid: ");
(void) scanf("%i", &msqid);
(void) fprintf(stderr, "\tIPC_RMID = %d\n", IPC_RMID);
(void) fprintf(stderr, "\tIPC_SET = %d\n", IPC_SET);
(void) fprintf(stderr, "\tIPC_STAT = %d\n", IPC_STAT);
(void) fprintf(stderr, "\nEnter the value for the command: ");
(void) scanf("%i", &cmd);
switch (cmd) {
case IPC_SET:
(void) fprintf(stderr, "Before IPC_SET, get current values:");
case IPC_STAT:
do_msgctl(msqid,IPC_STAT,&buf); 
(void) fprintf(stderr,"msg_perm.uid = %d\n",buf.msg_perm.uid); 
(void) fprintf(stderr,"msg_perm.gid = %d\n",buf.msg_perm.gid); 
(void) fprintf(stderr,"msg_perm.cuid = %d\n", buf.msg_perm.cuid);
(void) fprintf(stderr, "msg_perm.cgid = %d\n", buf.msg_perm.cgid);
(void) fprintf(stderr, "msg_perm.mode = %#o, ", buf.msg_perm.mode);
(void) fprintf(stderr, "access permissions = %#o\n", buf.msg_perm.mode & 0777);
(void) fprintf(stderr, "msg_cbytes = %d\n", buf.msg_cbytes);
(void) fprintf(stderr, "msg_qbytes = %d\n", buf.msg_qbytes);
(void) fprintf(stderr, "msg_qnum = %d\n", buf.msg_qnum);
(void) fprintf(stderr, "msg_lspid = %d\n", buf.msg_lspid);
(void) fprintf(stderr, "msg_lrpid = %d\n", buf.msg_lrpid);
(void) fprintf(stderr, "msg_stime = %s", buf.msg_stime ? ctime(&buf.msg_stime) : "Not Set\n");
(void) fprintf(stderr, "msg_rtime = %s", buf.msg_rtime ? ctime(&buf.msg_rtime) : "Not Set\n");
(void) fprintf(stderr, "msg_ctime = %s",ctime(&buf.msg_ctime)); 
if (cmd == IPC_STAT)
break;
(void) fprintf(stderr, "Enter msg_perm.uid: ");
(void) scanf ("%hi", &buf.msg_perm.uid);
(void) fprintf(stderr, "Enter msg_perm.gid: ");
(void) scanf("%hi", &buf.msg_perm.gid);
(void) fprintf(stderr, "%s\n", warning_message);
(void) fprintf(stderr, "Enter msg_perm.mode: ");
(void) scanf("%hi", &buf.msg_perm.mode);
(void) fprintf(stderr, "Enter msg_qbytes: ");
(void) scanf("%hi", &buf.msg_qbytes);
do_msgctl(msqid, IPC_SET, &buf);
break;
case IPC_RMID:
default:
do_msgctl(msqid, cmd, (struct msqid_ds *)NULL);
break;
}
exit(0);
}
static void
do_msgctl(msqid, cmd, buf)
struct msqid_ds *buf; 
int cmd,msqid; 
{
register int rtrn; 
(void) fprintf(stderr, "\nmsgctl: Calling msgctl(%d,%d, %s)\n",msqid, cmd, buf ? "&buf" : "(struct msqid_ds*)NULL");
 rtrn = msgctl(msqid, cmd, buf); 
if (rtrn == -1) 
{
perror("msgctl: msgctl failed");
exit(1);
}
else 
{
(void) fprintf(stderr, "msgctl: msgctl returned %d\n",rtrn);
}
}
