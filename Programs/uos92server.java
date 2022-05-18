import java.net.*;
import java.io.*;
class uos92server
{
public static void main(String []args)throws Exception
{
ServerSocket ss=new ServerSocket(5000);
while(true)
{
Socket s=ss.accept();
DataOutputStream dos=new DataOutputStream(s.getOutputStream());
DataInputStream dis=new DataInputStream(s.getInputStream());
dos.writeUTF("Welcomes u");
String cnm=dis.readUTF();
ThrdComm a=new ThrdComm(dos,dis,cnm);
}
}
}
class ThrdComm extends Thread
{
DataOutputStream dos;
DataInputStream dis;
BufferedReader br;
String str,cnm;
ThrdComm(DataOutputStream dos,DataInputStream dis,String cnm)throws Exception
{
super(cnm);
this.dos=dos;
this.dis=dis;
this.cnm=cnm;
br=new BufferedReader(new InputStreamReader(System.in));
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
System.out.println("Message To"+" "+cnm+":");
str=br.readLine();
dos.writeUTF(str);//sends msg to Client
str=dis.readUTF();//reads msg from client
System.out.println("From Client:"+" "+str);
}
}
