#include "header.h"

//PUBLIC:
Interface::Interface() {
    cout << "Before starting, lets add your first vector!" << endl << endl;
    addVector();
}

Interface::~Interface() {}

void Interface::run() {
    int userInput;
    MainMenuOption menuInput = Print_Current_Vectors;

    while (menuInput != Exit) {
        
        cout << "Main Menu:\n";
        cout << "1 - Add a Vector\n";
        cout << "2 - Delete a Vector\n";
        cout << "3 - Print Vectors\n\n";
        cout << "4 - Print Vector Sum\n";
        cout << "5 - Print Vector Product\n";
        cout << "6 - Minimum Subarray of Specific Sum\n";
        cout << "7 - Subarrays With Max Within Range\n";
        cout << "8 - Product Not Including Self\n\n";     //Add more options under here
        cout << "0 - Exit\n\n";
        
        // Checks validity
        cout << "Enter an option (0-8): ";
        menuInput = MainMenuOption(takeValidInputInRange(0,8));
        
        switch (menuInput) {
            case Add_Vector:
                addVector();
                break;
            case Delete_Vector:
                if(!isEmpty())
                    deleteVector();
                break;
            case Print_Current_Vectors:
                if(!isEmpty())
                    printVectors();
                break;
            case Print_Vector_Sum:
                if(!isEmpty())
                    IntVectorManipulation::printSum(returnChosenVector());
                break;
            case Print_Vector_Product:
                if(!isEmpty())
                    IntVectorManipulation::printProduct(returnChosenVector());
                break;
            case Min_Subarray:
                if(!isEmpty()) {
                    int target = takeValidInput();
                    IntVectorManipulation::minSubArrayLen(returnChosenVector(), target);
                }
            case Exit:
                break;
        }
    }

}

//PRIVATE:
bool Interface::addVector() {
    vector<int> myVector;
    int input;
    int numberOfElements;

    cout << "How many elements do you want to enter? ";
    cin >> numberOfElements;

    cout << "Enter " << numberOfElements << " numbers:\n";
    for (int i =  0; i < numberOfElements; i++) {
        int input = takeValidInput();
        myVector.push_back(input);
    }

    cout << "You entered: ";
    IntVectorManipulation::print(myVector);
    cout << endl << endl;

    vectorList.push_back(myVector);

    return true;
}

bool Interface::deleteVector() {

    int input;
    printVectors();
    cout << "Which vector would you like to remove?" << endl;
    cin >> input;
    while( input < 0 || input >= vectorList.size() ) {
        cout << "Please enter a valid vector." << endl;
        cin >> input;
    }
    cout << endl;
    vectorList.erase(vectorList.begin() + input);
    return true;
}

void Interface::printVectors() {
    cout << "Current vector list:\n";
    for( int i = 0; i < vectorList.size(); i++ ) {
        cout << i << "- ";
        IntVectorManipulation::print(vectorList[i]);
        cout << endl;
    }
    cout << endl << endl;
}

vector<int> Interface::returnChosenVector() {
    printVectors();

    int input;
    cout << "Which vector would you like to use?" << endl;
    cin >> input;
    while( input < 0 || input >= vectorList.size() ) {
        cout << "Please enter a valid vector." << endl;
        cin >> input;
    }
    cout << endl;
    return vectorList[input];
}

bool Interface::isEmpty() {
    if(vectorList.size() == 0) {
        cout << "No vectors in the list." << endl << endl;
        return true;
    }
    return false;
}

int Interface::takeValidInput() {
    int t;
    while (true) {
        cin >> t;
        if (!cin.fail()) {
            break;                                                    // If the input was valid, break the loop
        }
        else {
            cout << "Invalid input. Please enter an integer.\n";
            cin.clear();                                              // Clear the error flags
            cin.ignore(100000000, '\n');      // Ignore the rest of the line
        }
    }
    return t;
}

int Interface::takeValidInputInRange(int low, int high) {
    int t = takeValidInput();

    clamp(t, low, high);
    cout << "T IS NOW" << t;
    return t;
}