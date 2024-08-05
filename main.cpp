#include "liwanze.h"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <type_traits>
using namespace std ;
template<typename T>
T getInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining input
            cout << "Invalid input. Please try again." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining input
            break;
        }
    }
    return value;
}
Liwanze::Region getRegionFromUser() {
    int choice;
    cout << "Select Region: \n";
    cout << "0. Undefined\n";
    cout << "1. America\n";
    cout << "2. Asia-Pacific\n";
    cout << "3. Europe, Middle East, and Africa\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
    case 0: return Liwanze::ndef;
    case 1: return Liwanze::amer;
    case 2: return Liwanze::apac;
    case 3: return Liwanze::emea;
    default: return Liwanze::ndef;
    }
}

void addArtist(LinkedList& list) {
try {
        string name = getInput<string>("Enter a name of Artist: ");
        //str string name;
        cout << "Enter artist name: ";
        cin.ignore();
        getline(cin, name);
        // Check if input failed
        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            throw invalid_argument("Invalid input for artist."); // Throw an exception
        }

        // Validate the name input
        if (name.empty() || name.find_first_of("-+/ *,._") != std::string::npos) {
            throw std::out_of_range("Please enter a correct name.");
        }

    Liwanze::Region region = getRegionFromUser();

    Liwanze newArtist(name, region);
    list.addNode(newArtist);

     } catch (const exception& e) {
         cout << "Exception: " << e.what() << endl;
     }

}
void deleteArtist(LinkedList& list) {
    string name;
    cout << "Enter artist name to delete: ";
    cin.ignore();
    getline(cin, name);

    list.deleteNode(name);
}

int main() {
    LinkedList list;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Artist\n";
        cout << "2. Delete Artist\n";
        cout << "3. Print List\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addArtist(list);
            break;
        case 2:
            list.printList();
            break;
        case 3:
            list.printList();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
