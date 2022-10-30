// Problem site: https://www.codewars.com/kata/63579823d25aad000ecfad9f/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

long long pg_approach(unsigned);

long calculate(int j, int i)
{
  return (2 * j + i + 1) * pow(-1, 2 * j + i);
}
long brute_force(int n)
{
  n++;
  int start_point = 0;
  int total_sum = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = start_point; j < n; j++)
    {
      int triangle_elt = calculate(i, j);
      total_sum += triangle_elt;
    }
    start_point++;
  }
  return total_sum;
}
long long get_sum(unsigned n)
{
  return pg_approach(n);
}

long long pg_approach(unsigned n)
{
  long long results[n];
  memset(results, 0, n);
  results[0] = 1;
  results[1] = 5;
  if (n == 0)
    return 1;
  if (n == 1)
    return -5;
  unsigned current_col = 1;
  long long increase_factor = 4;
  while (current_col < n)
  {
    current_col++;
    if (!(current_col % 2))
      increase_factor += 1;
    else
      increase_factor += 3;
    results[current_col] = increase_factor + results[current_col - 1];
  }
  return (current_col % 2) ? (-1) * results[current_col] : results[current_col];
}
int main()
{
  for (int i = 0; i < 10; i++)
    printf("\nteste %d:\n\tBrute force: %ld , PG: %lld", i, brute_force(i), pg_approach(i));
  return 0;
}