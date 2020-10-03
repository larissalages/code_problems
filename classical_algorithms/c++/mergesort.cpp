void msort(int d[],int size){

 int i,j,k, result[size], mid=size/2;

 if(size==1)
 {
     return;
 }


 msort(d,mid);

 msort(&d[mid],size-mid);

 for(k=0,i=0,j=mid; i<mid && j<size; k++)
    result[k]=d[i]<d[j]?d[i++]:d[j++];

 while(i<mid)
    result[k++]=d[i++];
 while(j<size)
  result[k++]=d[j++];

 for(k=0;k<size;k++)
 {
     d[k]=result[k];
 }

}


int main()
{
    int arr[7] = {5,3,7,2,1,6,4};
    msort(arr,7);
    int i;

	for( i = 0 ; i<7 ; i++)
		printf("%d ", arr[i]);
	printf("\n");
    return 0;
}