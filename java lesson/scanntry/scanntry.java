import java.util.Scanner;
public class scanntry{
 Scanner scann = new Scanner(System.in);
 private String pass;
 public void inputer(){
  System.out.print("Please  Enter your password ");
  pass = scann.next();
 }
 public boolean inac(){ 
  System.out.print("Enter ur password to login ur ac ");
  if (scann.hasNext(pass)){
   scann.close();
   return true;
  }else{
   scann.close();
   return false;
  }
}
}