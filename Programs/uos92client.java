import java.net.*;
import java.io.*;
class uos92client extends Thread
{
public static void main(String []args)throws Exception
{
if(args.length!=1)
return;
uos92client a=new uos92client(args[0]);
}
uos92client(String s1)throws Exception
{
super(s1);//naming to thread
s=new Socket("localhost",5000);
dos=new DataOutputStream(s.getOutputStream());
dis=new DataInputStream(s.getInputStream());
br=new BufferedReader(new
InputStreamReader(System.in)); 
cnm=s1;//set aurgument as
String  str="";
str=dis.readUTF();//reads msg send by server
System.out.println("From Server:"+" "+str);
dos.writeUTF(cnm);//client sends its name to server
start();
}
public void run()
{
while(true)
{
try
{
talk();
}
catch(Exception e){}
}
}
synchronized void talk()throws Exception
{
str=dis.readUTF();//msg from server
System.out.println("From Server:"+" "+str);
System.out.println("Message to Server:");
str=br.readLine();
dos.writeUTF(str);
}
Socket s;
String str,cnm;
DataOutputStream dos;
DataInputStream dis;
BufferedReader br;
}
