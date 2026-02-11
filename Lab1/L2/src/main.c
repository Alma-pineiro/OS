#include <stdio.h>
#include <stdlib.h>

#include "../include/functions.h"

int main(int argc, char* argv[]) {
  int n = atoi(argv[1]);
  Item* inv = CreateInventory(n);

  for (int i = 0; i < n; i++) {
    char name[50];
    float price;
    int quantity;

    scanf("%s %f %d", name, &price, &quantity);
    AddItem(inv, i, name, price, quantity);
  }

  float total_inv_value = CalculateTotalValue(inv, n);
  printf("Total Inventroy Value %.2f\n", total_inv_value);
}