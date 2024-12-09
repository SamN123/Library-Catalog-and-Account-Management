#include <string>
#include <fstream>
#include <sstream>

#include "LinkedList.cpp"

using namespace std;

class Library {

public:

    Node* traverse;
    int counter = 1;
    int width = 0;

    Library(LinkedList& list1) {
        std::ifstream inputFile("expanded_book_titles.txt");
        if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        }

        std::string line;
        while (getline(inputFile, line)) {
            std::stringstream ss(line); // Load 'line' into the string stream
            std::string title; 
            std::string dateStr;
            int date; 
        
            // Split the line by the pipe delimiter
            if (getline(ss, title, '|') && getline(ss, dateStr, ';')) {
                // Convert the date string to an integer
                date = stoi(dateStr);
            };
        //cout << "Title: " << title << ", Due date: " << date << endl;
            list1.addNode(title, date);
        };

       

        Node* traverse = list1.getHead();
        while(traverse != nullptr) {
            traverse->key = hashFunction(traverse->title);
            //cout << hex << traverse->key << endl;
            traverse = traverse->next;
            counter++;
            if(traverse!=nullptr && traverse->title.length() > width) width = traverse->title.length(); 

        }

    };

    unsigned long int hashFunction(const std::string& entry) { //generates value based on 
         unsigned long int hash = 0;
         
        for(int i = 0; i < 8; i++) {
            hash = i > entry.length()-1 ? hash : hash + entry[i]; //save ascii character value to hash
            hash = i == 7 ? hash : hash << 8; //bit-shift hash left 8 bits to make space for next character
        } 
        
        return hash;
    };

    void saveCatalog(Node* head) {
        
        std::ofstream outputFile("expanded_book_titles.txt");
        while(head != nullptr){
            outputFile << head->title <<"|" << head->date << ";";
            if(head->next != nullptr) outputFile << "\n";
            head = head->next;
        }
        outputFile.close();
    }	
};
