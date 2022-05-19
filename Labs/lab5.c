#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fill(int * arr, int n)
{
  for (int i = 0; i < n; i++)
    arr[i] = rand() % 101 - 50;
}

void out(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%4d", arr[i]);
  printf("\n");
}

int find_count(int a[], int b[], int n1, int n2)
{
  int count = 0, flag = 0;
  for (int i = 0; i < n1; i++)
  {
    flag = 0;
    for (int j = 0; j < n2; j++)
    {
        for (int l = 0; l < i; l++)
          if (a[i] == a[l])
          {
            flag = 1;
            break;
          }
        if (flag) break;
        if (a[i] == b[j])
        {
          count++;
          break;
        }
    }
  }
  return count;
}

void find_rep(int rep[], int a[], int b[], int n1, int n2)
{
  int count = 0, flag = 0;
  for (int i = 0; i < n1; i++)
  {
    flag = 0;
    for (int j = 0; j < n2; j++)
    {
      for (int l = 0; l < i; l++)
        if (a[i] == a[l])
        {
          flag = 1;
          break;
        }
      if (flag) break;
      if (a[i] == b[j])
      {
        rep[count++] = a[i];
        break;
      }
    }
  }
}

int main()
{
  int n1, n2;
  srand(time(NULL));
  printf("Введите длинну первого массива: ");
  scanf("%d", &n1);
  printf("Введите длинну второго массива: ");
  scanf("%d", &n2);
  int a[n1], b[n2];
  fill(a, n1);
  fill(b, n2);
  printf ("Первый массив:\n");
  out(a, n1);
  printf ("Второй массив:\n");
  out(b, n2);
  int count = find_count(a, b, n1, n2);
  if (!count)
    printf("Нет повторяющихся элементов\n");
  else
  {
    printf ("Повторяющиеся элементы:\n");
    int rep[count];
    find_rep(rep, a, b, n1, n2);
    out(rep, count);
  }
  return 0;
}
