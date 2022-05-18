import java.util.concurrent.*;
public class sem extends Thread
{
public static Semaphore semaphore = new Semaphore(1);
 public static void main(String args[])
throws Exception {
Thread1 t1 = new Thread1();
Thread2 t2 = new Thread2();
sem tm = new sem();
tm.start();
t1.start();
t2.start();
}
public void run()
{
try
{
semaphore.acquire();
for(int i=0;i<=20;i=i+2)
{
System.out.println("Even: "+i);
}
semaphore.release();
}
catch(InterruptedException exc){}
}
static class Thread1 extends Thread
{
public void run()
{
try
{
semaphore.acquire();
for(int i=1;i<=21;i=i+2)
{
System.out.println("Odd: "+i);
}
semaphore.release();
}
catch(InterruptedException exc){}
}
}
static class Thread2 extends Thread
{
public void run()
{
try
{
semaphore.acquire();
for(int i=2;i<50;i++)
{
int count = 0;
for(int j=2;j<i;j++)
{
if(i%j==0)
{
count++;
}
}
if(count==0)
System.out.println("Prime: "+i);
}
semaphore.release();
}
catch(InterruptedException exc){}
}
}
}

