#include "../include/functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Item* CreateInventory(int size) { return (Item*)malloc(size * sizeof(Item)); }

void AddItem(Item* inv, int index, char* name, float price, int quantity) {
  snprintf(inv[index].name, sizeof(inv[index].name), "%s", name);
  inv[index].name[49] = '\0';
  inv[index].price = price;
  inv[index].quantity = quantity;
}

float CalculateTotalValue(Item* inv, int size) {
  float total_result = 0;

  for (int i = 0; i < size; i++) {
    total_result += inv[i].price * inv[i].quantity;
  }
  return total_result;
}
