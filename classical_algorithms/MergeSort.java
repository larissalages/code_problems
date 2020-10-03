import java.util.*;


class MergeSort
{

	public void sort(int a[], int low, int high)
	{
		if(low<high)
		{
			int mid=(low+high)/2;
			sort(a,low,mid);
			sort(a,mid+1,high);
			merge(a,low,mid,high);
		}
	}

	public void merge(int a[], int low, int mid, int high)
	{
		int h=low, i=low, j=mid+1,k;
		int b[]=new int[high+1];

		while((h<=mid) && (j<=high))
		{
			if(a[h]<a[j])
			{
				b[i]=a[h];
				h=h+1;
			}
			else
			{
				b[i]=a[j];
				j=j+1;
			}
		i=i+1;
		}


		if(h>mid)
		{
			for(k=j;k<=high;k++)
			{
				b[i]=a[k];
				i=i+1;
			}
		}


		if(j>high)
		{
			for(k=h;k<=mid;k++)
			{
				b[i]=a[k];
				i=i+1;
			}
		}

		for(k=low;k<=high;k++)
		{
			a[k]=b[k];
		}
	}

   	static void printArray(int a[], int n)
	{
	
		for(int i=0;i<n;i++)
		{
			System.out.print( a[i]+ "\t");
		}
	}

 	public static void main(String args[])
	{
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
}





