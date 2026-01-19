#include <iostream>
#include <string>
using namespace std;

enum class PaymentStatus{
    SUCCESS,
    FAILURE,
    PENDING
};

enum class PayUPaymentStatus{
    SUCCESS,
    FAILURE,
    PENDING,
    ERROR,
    UNKNOWN,
    TIMEOUT,
    PROCESSING,
};

// interface: <<abstract>>
class PaymentGateway{
    public:
        virtual long payViaCreditCard(
            string cardNumber,
            int cvv,
            int expiryMonth,
            int expiryYear) = 0;

        virtual PaymentStatus getStatus(long transactionId) = 0;
};


// Flipkart Codebase
// NOTE: if we want to support multiple PaymentGateway
// 
class Flipkart{
    private:
        // Make it list: to support the multiple payment gateway
        // vector<PaymentGateway*> paymentGateways
        PaymentGateway *paymentGateway;

    public:
        
        Flipkart(PaymentGateway* paymentGateway){
            this->paymentGateway = paymentGateway;
        }    

        void paymentViaCC(
            string cardNumber,
            int cvv,
            int expiryMonth,
            int expiryYear
        ){
            long transactionId = paymentGateway->payViaCreditCard(
                cardNumber,
                cvv,
                expiryMonth,
                expiryYear);

            while(paymentGateway->getStatus(transactionId) != PaymentStatus::SUCCESS){
                cout << "Waiting..." << endl;
            }
            cout << "Payment Successful!" << endl;
        }
};


// Third-Pary Code base
// We can not decide the Methods: Name etc.

// 1. Razorpay
class RazorpayGateway{

    public:
        string PayByCreditCard(string cardNumber, string cvv, string expiry){
            cout << "[Razorpay] Payment processing..." << endl;
            return "123";
        }

        PaymentStatus checkPaymentStatus(string transactionId){
            return PaymentStatus::SUCCESS;
        }
};

// 2. PayUMoney
class PayUMoneyGateway{

    public:
        string makeCCPayment(long long cardNumber, long cvv, long expiry){
            cout << "[PayUMoney] Payment processing..." << endl;
            return "456";
        }

        PayUPaymentStatus checkPaymentStatus(string transactionId){
            return PayUPaymentStatus::SUCCESS;
        }
};


// NOTE: Flipkart will create an `Adapter` for the third party APIs
// TODO: Implement the "PaymentGateway" interface

class RazorpayPaymentGatewayAdapter : public PaymentGateway {

    // NOTE: Internally use Razorpay Class bcz, real work is done by `Razorpay API`
    private:
        RazorpayGateway *razorpayGateway = new RazorpayGateway();

    public:
        long payViaCreditCard(
            string cardNumber,
            int cvv,
            int expiryMonth,
            int expiryYear) override {

                string cvvString = to_string(cvv);
                string expiry = to_string(expiryMonth) + "/" + to_string(expiryYear);
                string ans = razorpayGateway->PayByCreditCard(cardNumber, cvvString, expiry);
                return stol(ans);
            }

            PaymentStatus getStatus(long transactionId) override {
                PaymentStatus status = razorpayGateway->checkPaymentStatus(to_string(transactionId));
                return status;
            }
};


// NOTE: Move from the Razorpay -> PayUMoney
class PayUMoneyPaymentGatewayAdapter : public PaymentGateway {

    private:
        PayUMoneyGateway *payUMoney;



    public:
        PayUMoneyPaymentGatewayAdapter(){
            payUMoney = new PayUMoneyGateway();
        }

        ~PayUMoneyPaymentGatewayAdapter(){
            delete payUMoney;
        }


        long payViaCreditCard(
            string cardNumber,
            int cvv,
            int expiryMonth,
            int expiryYear) override {
                long longCardNumber = stoll(cardNumber);
                long expiry = expiryMonth * 100 + expiryYear;

                string ans = payUMoney->makeCCPayment(longCardNumber, cvv, expiry);
                return stol(ans);
            }

            PaymentStatus getStatus(long transactionId) override {
                PayUPaymentStatus payUstatus = payUMoney->checkPaymentStatus(to_string(transactionId));

                switch(payUstatus){
                    case PayUPaymentStatus::SUCCESS:
                        return PaymentStatus::SUCCESS;

                    case PayUPaymentStatus::FAILURE:
                    case PayUPaymentStatus::ERROR:
                    case PayUPaymentStatus::TIMEOUT:
                        return PaymentStatus::FAILURE;

                    case PayUPaymentStatus::PENDING:
                    case PayUPaymentStatus::PROCESSING:
                    case PayUPaymentStatus::UNKNOWN:
                    default:
                        return PaymentStatus::PENDING;
                    }
            }
};


int main(){
    cout << "=== Phase 1: Using Razorpay ===" << endl;
    PaymentGateway *razorPayAdapter = new RazorpayPaymentGatewayAdapter();

    Flipkart filpkart1(razorPayAdapter);
    filpkart1.paymentViaCC("4532015112830366", 123, 12, 2025);
    delete razorPayAdapter;

    cout << "\n=== Phase 2: Migrated to PayUMoney ===" << endl;
    PaymentGateway *payUAdapter = new PayUMoneyPaymentGatewayAdapter();

    // Flipkart filpkart2(payUAdapter);
    // filpkart2.paymentViaCC("5425233430109903", 456, 6, 2026);
    // delete payUAdapter;

    Flipkart flipkart2(new PayUMoneyPaymentGatewayAdapter());
    flipkart2.paymentViaCC("5425233430109903", 456, 6, 2026);

    return 0;
}