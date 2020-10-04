import java.util.Scanner;

public class BubbleSort {
    public static void main(String args[]){
        Scanner scan= new Scanner(System.in);
        try{
            int low,high;
            int n,i;
            System.out.println("How many elements do you want in the array?");
            n=scan.nextInt();
            int a[]= new int[n];
            System.out.println("Enter the array elements one by one");

            for(i=0;i<n;i++)
            {
                a[i]=scan.nextInt();
            }
            System.out.println("Array before sorting is:");
            printArray(a, n);
            low=0;
            high=n-1;

            MergeSort obj = new MergeSort();
            obj.sort(a, low, high);
            System.out.println();

            System.out.println("The sorted array is: ");
            printArray(a, n);

        }catch(Exception e){e.printStackTrace();}
        scan.close();
    }

    private static void printArray(int array[], int size){
        for(int i=0; i < size; i++){
            System.out.println(array[i]);
        }
        System.out.println("\n");
    }

    private static void bubbleSort(int array[], int size){
        for(int i=0; i < size - 1; i++){
            for(int j=0; j < size - i - 1; j++){
                if(array[j] > array[j+1]){
                    swap(array[j], array[j+1]);
                }
            }
        }
    }

    private static void swap(int a, int b){
        int temp = a;
        a = b;
        b = temp;
    }
}

