#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
char s[100];
gets(s);
//printf("%s",s);
FILE *fp;
if((fp=fopen(s,"r"))==NULL)
return 1;
int fn=0;
fn=fileno(fp);
struct stat sta;
if(fstat(fn,&sta) < 0) return 1;
printf("File size : %ld\n",(long)sta.st_size);
printf("File INode Number : %ld\n",sta.st_ino);
printf("File UID : %ld\n",(long)sta.st_uid);
printf("File GID : %ld\nA",(long)sta.st_gid);
printf("File Permissions: \t");
printf( (S_ISDIR(sta.st_mode)) ? "d" : "-");
printf( (sta.st_mode & S_IRUSR) ? "r" : "-");
printf( (sta.st_mode & S_IWUSR) ? "w" : "-");
printf( (sta.st_mode & S_IXUSR) ? "x" : "-");
printf( (sta.st_mode & S_IRGRP) ? "r" : "-");
printf( (sta.st_mode & S_IWGRP) ? "w" : "-");
printf( (sta.st_mode & S_IXGRP) ? "x" : "-");
printf( (sta.st_mode & S_IROTH) ? "r" : "-");
printf( (sta.st_mode & S_IWOTH) ? "w" : "-");
printf( (sta.st_mode & S_IXOTH) ? "x" : "-");
printf("\n\n");
printf("File type: ");
switch (sta.st_mode & S_IFMT)
{
case S_IFBLK:
printf("block device\n");
break;
case S_IFCHR:
printf("character device\n");
break;
case S_IFDIR:
printf("directory\n");
break;
case S_IFIFO:
printf("FIFO/pipe\n");
break;
case S_IFLNK:
printf("symlink\n");
break;
case S_IFREG:
printf("regular file\n");
break;
case S_IFSOCK:
printf("socket\n");
break;
default:
printf("unknown?\n");
break;
}
return 0;
}
