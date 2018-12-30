package romanum;
import java.util.Scanner;
public class Romanum { 
 private String exchange(int starget){
	char one,five,ten;
	String output = new String();
	one = 'I';
	five = 'V';
    ten = 'X';
	switch (starget){
	 case 1: output=one;
	         return output;
     case 5:output=five;
	        return output;	 
	}
	if (starget<5){
		if
	}
 }
 private String exchange(int starget,int dtarget){
	 
 }
 private String exchange(int starget,int dtarget,int ttarget){
	 
 }
 private String checkdigit(Integer target) {
   if (target<10){
	   exchange(target);
   }if(target<100){
	  exchange(target/10,target%10); 
   }if(target<1000){
	  enchange(target/100,target%100-target/10,target%100-(target/10)*10);
   }else{
	   return 'M';
   }
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
