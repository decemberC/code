package errortry;

import java.util.Scanner;
import java.io.IOException;

public class errortry{
 public static void main(String[] args){
 Scanner inputer = new Scanner(System.in);
 int load;
 try{
  load = inputer.nextInt();
 }
 catch (Exception e){
  System.err.println("Error! input must be string");
 }
 inputer.close();
}
}