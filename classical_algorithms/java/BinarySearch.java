import java.util.Scanner;
public class Main {
    private static int binarySearch(int arr[], int x) { 
        int l = 0, r = arr.length - 1; 
        while (l <= r) { 
            int m = l + (r - l) / 2; 
            // Check if x is present at mid 
            if (arr[m] == x) 
                return m; 
            // If x greater, ignore left half 
            if (arr[m] < x) 
                l = m + 1; 
            // If x is smaller, ignore right half 
            else
                r = m - 1; 
        } 
        // if we reach here, then element was 
        // not present 
        return -1; 
    } 
	public static void main(String[] args) {
	Scanner scan = new Scanner(System.in);
	    try {
            int i,n,x, last;
	        System.out.println("How many elements do you want in the array?");
            n=scan.nextInt();
            int a[]= new int[n];
            System.out.println("Enter the array elements one by one");
            for(i=0;i<n;i++)
            {
                a[i]=scan.nextInt();
            }
            System.out.println("Enter Element to found");
            x = scan.nextInt();
            last = a.length -1 ;
            int result = binarySearch(a, x);
		    if (result == -1) 
                System.out.println("Element not present"); 
            else
                System.out.println("Element found at "
                               + "index " + result); 
        } catch(Exception e) {e.printStackTrace();}
        scan.close();
    }
}
