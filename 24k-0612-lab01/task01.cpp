#include <iostream>
#include <string>
using namespace std;

class ResearchPaper {
private:
    string* authors;
    int authorCount;     

public:
    
    ResearchPaper(int count, string* names) {
        authorCount = count; 
        authors = new string[authorCount];
        for (int i = 0; i < authorCount; ++i) {
            authors[i] = names[i];
        }
    }

    
    ~ResearchPaper() {
        delete[] authors;  
    }

    
    ResearchPaper(const ResearchPaper& other) {
        authorCount = other.authorCount;
         authors = new string[authorCount];
        for (int i = 0; i < authorCount; ++i) {
            authors[i] = other.authors[i];
        }
    }

    
    ResearchPaper& operator=(const ResearchPaper& other) {
        
        if (this != &other) {
            delete[] authors;

            authorCount = other.authorCount;
            authors = new string[authorCount];
            for (int i = 0; i < authorCount; ++i) {
                authors[i] = other.authors[i];
            }
        }

        return *this; 
    }


    void printAuthors() const {
        cout << "Authors: ";
        for (int i = 0; i < authorCount; ++i) {
            cout << authors[i];
            if (i < authorCount - 1) cout << ", ";
        }
        cout << endl;
    }

    void setAuthor(int index, const string& name) {
        if (index >= 0 && index < authorCount) {
            authors[index] = name;
        }
    }
};

int main() {
    
    string authors1[] = {"Alice", "Bob"};
    ResearchPaper paper1(2, authors1);
    cout << "Original Paper 1:\n";
    paper1.printAuthors();

    
    ResearchPaper paper2 = paper1;
    cout << "Copied Paper 2 (via copy constructor):\n";
    paper2.printAuthors();

    
    paper2.setAuthor(0, "Charlie");
    cout << "\nAfter modifying Paper 2:\n";
    paper2.printAuthors();

    
    cout << "Paper 1 remains unchanged:\n";
    paper1.printAuthors();

    
    string authors3[] = {"Dave", "Eve", "Frank"};
    ResearchPaper paper3(3, authors3);
    cout << "\nOriginal Paper 3:\n";
    paper3.printAuthors();

    
    paper3 = paper1;
    cout << "After assigning Paper 1 to Paper 3:\n";
    paper3.printAuthors();

   
    paper3.setAuthor(1, "Grace");
    cout << "\nAfter modifying Paper 3:\n";
    paper3.printAuthors();

    
    cout << "Paper 1 remains unchanged:\n";
    paper1.printAuthors();

    return 0;
}