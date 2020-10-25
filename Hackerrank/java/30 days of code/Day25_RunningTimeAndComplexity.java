import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int n  = sc.nextInt();
        for(int i=0; i<n; i++)
        {
            int c = 0;
            int p = sc.nextInt();
            if(p==1)
                System.out.println("Not prime");
            for(int j=2; j*j<=p;j++)
            {
                if(p%j==0)
                {
                    System.out.println("Not prime");
                    c++;
                    break;
                }
            }
            if(c==0 && p!=1)
                System.out.println("Prime");
        }
    }
}
