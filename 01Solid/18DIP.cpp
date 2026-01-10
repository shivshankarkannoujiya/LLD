#include <iostream>
using namespace std;

// NOTE: Low-Level Module
class MySqlDatabse {
    public:
        void saveToSql(string data){
            cout << "EXECUTING SQL QUERY: INSERT INTO users VALUES ('" << data << "');" << endl;
        }
};

class MongoDBDatabse {
    public:
        void saveToMongoDB(string data){
            cout << "EXECUTING MONGODB FUNCTION: db.users.insert({'" << data << "'});" << endl;
        }
};

// NOTE: High level module
class UserService {
    // Direct Dependency on Low - level module
    MySqlDatabse sqlDB;
    MongoDBDatabse mongDB;

    public:
        void storeToMySQL(string user){
            // My SQL Specific code
            sqlDB.saveToSql(user); 
        }
        
        void storeToMongoDB(string user){
            // MongoDB Specific code
            mongDB.saveToMongoDB(user);
        }

};

int main(){
    UserService service;
    service.storeToMySQL("abhi");
    service.storeToMongoDB("abhi");
}