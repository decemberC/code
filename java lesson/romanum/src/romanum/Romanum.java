package romanum;
import java.util.Scanner;
public class Romanum { 
 private String exchange(int starget){
	 
 }
 private String exchange(int starget,int dtarget){
	 
 }
 private String exchange(int starget,int dtarget,int ttarget){
	 
 }
 private String checkdigit(Integer target) {
   
 }
 public static void main(String[] args) {
	 Romanum myself = new Romanum();
	 boolean yes = false;
	 Scanner iner = new Scanner(System.in);
	 Integer needchange = null;
	 while (!yes) {
	 try {
	  System.out.print("please enter a number between 0 to 1001: ");
	  needchange = iner.nextInt();
      if(needchange >0 && needchange<1000) {
		yes =true; 
	 }
	}catch(Exception wrongin){
		 System.out.println("Error, input should between 0 to 1001");
		 iner.next();
	}
  }
  System.out.println(myself.checkdigit(needchange));
}
}
