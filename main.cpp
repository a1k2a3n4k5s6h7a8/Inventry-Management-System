#include "inventory.h"
#include <iostream>
#include <string>

int main() {
    Inventory myInventory;
    std::string filename = "products.txt";

    // Load data from file at startup
    myInventory.loadFromFile(filename);

    int choice = 0;
    while (choice != 7) {
        std::cout << "\n=== Inventory Management System ===\n";
        std::cout << "1. Add Product\n";
        std::cout << "2. Display Products\n";
        std::cout << "3. Search Product\n";
        std::cout << "4. Update Product\n";
        std::cout << "5. Delete Product\n";
        std::cout << "6. Save Inventory\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                std::string name;
                std::string category;
                double price;
                int quantity;
                std::string supplier;

                std::cout << "Enter Product ID (integer): ";
                std::cin >> id;
                std::cin.ignore(); // Clear the newline from input buffer

                std::cout << "Enter Product Name: ";
                std::getline(std::cin, name);

                std::cout << "Enter Category: ";
                std::getline(std::cin, category);

                std::cout << "Enter Price: ";
                std::cin >> price;

                std::cout << "Enter Quantity: ";
                std::cin >> quantity;
                std::cin.ignore(); // Clear the newline

                std::cout << "Enter Supplier Name: ";
                std::getline(std::cin, supplier);

                // Create a temporary Product and add it
                Product tempProduct(id, name, category, price, quantity, supplier);
                myInventory.addProduct(tempProduct);
                break;
            }
            case 2:
                myInventory.displayProducts();
                break;

            case 3: {
                int id;
                std::cout << "Enter Product ID to search: ";
                std::cin >> id;
                myInventory.searchProduct(id);
                break;
            }
            case 4: {
                int id;
                std::cout << "Enter Product ID to update: ";
                std::cin >> id;
                myInventory.updateProduct(id);
                break;
            }
            case 5: {
                int id;
                std::cout << "Enter Product ID to delete: ";
                std::cin >> id;
                myInventory.deleteProduct(id);
                break;
            }
            case 6:
                myInventory.saveToFile(filename);
                break;

            case 7:
                // Auto-save inventory before exiting
                std::cout << "Auto-saving inventory before exit...\n";
                myInventory.saveToFile(filename);
                std::cout << "Goodbye!\n";
                break;

            default:
                std::cout << "Invalid choice! Please enter a number between 1 and 7.\n";
                break;
        }
    }

    return 0;
}