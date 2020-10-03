public class QuickSort{

    public static int partition(int[] arr, int low, int high){
        int pivot = arr[high]; // taking pivot at rightmost pos
        int start_ptr = low - 1;
        for(int i = low; i < high; i++){
            if(arr[i] < pivot){
                start_ptr++;
                
                int tmp = arr[i];
                arr[i] = arr[start_ptr];
                arr[start_ptr] = tmp;
            }
        }

        // swaping the last element i.e. "pivot"
        int temp = arr[high];
        arr[high] = arr[start_ptr + 1];
        arr[start_ptr + 1] = temp;

        return start_ptr + 1;
    }

    public static void sort(int[] arr, int low, int high){
        if(low < high){
            int pi_index = partition(arr, low,high);
            
            partition(arr, low, pi_index - 1);
            partition(arr, pi_index + 1, high);
        }
    }

}