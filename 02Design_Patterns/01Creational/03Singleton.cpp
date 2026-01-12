#include <iostream>
#include <string>
using namespace std;

class Database{

    private:
        string connectionUrl;

        Database(){
            cout << "Connecting to Database..." << endl;
            this->connectionUrl = "jdbc:mysql://localhost:3306";
        }

        // Delete copy constructor and assignment operator
        // This prevents copying the singleton
        Database(const Database &) = delete;
        Database &operator=(const Database &) = delete;

        public:
            static Database& getInstance(){
                static Database instance;
                return instance;
            }

};


int main(){
    Database &db1 = Database::getInstance();
    Database &db2 = Database::getInstance();

    if(&db1 == &db2){
        cout << "It's the same object!" << endl;
    }
}