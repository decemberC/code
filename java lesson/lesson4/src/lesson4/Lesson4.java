package lesson4;

public class Lesson4 {
 public int flooping(int i){
	 int x = 1;
	 for(i = i;i>0;i--){
		if (x*i >= 10000){
		  System.out.println("This function can't process the number that over 10 thousand");
		  break;
		}else{
			x=x*i;
		}
	 }
	return x;
 }
 public void wflooping(int i){
	 int result = 1;
	 while(i<10 && i>0){
	  if (result*i >= 10000){
			  System.out.println("This function can't process the number that over 10 thousand");
			  break;
			}else{
				result=result*i;
				i--;
			}
	 }
	  System.out.println(result);
	  System.out.println(i);
 }
}
