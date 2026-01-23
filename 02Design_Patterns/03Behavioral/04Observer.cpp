#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

enum class Events{
    ORDER_PLACED
};

class Order {
    private:
        long orderId;
        int amount;
};

// <<interface>>
class Subscriber{
    public:
        virtual void listen(const Order &order) = 0;
};


class Flipkart{
    private:
        static unordered_map<Events, vector<Subscriber*>> subscribers;

    public:

        static void registerSubscriber(Events event, Subscriber* subscriber){
            subscribers[event].push_back(subscriber);
        }

        // Want to send the Order details with the event notification
        // Subscriber will know about: Order placed for particular <Order>
        static void notify(Events event, const Order &order){
            for(Subscriber* subscriber: subscribers[event]){
                subscriber->listen(order);
            }
        }

        void placeOrder(const Order &order){
            cout << "Order Placed successfully"<<endl;
            this->notify(Events::ORDER_PLACED, order);
        }
};

// NOTE: static member definition
unordered_map<Events, vector<Subscriber *>> Flipkart::subscribers;

// Subscribers
class InvoiceManagementService : public Subscriber{

    // Subscriber is not Subscribed YET
    // How/When will Subscriber will Subscribe
    // NOTE: Will `InvoiceManagementService` always be interested in ORDER_PLACED event: YES
    // TODO: So, in the constructor of `InvoiceManagementService` itself it can subscribe to that
    // NOTE: Why passing: `this`
                // Because who will be subscriber, it itself will be the subscribe so, `this` 

    public:
        InvoiceManagementService(){
            Flipkart::registerSubscriber(Events::ORDER_PLACED, this);
        }

        void listen(const Order &order) override {
            this->generateInvoice(order);
        }

        void generateInvoice(Order order){
            cout << "Generating Invoice for Order" << endl;
        }
};


int main(){
    InvoiceManagementService invoiceManagementService;
    Flipkart flipkart;
    Order order;

    flipkart.placeOrder(order);
}