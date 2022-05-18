import java.net.*;
import java.io.*;
class uos91server
{
public static void main(String []args)throws Exception
{
ServerSocket ss=new ServerSocket(5050);
System.out.println("Server is Waiting.....");
Socket s=ss.accept();
DataOutputStream dos=new DataOutputStream(s.getOutputStream());
DataInputStream dis=new DataInputStream(s.getInputStream());
String str="Welcomes you are connected \n";
dos.writeUTF(str); 
str=dis.readUTF(); 
System.out.println("From client"+" "+str);
ss.close();
s.close();
dos.close();
dis.close();
}
}
