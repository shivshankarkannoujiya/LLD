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

        void addProductToShoppingCart(Product *p){
            products.push_back(p);
        }
        
        const vector<Product*> getShoppingCartProducts(){
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
            cout << "=== SHOPPING CART INVOICE  ===" << endl;
            for(auto p : cart->getShoppingCartProducts()){
                cout << p->name << ": $" << p->price << endl;
            }
            cout << "TOTAL PRICE: " << cart->calculateTotalCartPrice() << endl;
        }
};


class DBPersistence {
    private:
        ShoppingCart *cart;

    public:
        virtual void save(ShoppingCart *cart) = 0;
};

class SQLPersistance : public DBPersistence{
    public:
        void save(ShoppingCart *cart) override {
            cout << "Saving Shopping cart to SQL DB ...." << endl;
        }
};

class MONGOPersistance : public DBPersistence{
    public:
        void save(ShoppingCart *cart) override {
            cout << "Saving Shopping cart to MONGO DB ...." << endl;
        }
};

class FILEPersistance : public DBPersistence{
    public:
        void save (ShoppingCart *cart) override {
            cout << "Saving Shopping cart to FILE ...." << endl;
        }
};

int main(){
    ShoppingCart *cart = new ShoppingCart();

    cart->addProductToShoppingCart(new Product("Laptop", 100000));
    cart->addProductToShoppingCart(new Product("Mouse", 1000));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    DBPersistence *sqlDB = new SQLPersistance();
    DBPersistence *mongo = new MONGOPersistance();
    DBPersistence *file = new FILEPersistance();

    sqlDB->save(cart);
    mongo->save(cart);
    file->save(cart);

    return 0;
}