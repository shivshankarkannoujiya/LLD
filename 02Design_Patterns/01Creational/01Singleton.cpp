#include <iostream>
using namespace std;

class Database {

    private:
        static Database *instance;

        Database() {
            cout << "Singleton DB created" << endl;
        };

    public:
        static Database* getInstance(){
            if(instance == nullptr){
                instance = new Database();
            }
            return instance;
        }    
};

Database *Database::instance = nullptr;

int main(){
    cout << Database::getInstance() << endl;
    cout << Database::getInstance() << endl;
}