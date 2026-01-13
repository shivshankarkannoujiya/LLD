#include <iostream>
#include <string>
using namespace std;

// NOTE: Approach: 1

class UserExamParameter {
    public:
        int englishMark;
        int mathMark;
        int scienceMark;
        string name;
};

class UserExam {
    private:
        int englishMark;
        int mathMark;
        int scienceMark;
        string name;
        
    public:
        UserExam(const UserExamParameter &parameter){

            if(
                parameter.englishMark > 100 || parameter.mathMark > 100 || parameter.scienceMark > 100
            ){
                throw invalid_argument("Marks can not be greater than 100");
            }

            if (parameter.name[0] == '0'){
                throw invalid_argument("Name cannot start with 0");
            }

            this->englishMark = parameter.englishMark;
            this->mathMark = parameter.mathMark;
            this->scienceMark = parameter.scienceMark;
            this->name = parameter.name;
            cout << "Exam is created for: " << this->name << endl;
        }

        UserExam() {};

        void setEnglish(int englishMark){
            this->englishMark = englishMark;
        }
};

int main(){
    UserExamParameter params;

    params.englishMark = 80;
    params.mathMark = 100;
    params.scienceMark = 90;
    params.name = "Namam";

    try{
        UserExam *exam = new UserExam(params);
    }catch(const invalid_argument &e){
        cout << "Exception: " << e.what() << endl;
    }
}