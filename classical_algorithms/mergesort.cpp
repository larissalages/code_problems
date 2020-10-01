void merge(int a[], int l, int m, int r)
{
  int l1 = m - l + 1;
  int l2 = r - m;

  int temp1[l1];
  int temp2[l2];

  for (int i = 0; i < l1; i++)
  {
    temp1[i] = a[l + i];
  }
  for (int j = 0; j < l2; j++)
  {
    temp2[j] = a[m + j + 1];
  }
  int i = 0;
  int j = 0;
  int k = l;

  while (i < l1 && j < l2)
  {
    if (temp1[i] < temp2[j])
    {
      a[k] = temp1[i];
      i++;
    }

    else
    {
      a[k] = temp2[j];
      j++;
    }

    while (i < l1)
    {
      a[k] = temp1[i];
      i++;
      k++;
    }

    while (j < l2)
    {
      a[k] = temp2[j];
      j++;
      k++;
    }
  }
}

void mergesort(int a[], int l, int r)
{
  if (l < r)
  {
    int m = r + (l - r) / 2;

    mergesort(a, l, m);
    mergesort(a, m + 1, r);

    merge(a, l, m, r);
  }
}