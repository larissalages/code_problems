//This Algorithm is called as Kadane's Algorithm 
//Contributed by MohammedJunaid02
//Simple Explaination along with 2 sample I/P and O/P is given below

import java.util.*;
import java.io.*;
public class Kadanes_Algo {
    public static void main(String[] args)
    {
        int[] arr = {-2, -3, 4, -1, -2, 1, 5, -3 };
        System.out.println("Maximum contiguous sum is " + maxSubArraySum(arr));
    }
    private static int maxSubArraySum(int[] arr) {
        int maximumSum = Integer.MIN_VALUE;
        int currentSum = 0;

        for (int i = 0; i < arr.length ; i++) {
            currentSum += arr[i];

            if (currentSum > maximumSum) {
            maximumSum = currentSum;
            }

            if (currentSum < 0) {
            currentSum = 0;
            }
        }

        return maximumSum;
    }
}


// Example 1:
// Input:
//        N = 5
//        Arr[] = {1,2,3,-2,5}
// Output:
//        9
// Explanation:
//         Max subarray sum is 9
//         of elements (1, 2, 3, -2, 5) which 
//         is a contiguous subarray.

// Example 2:
// Input:
//       N = 4
//       Arr[] = {-1,-2,-3,-4}
// Output:
//       -1
// Explanation:
//             Max subarray sum is -1 
//             of element (-1)