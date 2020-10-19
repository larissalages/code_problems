import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int N = scanner.nextInt();
        String[] newArr = new String[N];
        int c=0;
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int NItr = 0; NItr < N; NItr++) {
            String[] firstNameEmailID = scanner.nextLine().split(" ");

            String firstName = firstNameEmailID[0];
            String emailID = firstNameEmailID[1];
            if(emailID.endsWith("@gmail.com"))
            {
                newArr[c] = firstName;
                c++;
            }
        }

        String[] arr = new String[c];
        for(int i=0; i<c; i++)
            arr[i] = newArr[i];

        Arrays.sort(arr);
        Arrays.toString(arr);

        for(int i=0; i<c; i++)
            System.out.println(arr[i]);

        scanner.close();
    }
}
