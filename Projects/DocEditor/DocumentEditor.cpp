#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class DocumentElement {
    public:
        virtual string render() = 0;
        virtual ~DocumentElement() {};
};


class TextElement : public DocumentElement {
    private:
        string text;

    public:
        TextElement(string t) : text(t) {};
        
        string render() override {
            return text;
        }

};


class ImageElement : public DocumentElement {
    private:
        string path;

    public:
        ImageElement(string p) : path(p) {};

        string render() override {
            return path;
        }
};


class Document {
    private:
        vector<DocumentElement *> docElements;

    public:
        // Add any element (polymorphic)
        void addElement(DocumentElement *element){
            docElements.push_back(element);
        }

        // Render entire document
        string render(){
            string results;
            for(auto element : docElements){
                results += element->render() + "\n";
            }
            return results;
        }

        // Get elements (for persistence)
        vector<DocumentElement*>& getElements(){
            return docElements;
        }

        ~Document(){
            for(auto element : docElements){
                delete element;
            }
        }
};

// ============= PERSISTENCE HIERARCHY =============
class Persistence{
    public:
        virtual void save(string content) = 0;
        virtual ~Persistence() {};
};

class SaveToFile : public Persistence{
    private:
        string filename;
    public:
        SaveToFile(string fname) : filename(fname) {};

    void save(string content) override {
        ofstream file(filename);
        if(file.is_open()){
            file << content;
            file.close();
            cout << "✓ Saved to file: " << filename << endl;
        }
    }
};

class SaveToDB : public Persistence{
    public:
        void save(string content) override {
            cout << "✓ Saved to database: "<<endl;
            cout << "INSERT INTO documents VALUES ('" << content << "');"<<endl;
        }
};

class DocumentEditor{
    private: 
        Document doc;
        Persistence *db;
    public:
        DocumentEditor(Persistence *persistence) : db(persistence) {};

        void addText(string text){
            doc.addElement(new TextElement(text));
            cout << "✓ Text added"<<endl;
        }

        void addImage(string path){
            doc.addElement(new ImageElement(path));
            cout << "✓ Image added"<<endl;
        }

        void saveDocument(){
            string rendered = doc.render();
            db->save(rendered);
        }

        void preview(){
            cout << "\n========== PREVIEW ==========\n";
            cout << doc.render();
            cout << "=============================\n\n";
        }
};

int main() {

    SaveToFile fileStorage("document.txt");

    DocumentEditor editor(&fileStorage);

    int choice;
    string input;

    while(true){

        cout << "1. Add Text" << endl;
        cout << "2. Add Image" << endl;
        cout << "3. Preview Document" << endl;
        cout << "4. Save Document" << endl;
        cout << "5. Exit" << endl;
        cout << "\nChoice: ";
        cin >> choice;
        cin.ignore();

        switch (choice){
            case 1:
                cout << "Enter text: ";
                getline(cin, input);
                editor.addText(input);
                break;

            case 2:
                cout << "Enter image path: ";
                getline(cin, input);
                editor.addImage(input);
                break;

            case 3:
                editor.preview();
                break;

            case 4:
                editor.saveDocument();
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }

    }
    
}

