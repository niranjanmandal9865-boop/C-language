#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 5

typedef struct {
    char name[50];
    float price;
    int stock;
} Product;

void displayProducts(Product products[], int size) {
    printf("Available Products:\n");
    for(int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f (Stock: %d)\n", i+1, products[i].name, products[i].price, products[i].stock);
    }
}

int main() {
    Product products[MAX_PRODUCTS] = {
        {"Laptop", 800.0, 5},
        {"Smartphone", 500.0, 10},
        {"Headphones", 50.0, 15},
        {"Keyboard", 30.0, 20},
        {"Mouse", 20.0, 25}
    };

    int choice;
    int cart[MAX_PRODUCTS] = {0};
    float total = 0;

    printf("Welcome to the C E-Commerce Store!\n");

    while(1) {
        displayProducts(products, MAX_PRODUCTS);
        printf("Enter product number to add to cart (0 to checkout): ");
        scanf("%d", &choice);

        if(choice == 0) break;
        if(choice < 1 || choice > MAX_PRODUCTS) {
            printf("Invalid choice!\n");
            continue;
        }

        int index = choice - 1;
        if(products[index].stock > 0) {
            cart[index]++;
            products[index].stock--;
            total += products[index].price;
            printf("%s added to cart.\n", products[index].name);
        } else {
            printf("Sorry, %s is out of stock.\n", products[index].name);
        }
    }

    printf("\nCheckout:\n");
    for(int i = 0; i < MAX_PRODUCTS; i++) {
        if(cart[i] > 0) {
            printf("%s x%d - $%.2f\n", products[i].name, cart[i], products[i].price * cart[i]);
        }
    }
    printf("Total Amount: $%.2f\n", total);
    printf("Thank you for shopping!\n");

    return 0;
}
