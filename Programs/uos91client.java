import java.net.*;
import java.io.*;
class uos91client
{
public static void main(String []args)throws Exception
{
Socket s=new Socket("localhost",5050);
DataOutputStream dos=new DataOutputStream(s.getOutputStream());
DataInputStream dis=new DataInputStream(s.getInputStream());
String str=dis.readUTF(); 
System.out.println("From server"+" "+str);
str="Thank u for connecting";
dos.writeUTF(str); 
s.close();
dos.close();
dis.close();
}
}
