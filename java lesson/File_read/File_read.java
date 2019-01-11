import java.io.*;
public class File_read{
 public static void main(String[] args){
	 try{
	  File h = new File("hello world.txt");
	  FileReader iner = new FileReader("hello world.txt");
	  char[] file_info = new char[(int)h.length()];
	  for(int i = 0;i<h.length();i++){
	  file_info[i] = (char)iner.read();
	  System.out.print(file_info[i]);
	  }
	  iner.close();
	 }catch(IOException e){System.out.println("Error");}
	 
 }
}