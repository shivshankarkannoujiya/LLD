#include <iostream>
using namespace std;

// Eager loading to avoid: Concurrency
class Database {

    private:
        static Database *instance;

        Database() {
            cout << "Singleton Created..." << endl;
        };

    public:
        static Database* getInstance(){
            return instance;
        }    
};

Database *Database::instance = new Database();

int main(){
    cout << Database::getInstance() << endl;
    cout << Database::getInstance() << endl;
}