#include <iostream>
#include <vector>
using namespace std;


class Product{
    public:
        string name;
        int price;

        Product(string name, int price){
            this->name = name;
            this->price = price;
        }
};

class ShoppingCart{

    private:
        vector<Product *> products;

    public:
        void addProductToCart(Product *p){
            products.push_back(p);
        }

        const vector<Product*>& getProducts(){
            return products;
        }

        double calculateTotalPrice(){
            int totalPrice = 0;
            for(auto p : products){
                totalPrice += p->price;
            }
            return totalPrice;
        }
        
};

class ShoppingCartPrinter{

    private:
        ShoppingCart *cart;

    public:
        ShoppingCartPrinter(ShoppingCart *cart) {
            this->cart = cart;
        }

        void printInvoice(){
            cout << "=== Shopping cart Invoice ===" << endl;
            for(auto p : cart->getProducts()){
                cout << p->name << ": $" << p->price << endl;
            }
            cout << "Total Price: $" << cart->calculateTotalPrice() << endl;
        }
};

class ShoppingCartStorage {

    private:
        ShoppingCart *cart;

    public:
        ShoppingCartStorage(ShoppingCart * cart){
            this->cart = cart;
        }

        void saveToDatabse(){
            cout << "Saving shopping cart to database..." << endl;
        }
};

int main(){
    ShoppingCart *cart = new ShoppingCart();

    cart->addProductToCart(new Product("Laptop", 100000));
    cart->addProductToCart(new Product("Mouse", 1000));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage *db = new ShoppingCartStorage(cart);
    db->saveToDatabse();

    return 0;
}