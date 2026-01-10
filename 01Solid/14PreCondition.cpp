#include <iostream>
using namespace std;


class User {
    public:
        // Pre: Passowrd must be at least 8 char long
        virtual void createPassword(string pass){
            if(pass.length() < 8)
                throw invalid_argument("Password must be at least 8 char long");
            cout << "Password created successfully" << endl;
        }
        
};

class AdminUser : public User {
    public:
        // Pre: Passowrd must be at least 6 char long
        void createPassword(string pass){
            if(pass.length() < 6)
                throw invalid_argument("Password must be at least 6 char long");
            cout << "Password created successfully" << endl;
        }
};

int main(){
    // User *user = new User();
    User *user = new AdminUser();
    user->createPassword("123456");
}