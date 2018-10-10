import java.util.Scanner;
//this scrip is used to try can we write nothing in while black and try while loop
public class looptry{
 static Scanner in = new Scanner(System.in);
 private static boolean looper(){
	 if (!in.hasNext("i love u")){	 
     return false;
   } else{return true;}
 }
 public static void main(String[] args){
 while(looper()){
 }
 }

}