#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Product {
public:
    Product(const std::string& name, int stock, double price)
        : name(name), stock(stock), price(price) {}

    const std::string& getName() const { return name; }
    int getStock() const { return stock; }
    double getPrice() const { return price; }
    double inventoryValue() const { return stock * price; }

private:
    std::string name;
    int stock;
    double price;
};

class Warehouse {
public:
    void addProduct(const std::string& name, int stock, double price) {
        products.emplace_back(name, stock, price);
    }

    void printInventory() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Warehouse Inventory\n";
        std::cout << "===================\n";

        double total = 0.0;

        for (const auto& product : products) {
            std::cout << product.getName()
                      << " | Stock: " << product.getStock()
                      << " | Price: $" << product.getPrice()
                      << " | Value: $" << product.inventoryValue()
                      << std::endl;
            total += product.inventoryValue();
        }

        std::cout << "===================\n";
        std::cout << "Total Inventory Value: $" << total << std::endl;
    }

private:
    std::vector<Product> products;
};

int main() {
    Warehouse warehouse;

    warehouse.addProduct("Laptop", 12, 899.99);
    warehouse.addProduct("Keyboard", 35, 59.50);
    warehouse.addProduct("Mouse", 48, 24.95);
    warehouse.addProduct("Webcam", 20, 79.90);

    warehouse.printInventory();

    return 0;
}
