#include <stdio.h>

int main()
{
  int n, array[1000], c, d, t, flag = 0;

  printf("nhap so phan tu: ");
  scanf("%d", &n);

  printf("nhap %d so nguyen: ", n);

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  for (c = 1 ; c <= n - 1; c++) {
    t = array[c];

    for (d = c - 1 ; d >= 0; d--) {
      if (array[d] > t) {
        array[d+1] = array[d];
        flag = 1;
      }
      else
        break;
    }
    if (flag)
      array[d+1] = t;
  }

  printf("danh sach sau khi sap xep la: \n");

  for (c = 0; c <= n - 1; c++) {
    printf("%d ", array[c]);
  }

  return 0;
}