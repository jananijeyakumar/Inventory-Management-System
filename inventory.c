#include <stdio.h>
#include <string.h>

#define MAX 100

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Product inventory[MAX];
int count = 0;

// Function prototypes
void addProduct();
void displayProducts();
void searchProduct();
void updateProduct();
void deleteProduct();
void lowStock();
void sortProducts();

int main() {
    int choice;

    while (1) {
        printf("\n===== Inventory Management System =====\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Low Stock Alert\n");
        printf("7. Sort Products by Quantity\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: searchProduct(); break;
            case 4: updateProduct(); break;
            case 5: deleteProduct(); break;
            case 6: lowStock(); break;
            case 7: sortProducts(); break;
            case 8: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

// Add Product
void addProduct() {
    if (count >= MAX) {
        printf("Inventory full!\n");
        return;
    }

    printf("Enter Product ID: ");
    scanf("%d", &inventory[count].id);

    printf("Enter Product Name: ");
    scanf("%s", inventory[count].name);

    printf("Enter Quantity: ");
    scanf("%d", &inventory[count].quantity);

    printf("Enter Price: ");
    scanf("%f", &inventory[count].price);

    count++;
    printf("Product added successfully!\n");
}

// Display Products
void displayProducts() {
    if (count == 0) {
        printf("No products available.\n");
        return;
    }

    printf("\nID\tName\tQty\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%.2f\n",
               inventory[i].id,
               inventory[i].name,
               inventory[i].quantity,
               inventory[i].price);
    }
}

// Search Product
void searchProduct() {
    int id, found = 0;

    printf("Enter Product ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Product Found:\n");
            printf("ID: %d\nName: %s\nQty: %d\nPrice: %.2f\n",
                   inventory[i].id,
                   inventory[i].name,
                   inventory[i].quantity,
                   inventory[i].price);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Product not found!\n");
}

// Update Product
void updateProduct() {
    int id, found = 0;

    printf("Enter Product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Enter new Name: ");
            scanf("%s", inventory[i].name);

            printf("Enter new Quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("Enter new Price: ");
            scanf("%f", &inventory[i].price);

            printf("Product updated!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Product not found!\n");
}

// Delete Product
void deleteProduct() {
    int id, found = 0;

    printf("Enter Product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            count--;
            printf("Product deleted!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Product not found!\n");
}

// Low Stock Alert
void lowStock() {
    int threshold;

    printf("Enter low stock threshold: ");
    scanf("%d", &threshold);

    printf("\nLow Stock Products:\n");
    for (int i = 0; i < count; i++) {
        if (inventory[i].quantity < threshold) {
            printf("%s (Qty: %d)\n",
                   inventory[i].name,
                   inventory[i].quantity);
        }
    }
}

// Sort Products by Quantity
void sortProducts() {
    struct Product temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (inventory[j].quantity > inventory[j + 1].quantity) {
                temp = inventory[j];
                inventory[j] = inventory[j + 1];
                inventory[j + 1] = temp;
            }
        }
    }

    printf("Products sorted by quantity!\n");
}