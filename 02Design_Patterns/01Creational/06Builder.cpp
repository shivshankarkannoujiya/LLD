#include <iostream>
#include <string>
using namespace std;

// NOTE: Method Chaining

class UserExam{

private:
    int englishMark;
    int mathMark;
    int scienceMark;
    string name;

    UserExam() = default;

public:
    class UserExamBuilder{

    private:
        int englishMark;
        int mathMark;
        int scienceMark;
        string name;

    public:
        UserExamBuilder& setEnglishMark(int englishMark){
            this->englishMark = englishMark;
            return *this;
        }

        UserExamBuilder& setMathMark(int mathMark){
            this->mathMark = mathMark;
            return *this;
        }

        UserExamBuilder& setScienceMark(int scienceMark){
            this->scienceMark = scienceMark;
            return *this;
        }

        UserExamBuilder& setName(string name){
            this->name = name;
            return *this;
        }

        UserExam build(){

            // Step: 1 VALIDATION
            if (englishMark > 100 || mathMark > 100 || scienceMark > 100){
                throw invalid_argument("Marks can not be greater than 100");
            }

            if ((englishMark + mathMark) > 150){
                throw invalid_argument("Math + EnglishMark can not be grater than 150");
            }

            if (name.empty() || name[0] == '0'){
                throw invalid_argument("Name cannot start with 0");
            }

            // Step:2 CREATE PARENT
            UserExam userExam;

            userExam.englishMark = this->englishMark;
            userExam.mathMark = mathMark;
            userExam.scienceMark = this->scienceMark;
            userExam.name = this->name;

            return userExam;
        }
    };

    static UserExamBuilder getBuilder(){
        return UserExamBuilder();
    }
};

int main(){

    try{
        UserExam userExam =  UserExam::getBuilder()
            .setEnglishMark(100)
            .setMathMark(20)
            .setScienceMark(100)
            .build();

        cout << "UserExam created successfully" << endl;
    }
    catch(const exception& e){
        cerr << e.what() << endl;
    }
    
}