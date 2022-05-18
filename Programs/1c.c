/*#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
    fork(); 
    printf("Hello world!\n"); 
    return 0; 
}
*//*
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
void forkexample() 
{ 
	
	if (fork() == 0) 
		printf("Hello from Child!\n"); 
	else
		printf("Hello from Parent!\n"); 
} 
int main() 
{ 
	forkexample(); 
	return 0; 
}

*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    int n =10;
    pid_t pid = vfork(); 
    if (pid == 0)         
    {
        printf("Child process started\n");
    }
    else
    {
        printf("Now i am coming back to parent process\n");
    }
    printf("value of n: %d \n",n);
    return 0;
}
