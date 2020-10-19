void Quicksort(list, int leftElement, int rightElement) {
  int left = leftElement;
  int right = rightElement;
  int pivot = list[(leftElement + rightElement) ~/ 2];

  while (left <= right) {
    while (list[left] < pivot) {
      left++;
    }

    while (list[right] > pivot) {
      right--;
    }

    if (left <= right) {
      int temp = list[left];
      list[left] = list[right];
      list[right] = temp;
      left++;
      right--;
    }
  }

  if (leftElement < right) {
    Quicksort(list, leftElement, right);
  }

  if (left < rightElement) {
    Quicksort(list, left, rightElement);
  }
}
