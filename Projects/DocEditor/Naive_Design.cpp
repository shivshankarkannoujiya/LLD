#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


class DocumentEditor{
    private:
        vector<string> documentElements;
        string renderedDocument;

    public:

        void addText(string text){
            documentElements.push_back(text);
            cout << "Text added successfully!"<<endl;
        }

        void addImage(string path){
            documentElements.push_back(path);
            cout << "Image added successfully!"<<endl;
        }

        string renderDocument(){
            string result;

            if (documentElements.empty()){
                return "[Empty Document]\n";
            }

            for (int i = 0; i < documentElements.size(); i++){
                string element = documentElements[i];
                if (element.size() >= 4){
                    string ext = element.substr(element.size() - 4);
                    if (ext == ".jpg" || ext == ".png"){
                        result += "[Image: " + element + "]\n";
                    }
                    else{
                        result += element + "\n";
                    }
                }
                else{
                    result += element + "\n";
                }
            }

            renderedDocument = result;
            return renderedDocument;
        }

        void saveToFile(){
            ofstream file("document.txt");

            if(!file.is_open()){
                cout << "Error: Could not create file!"<<endl;
                return;
            }

            file << renderDocument();
            file.close();
            cout << "Document saved to 'document.txt' successfully!"<<endl;
        }
};

int main(){

    DocumentEditor doc;

    int choice;
    string input;

    cout << "===== Document Editor =====\n\n";
    
    while (true){
        cout << "1. Add Text"<<endl;
        cout << "2. Add Image"<<endl;
        cout << "3. Render Document"<<endl;
        cout << "4. Save to File"<<endl;
        cout << "5. Exit"<<endl;

        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:
                cout << "Enter text: ";
                getline(cin, input);
                doc.addText(input);
                break;
            case 2:
                cout << "Enter image path: ";
                getline(cin, input);
                doc.addImage(input);
                break;
            case 3:
                cout << "\n========== RENDERED DOCUMENT ==========\n";
                cout << doc.renderDocument();
                cout << "========================================\n";
                break;
            case 4:
                doc.saveToFile();
                break;
            case 5:
                cout << "Exiting..."<<endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again."<<endl;

        }
        cout << endl;
    }

    return 0;
}