import java.util.Scanner;
public class InsertionSort
{
    private static void insertionSort(int array[], int size){
        for (int i = 1; i < size; i++){
            int key = array[i];
            int j = i -1;
            while ( j >= 0 && array[j] > key) {
                array[j+1] = array[j];
                j = j - 1;
            }
            array[j+1] = key;
        }
    }
    
    private static void printArray(int array[]) {
        for(int i = 0; i < array.length;i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }
    
	public static void main(String[] args) {
	    Scanner scan = new Scanner(System.in);
	    try {
	        int i,n;
	        System.out.println("How many elements do you want in the array?");
            n=scan.nextInt();
            int a[]= new int[n];
            System.out.println("Enter the array elements one by one");

            for(i=0;i<n;i++)
            {
                a[i]=scan.nextInt();
            }
            System.out.println("Array before sorting is:");
            printArray(a);
            System.out.println("Array before sorting is:");
            insertionSort(a, a.length);
            printArray(a);
	        
	    } catch(Exception e) {e.printStackTrace();}
        scan.close();
	}
}