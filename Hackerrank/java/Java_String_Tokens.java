import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine().trim();

        String[] str = s.split("[ !,?._'@]+");
        int l = str.length;
        if(s.compareTo("")==0)
            System.out.println(0);
        else
        {
            System.out.println(l);
            for(int i=0;i<l;i++)
                System.out.println(str[i]);
        }
        scan.close();
    }
}
