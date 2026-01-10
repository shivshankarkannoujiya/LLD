#include <iostream>
using namespace std;


// Abstraction<interface>
class Database{
   public: 
        virtual void save(string data) = 0;
};

// Low-level Module
class MySqlDatabase : public Database {
    public:
        void save(string data) override {
            cout << "EXECUTING SQL QUERY: INSERT INTO users VALUES ('" << data << "');" << endl;
        }
};

class MongoDBDatabase : public Database{
   public:
        void save(string data) override {
            cout << "EXECUTING MONGODB FUNCTION: db.users.insert({'" << data << "'});" << endl;
        }
};

// High-Level Module
class UserService{
  private:
      //NOTE: Dependency Injection
     // Passing an object in a class as a Variable   
      Database *db; 

    public:
        UserService(Database *db){
            this->db = db;
        }
        
        void storeUser(string user){
            db->save(user);
        }
};

int main() {
    MySqlDatabase mySql;
    MongoDBDatabase mongoDB;

    UserService service_1(&mySql);
    UserService service_2(&mongoDB);

    service_1.storeUser("Raman");
    service_2.storeUser("Rajan");
}