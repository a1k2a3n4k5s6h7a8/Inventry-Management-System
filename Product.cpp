#include "product.h"
#include <iostream>

// Default constructor: Initializes variables with default values
Product::Product() {
    id = 0;
    name = "";
    category = "";
    price = 0.0;
    quantity = 0;
    supplier = "";
}

// Parameterized constructor: Initializes variables with custom values
Product::Product(int newId, std::string newName, std::string newCategory, 
                 double newPrice, int newQuantity, std::string newSupplier) {
    id = newId;
    name = newName;
    category = newCategory;
    price = newPrice;
    quantity = newQuantity;
    supplier = newSupplier;
}

// Getters: Return the private member variables
int Product::getId() {
    return id;
}

std::string Product::getName() {
    return name;
}

std::string Product::getCategory() {
    return category;
}

double Product::getPrice() {
    return price;
}

int Product::getQuantity() {
    return quantity;
}

std::string Product::getSupplier() {
    return supplier;
}

// Setters: Assign new values to the private member variables
void Product::setId(int newId) {
    id = newId;
}

void Product::setName(std::string newName) {
    name = newName;
}

void Product::setCategory(std::string newCategory) {
    category = newCategory;
}

void Product::setPrice(double newPrice) {
    price = newPrice;
}

void Product::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

void Product::setSupplier(std::string newSupplier) {
    supplier = newSupplier;
}

// Display function: Prints the product information to the console
void Product::display() {
    std::cout << "ID: " << id << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Category: " << category << "\n";
    std::cout << "Price: $" << price << "\n";
    std::cout << "Quantity: " << quantity << "\n";
    std::cout << "Supplier: " << supplier << "\n";
    std::cout << "---------------------------\n";
}