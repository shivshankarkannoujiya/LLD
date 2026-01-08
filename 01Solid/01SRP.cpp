#include <iostream>
#include <vector>
using namespace std;

class Product{

public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};

// Voilating SRP:
// ShoppingCart handling multiple responsibility

class ShoppingCart{

private:
    vector<Product *> products;

public:
    void addProductToCart(Product *p){
        products.push_back(p);
    }

    const vector<Product *> &getProducts(){
        return products;
    }

    // Calculate total price in cart
    double calculateTotal(){
        double total = 0;
        for (auto p : products){
            total += p->price;
        }
        return total;
    }

    // voilating
    void printInvoice(){
        cout << "=== Shopping Cart Invoice ===" << endl;
        for(auto p : products){
            cout << p->name << " - $" << p->price << endl;
        }
        cout << "Total: $" << calculateTotal() << endl;
    }

    // voilating
    void saveToDatabase(){
        cout << "Saving shopping cart to database..." << endl;
    }

};


int main(){
    ShoppingCart *cart = new ShoppingCart();

    cart->addProductToCart(new Product("Laptop", 100000));
    cart->addProductToCart(new Product("Mouse", 1000));

    cart->printInvoice();
    cart->saveToDatabase();

    return 0;
}