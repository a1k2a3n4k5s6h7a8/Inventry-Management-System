#include "inventory.h"
#include <iostream>
#include <fstream>

// Adds a product to the end of our list (vector)
void Inventory::addProduct(Product newProduct) {
    products.push_back(newProduct);
    std::cout << "Product added successfully!\n";
}

// Loops through the list and displays each product
void Inventory::displayProducts() {
    if (products.empty()) {
        std::cout << "No products in inventory.\n";
        return;
    }
    std::cout << "\n--- Inventory List ---\n";
    for (size_t i = 0; i < products.size(); i++) {
        products[i].display();
    }
}

// Searches for a product by its ID
void Inventory::searchProduct(int id) {
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i].getId() == id) {
            std::cout << "\nProduct Found:\n";
            products[i].display();
            return;
        }
    }
    std::cout << "Product with ID " << id << " not found.\n";
}

// Updates the details of a product
void Inventory::updateProduct(int id) {
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i].getId() == id) {
            std::string newName, newCategory, newSupplier;
            double newPrice;
            int newQuantity;

            // Ask the user for the new details
            std::cout << "Enter new name: ";
            std::cin.ignore(); // Clears any leftover input characters
            std::getline(std::cin, newName);

            std::cout << "Enter new category: ";
            std::getline(std::cin, newCategory);

            std::cout << "Enter new price: ";
            std::cin >> newPrice;

            std::cout << "Enter new quantity: ";
            std::cin >> newQuantity;

            std::cout << "Enter new supplier: ";
            std::cin.ignore();
            std::getline(std::cin, newSupplier);

            // Update the product values using setters
            products[i].setName(newName);
            products[i].setCategory(newCategory);
            products[i].setPrice(newPrice);
            products[i].setQuantity(newQuantity);
            products[i].setSupplier(newSupplier);

            std::cout << "Product updated successfully!\n";
            return;
        }
    }
    std::cout << "Product with ID " << id << " not found.\n";
}

// Removes a product from the list by its ID
void Inventory::deleteProduct(int id) {
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i].getId() == id) {
            // Remove the element at index i
            products.erase(products.begin() + i);
            std::cout << "Product deleted successfully!\n";
            return;
        }
    }
    std::cout << "Product with ID " << id << " not found.\n";
}

// Saves all products in the vector to a text file
void Inventory::saveToFile(std::string filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cout << "Error: Could not open file " << filename << " for writing.\n";
        return;
    }

    for (size_t i = 0; i < products.size(); i++) {
        outFile << products[i].getId() << "\n";
        outFile << products[i].getName() << "\n";
        outFile << products[i].getCategory() << "\n";
        outFile << products[i].getPrice() << "\n";
        outFile << products[i].getQuantity() << "\n";
        outFile << products[i].getSupplier() << "\n";
    }

    outFile.close();
    std::cout << "Inventory saved to " << filename << " successfully!\n";
}

// Loads products from a text file into our vector
void Inventory::loadFromFile(std::string filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cout << "No saved data found. Starting with a blank inventory.\n";
        return;
    }

    // Clear the current list before loading from the file
    products.clear();

    int id;
    std::string name;
    std::string category;
    double price;
    int quantity;
    std::string supplier;

    // Read the file line-by-line
    while (inFile >> id) {
        inFile.ignore(); // Ignore the newline after the integer ID
        std::getline(inFile, name);
        std::getline(inFile, category);
        
        inFile >> price;
        inFile >> quantity;
        inFile.ignore(); // Ignore the newline after the integer quantity
        
        std::getline(inFile, supplier);

        // Create a new product and add it to our list
        Product tempProduct(id, name, category, price, quantity, supplier);
        products.push_back(tempProduct);
    }

    inFile.close();
    std::cout << "Inventory loaded from " << filename << " successfully!\n";
}