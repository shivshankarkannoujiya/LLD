#include <iostream>
#include <string>
using namespace std;

class PaymentMethod {
    public:
        virtual void processPayment(double amount) = 0;
        virtual string getPaymentMethodName() = 0;
        virtual ~PaymentMethod() = default;
};


class CreditCardPayment : public PaymentMethod {
    private:
        string cardNumber;
        string cvv;
    
        void validateCard(){}
        void chargeCard(double amount){}

    public:
        CreditCardPayment(string cardNumber, string cvv){
            this->cardNumber = cardNumber;
            this->cvv = cvv;
        }

        void processPayment(double amount) override{
            cout << "Processing credit card payment: $" << amount << endl;
            validateCard();
            chargeCard(amount);
        }

        string getPaymentMethodName(){
            return "Credit Card";
        }
};


class PayPalPayment : public PaymentMethod{
    private:
        string email;

        void authenticatePayPal(){};
        void transferFunds(double amount) {};

    public:
        PayPalPayment(string email){
            this->email = email;
        }

        void processPayment(double amount) override {
            cout << "Processing PayPal payment: $" << amount << endl;
            authenticatePayPal();
            transferFunds(amount);
        }

        string getPaymentMethodName() override{
            return "PayPal";
        }
};


class BitcoinPayment : public PaymentMethod{
    private:
        string walletAddress;

        void verifyWallet(){};
        void sendBitcoin(double amount){};

    public:
        BitcoinPayment(string walletAddress) {
            this->walletAddress = walletAddress;
        }

        void processPayment(double amount) override{
            cout << "Processing Bitcoin payment: $" << amount << endl;
            verifyWallet();
            sendBitcoin(amount);
        }

        string getPaymentMethodName() override{
            return "Bitcoin";
        }
};


class BankTransferPayment : public PaymentMethod{

    private:
        string accountNumber;
        string routingNumber;

        void verifyAccount() {};
        void initiateTransfer(double amount) {};

    public:
        BankTransferPayment(string accountNumber, string routingNumber) {
            this->accountNumber = accountNumber;
            this->routingNumber = routingNumber;
        }

        void processPayment(double amount) override{
            cout << "Processing bank transfer: $" << amount << endl;
            verifyAccount();
            initiateTransfer(amount);
        }

        string getPaymentMethodName() override{
            return "Bank Transfer";
        }
};

class PaymentProcessor {
    private:
        void logTransaction(PaymentMethod *method, double amount){
            cout << "=== Transaction logged ===" << endl;
            cout << "METHOD: " << method->getPaymentMethodName() << endl;
            cout << "AMOUNT: $" << amount << endl;
        }

    public:
        void processPayment(PaymentMethod *method, double amount) {
            cout << "Processing payment via "
                 << method->getPaymentMethodName() << endl;
            method->processPayment(amount);
            logTransaction(method, amount);
        }
};

int main(){

    PaymentProcessor processor;

    CreditCardPayment creditCard("1234-5678", "123");
    processor.processPayment(&creditCard, 99.99);

    PayPalPayment paypal("user@email.com");
    processor.processPayment(&paypal, 149.99);

    BitcoinPayment bitcoin("abcbit12");
    processor.processPayment(&bitcoin, 20000.99);

    BankTransferPayment bank("123456789", "987654");
    processor.processPayment(&bank, 1999.99);
}