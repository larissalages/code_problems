void main() {
  List<int> array = <int>[10, -4, 7, 3, 1, 0, 2, 6, 99];
  BubbleSort(array);

  for (int i = 0; i < array.length - 1; i++) print(array[i]);
}

List<int> BubbleSort(List<int> list) {
  print("Bubble Sort: ");
  for (int i = 0; i < list.length; i++) {
    for (int j = 0; j < list.length - 1; j++) {
      if (list[j] > list[j + 1]) {
        int num = list[j];
        list[j] = list[j + 1];
        list[j + 1] = num;
      }
    }
  }
  return list;
}
