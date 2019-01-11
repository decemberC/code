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
	 case 1: output=""+one;
	         return output;
     case 5:output=""+five;
	        return output;
     case 0: return "";			
	}
	if (starget<5){
		if(starget>3){
			output = ""+one + five;
			return output;
		}else{
			for (int i = 1;i<=starget;i++){
				output = ""+output + one;
			}
			return output;
		}
	}else{
		if (starget>8){
			output = ""+one +ten;
			return output;
		}else{
			output=""+five;
			for (int i = 1;i<=starget%5;i++){
				output=output+one;
			}
			return output;
		}
	}
 }
 private String exchange(int starget,int dtarget){
		char one,five,ten;
	String output = new String();
	one = 'X';
	five = 'L';
    ten = 'C';
	switch (starget){
	 case 1: output=""+one;
	         return output+exchange(dtarget);
     case 5:output=""+five;
	        return output+exchange(dtarget);	 
	 case 0: return "";
	}
	if (starget<5){
		if(starget>3){
			output = ""+one+five;
			return output+exchange(dtarget);
		}else{
			for (int i = 1;i<=dtarget;i++){
				output = output + one;
			}
			return output+exchange(dtarget);
		}
	}else{
		if (starget>8){
			output =""+ one +ten;
			return output+exchange(dtarget);
		}else{
			output=""+five;
			for (int i = 1;i<=starget%5;i++){
				output=output+one;
			}
			return output+exchange(dtarget);
		}
	} 
 }
 private String exchange(int starget,int dtarget,int ttarget){
			char one,five,ten;
	String output = new String();
	one = 'C';
	five = 'D';
    ten = 'M';
	switch (starget){
	 case 1: output=""+one;
	         return output+exchange(dtarget,ttarget);
     case 5:output=""+five;
	        return output+exchange(dtarget,ttarget);	 
	 case 0: return "";
	}
	if (starget<5){
		if(starget>3){
			output =""+one+five;
			return output+exchange(dtarget,ttarget);
		}else{
			for (int i = 1;i<=starget;i++){
				output = output + one;
			}
			return output+exchange(dtarget,ttarget);
		}
	}else{
		if (starget>8){
			output =""+one +ten;
			return output+exchange(dtarget,ttarget);
		}else{
			output=""+five;
			for (int i = 1;i<=starget%5;i++){
				output=output+one;
			}
			return output+exchange(dtarget,ttarget);
		}
	}  
 }
 private String checkdigit(Integer target) {
   if (target<10){
	   return exchange(target);
   }if(target<100){
	  return exchange(target/10,target%10); 
   }if(target<1000){
	  return exchange(target/100,target%100-target/10,target%100-(target/10)*10);
   }else{
	   return ""+'M';
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
	}catch(IOException wrongin){
		 System.out.println("Error, input should between 0 to 1001");
		 iner.next();
	}
  }
  System.out.println(myself.checkdigit(needchange));
}
}
