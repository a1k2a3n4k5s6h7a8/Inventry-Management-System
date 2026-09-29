#ifndef INVENTORY_H
#define INVENTORY_H

#include "product.h"
#include <vector>
#include <string>

// The Inventory class manages a collection of products.
class Inventory {
private:
    // A list (vector) to store all the products in stock
    std::vector<Product> products;

public:
    // Adds a new product to the inventory
    void addProduct(Product newProduct);

    // Displays all products in the inventory
    void displayProducts();

    // Searches for a product by its ID and prints its details
    void searchProduct(int id);

    // Updates the details of a product with the given ID
    void updateProduct(int id);

    // Deletes a product from the inventory by its ID
    void deleteProduct(int id);

    // Saves the inventory data to a text file
    void saveToFile(std::string filename);

    // Loads the inventory data from a text file
    void loadFromFile(std::string filename);
};

#endif // INVENTORY_H