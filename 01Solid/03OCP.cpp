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

class ShoppingCart{
    private:
        vector<Product *> products;
    
    public:

        void addToShoppingCart(Product *p){
            products.push_back(p);
        }
        
        const vector<Product*>& getProducts(){
            return products;
        }

        double calculateTotalCartPrice(){
            double totalPrice = 0;
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
        ShoppingCartPrinter(ShoppingCart *cart){
            this->cart = cart;
        }   

        void printInvoice(){
            cout << "=== Shopping Cart Invoice ===" << endl;
            for(auto p : cart->getProducts()){
                cout << p->name << ": $" << p->price << endl;
            }
            cout << "Total Price: $" << cart->calculateTotalCartPrice() << endl;
        } 
};

class ShoppingCartStorage {

    private:
        ShoppingCart *cart;
    
    public:
        ShoppingCartStorage(ShoppingCart *cart){
            this->cart = cart;
        }
        
        void saveToSqlDB(){
            cout<<"Saving shopping cart to SQL..."<<endl;
        }

        // NOTE: Changing existing code
        // NOTE: Violating <OCP>
        void saveToMongoDB(){
            cout<<"Saving shopping cart to MONGO..."<<endl;
        }
        void saveToFile(){
            cout<<"Saving shopping cart to FILE..."<<endl;
        }
};

int main(){
    ShoppingCart *cart = new ShoppingCart();

    cart->addToShoppingCart(new Product("Laptop", 100000));
    cart->addToShoppingCart(new Product("Mouse", 100));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage *storage = new ShoppingCartStorage(cart);
    storage->saveToSqlDB();
    storage->saveToMongoDB();
    storage->saveToFile();
}