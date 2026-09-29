#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

// The Product class stores details of a single item in the inventory.
class Product {
private:
    // Member variables to store product details
    int id;
    std::string name;
    std::string category;
    double price;
    int quantity;
    std::string supplier;

public:
    // Default constructor (sets default values)
    Product();

    // Constructor to initialize a product with values
    Product(int newId, std::string newName, std::string newCategory, 
            double newPrice, int newQuantity, std::string newSupplier);

    // Getters - functions to get the values of private variables
    int getId();
    std::string getName();
    std::string getCategory();
    double getPrice();
    int getQuantity();
    std::string getSupplier();

    // Setters - functions to change the values of private variables
    void setId(int newId);
    void setName(std::string newName);
    void setCategory(std::string newCategory);
    void setPrice(double newPrice);
    void setQuantity(int newQuantity);
    void setSupplier(std::string newSupplier);

    // Function to print the product details to the screen
    void display();
};

#endif // PRODUCT_H