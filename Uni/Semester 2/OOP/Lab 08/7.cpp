#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    std::string productName;
    double price;
    int stockQuantity;

public:
    Product(const string name, double p, int quantity): productName(name), price(p), stockQuantity(quantity) {}

    friend class InventoryManager;

    friend void applyDiscount(Product& product, double discountPercentage);

    void displayProductDetails() const {
        cout << "Product Name: " << productName << std::endl;
        cout << "Price: $" << price << std::endl;
        cout << "Stock Quantity: " << stockQuantity << std::endl;
    }
};

class InventoryManager {
public:
    void displayStockDetails(const Product& product) {
        product.displayProductDetails();
    }

    void updateStock(Product& product, int newQuantity) {
        product.stockQuantity = newQuantity;
    }
};

void applyDiscount(Product& product, double discountPercentage) {
    product.price -= product.price * (discountPercentage / 100);
}

int main() {
    Product myProduct("Laptop", 1000.00, 50);

    InventoryManager manager;

    cout << "Initial Product Details:" << std::endl;
    manager.displayStockDetails(myProduct);

    double discount = 10.0; 
    applyDiscount(myProduct, discount);


    cout << "\nUpdated Product Details after applying " << discount << "% discount:" << std::endl;
    manager.displayStockDetails(myProduct);

    manager.updateStock(myProduct, 45);
    cout << "\nUpdated Stock Quantity:" << std::endl;
    manager.displayStockDetails(myProduct);

    return 0;
}