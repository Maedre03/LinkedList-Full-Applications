//202311058 Yigit Onal
#include <iostream>
#include <string>
#include "LinkedList_string.h"
using namespace std;

void displayMenu() {
    cout << "Welcome to the Linked List Program!" << endl;
    cout << "Menu:" << endl;
    cout << "1. Add an element (to back)" << endl;
    cout << "2. Remove an element by value" << endl;
    cout << "3. Access an element at index" << endl;
    cout << "4. Insert an element at index" << endl;
    cout << "5. Insert an element after index" << endl;
    cout << "6. Remove an element at index" << endl;
    cout << "7. Print the linked list" << endl;
    cout << "8. Print the size of the linked list" << endl;
    cout << "9. Check if the linked list is empty" << endl;
    cout << "10. Clear the linked list" << endl;
    cout << "11. Find the middle node" << endl;
    cout << "12. Get the smallest node" << endl;
    cout << "13. Move smallest node to front" << endl;
    cout << "x. Exit" << endl;
    cout << "Selection: ";
}

int main()
{
    LinkedList list;
    string choice;
    string val;
    int idx;

    while(true){
        displayMenu();
        cin >> choice;

        if(choice == "x"){break;}

        int option = stoi(choice); // string to integer function

        switch (option)
        {
        case 1:
            cout << "Enter value to add: ";
            cin >> val;
            list.push_back(val);
            break;
        
        case 2:
            cout << "Enter value to add: ";
            cin >> val;
            list.erase(val);
            break;
        
        case 3:
            cout << "Enter index: ";
            cin >> idx;
            cout << "Element at " << idx << ": " << list.at(idx) << endl;
            break;

        case 4:
                cout << "Enter index and value: ";
                cin >> idx >> val;
                list.insert_at(idx, val);
                break;
        case 5:
                cout << "Enter index and value: ";
                cin >> idx >> val;
                list.insert_after(idx, val);
                break;
            case 6:
                cout << "Enter index to remove: ";
                cin >> idx;
                list.erase_at(idx);
                break;
            case 7:
                cout << "Current List: " << list << endl; 
                break;
            case 8:
                cout << "Size: " << list.size() << endl;
                break;
            case 9:
                if(list.empty()) cout << "List is empty." << endl;
                else cout << "List is not empty." << endl;
                break;
            case 10:
                list.clear();
                cout << "List cleared." << endl;
                break;
            case 11: {
                Node* mid = list.findMiddleNode();
                if(mid) cout << "Middle Node: " << mid->data << endl;
                else cout << "List is empty!" << endl;
                break;
            }
            case 12: {
                Node* small = list.getSmallestNode();
                if(small) cout << "Smallest Node: " << small->data << endl;
                else cout << "List is empty!" << endl;
                break;
            }
            case 13:
                list.moveSmallestToFront();
                cout << "Smallest element moved to front." << endl;
                break;
            default:
                cout << "Invalid selection!" << endl;
        }
    }

    cout << "Exiting program. Goodbye!";
    return 0;
}