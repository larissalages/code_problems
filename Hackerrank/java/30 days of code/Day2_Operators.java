import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static void solve(double meal_cost, int tip_percent, int tax_percent) {
        double tip_percent1 = tip_percent;
        double tax_percent1 = tax_percent;
        double tip, tax, total_cost;

        tip = meal_cost * (tip_percent1/100);
        tax = meal_cost * (tax_percent1/100);
        total_cost = meal_cost + tip + tax;

        System.out.println(Math.round(total_cost));
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        double meal_cost = scanner.nextDouble();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int tip_percent = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int tax_percent = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        solve(meal_cost, tip_percent, tax_percent);

        scanner.close();
    }
}
