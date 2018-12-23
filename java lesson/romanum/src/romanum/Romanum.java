package romanum;
import java.util.Scanner;
public class Romanum {
 private void change() {
  
 }
 public static void main(String[] args) {
	 boolean yes = false;
	 Scanner iner = new Scanner(System.in);
	 while (!yes) {
	 Integer needchange = null;
	 try {
	  System.out.print("please enter a number between 0 to 1001: ");
	  needchange = iner.nextInt();
      if(needchange >0 && needchange<1000) {
		yes =true; 
	 }
	}catch(Exception wrongin){
		 System.out.println("Error, input should between 0 to 1001");
		 break;
	}
  }
}
}
