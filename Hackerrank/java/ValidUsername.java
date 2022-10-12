import java.io.*;
import java.util.*;

public class ValidUsername {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());//taking number of testcases as input
        
        for(int i=0;i<t;i++){
            boolean result = false;
            String str = sc.nextLine();//taking testcases as input
          //checking the conditions
            if(str.length()>=8 && str.length()<=30){
                if(Character.isAlphabetic(str.charAt(0))){
                    if(str.matches("[a-zA-Z0-9_]+")){
                        result = true;
                    }
                }
            }
          //Printing the result
            if(result){
            System.out.println("Valid");
            }else{
                System.out.println("Invalid");
            }
        }
        
    }
}
