#include "header.h"

//PUBLIC:
Interface::Interface() {
    cout << "Before starting, lets add your first vector!" << endl << endl;
    addVector();
}

Interface::~Interface() {}

void Interface::run() {
    MainMenuOption menuInput = Print_Current_Vectors;

    while (menuInput != Exit) {
        
        cout << "Main Menu:\n";
        cout << "1 - Add a Vector\n";
        cout << "2 - Delete a Vector\n";
        cout << "3 - Print Vectors\n\n";
        cout << "4 - Print Vector Sum\n";
        cout << "5 - Print Vector Product\n";
        cout << "6 - Minimum Subarray of Specific Sum\n\t*will be incorrect if array contains negative values*\n";
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
                    cout << "Enter your target value: ";
                    int target = takeValidInput();
                    IntVectorManipulation::minSubArrayLen(returnChosenVector(), target);
                }
                break;
            case Subarray_Within_Range:
                if(!isEmpty()) {
                    cout << "Enter your lower value: ";
                    int low = takeValidInput();
                    cout << "Enter your upper value: ";
                    int high = takeValidInputInRange(low, INT_MAX);
                    IntVectorManipulation::numSubarrayBoundedMax(returnChosenVector(), low, high);
                }
                break;
            case Product_NoSelf:
                if(!isEmpty())
                    IntVectorManipulation::productExceptSelf(returnChosenVector());
                break;
            case Exit:  //Add more options above the Exit case
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
    numberOfElements = takeValidInputInRange(1, INT_MAX);

    cout << "Enter " << numberOfElements << " number(s):\n";
    for (int i =  0; i < numberOfElements; i++) {
        input = takeValidInput();
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
    input = takeValidInputInRange(0, vectorList.size());
    cout << endl;
    vectorList.erase(vectorList.begin() + input);
    return true;
}

void Interface::printVectors() {
    cout << "\nCurrent vector list:\n";
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
    input = takeValidInputInRange(0, vectorList.size());
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

//Below functions take in user inputs. They ensure input is and int
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
            cin.ignore(100000000, '\n');                              // Ignore the rest of the line
        }
    }
    return t;
}

//Forces user input to be within range
int Interface::takeValidInputInRange(int low, int high) {
    int t = takeValidInput();

    t = clamp(t, low, high);
    return t;
}