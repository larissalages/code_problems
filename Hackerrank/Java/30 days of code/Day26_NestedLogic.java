import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int d1 = sc.nextInt();
        int m1 = sc.nextInt();
        int y1 = sc.nextInt();
        int d2 = sc.nextInt();
        int m2 = sc.nextInt();
        int y2 = sc.nextInt();
        if(y1 > y2)
            System.out.println(10000);
        else if(y1==y2 && m1 > m2)
            System.out.println(500 * (m1-m2));
        else if(y1==y2 && m1==m2 && d1 > d2)
            System.out.println(15 * (d1-d2));
        else
            System.out.println(0);
    }
}
