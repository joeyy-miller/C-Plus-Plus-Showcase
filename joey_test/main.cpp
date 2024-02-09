#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * showBasicTypes: Shows different vaible types in C++
 * @return None
 */
void showBasicTypes() {
    int a = 5;
    float b = 3.14;
    char c = 'A';
    cout << "Integer: " << a << ", Float: " << b << ", Char: " << c << endl;
}

void dynamicMemoryAllocation() {
    int* ptr = new int(10);
    cout << "Dynamically allocated integer: " << *ptr << endl;
    delete ptr;
}

void showSTLContainers() {
    vector<int> vec = {1, 2, 3, 4, 5};
    map<string, int> mp = {{"apple", 1}, {"banana", 2}};

    cout << "Vector elements: ";
    for(int n : vec) {
        cout << n << " ";
    }
    cout << endl;

    cout << "Map elements: ";
    for(const auto& pair : mp) {
        cout << "[" << pair.first << " => " << pair.second << "] ";
    }
    cout << endl;
}

void functionOverloading(int a) {
    cout << "Integer: " << a << endl;
}

void functionOverloading(double a) {
    cout << "Double: " << a << endl;
}

void displayMemoryContent(int* array, int size) {
    int choice;

    cout << "Array Memory Locations:\n";
    for (int i = 0; i < size; ++i) {
        cout << "&array[" << i << "]: " << (void*)&array[i] << " (value: " << array[i] << ")\n";
    }

    cout << "\nEnter the index of the array element to view its memory content (or -1 to exit): ";
    while (true) {
        cin >> choice;
        if (choice == -1) {
            break;
        }
        if (choice >= 0 && choice < size) {
            cout << "Memory content at array[" << choice << "] (Address: " << &array[choice] << "): ";
            cout << array[choice] << std::endl;
        } else {
            cout << "Invalid index. Please try again.\n";
        }
        cout << "Enter another index (or -1 to exit): ";
    }
}

class SampleClass {
public:
    void display() {
        cout << "SampleClass display method." << endl;
    }
};

int main() {
    int choice;

    do {
        // Main Menu
        cout << "\nC++ Showcase Menu:\n";
        cout << "1. Basic Variable Types\n";
        cout << "2. Dynamic Memory Allocation\n";
        cout << "3. STL Containers\n";
        cout << "4. Function Overloading\n";
        cout << "5. Class and Object\n";
        cout << "6. View Memory Locations\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // User Input
        switch(choice) {
            case 1: {
                // Basic Variable Types Showcase
                showBasicTypes();
                break; }
            case 2: {
                // Dynamic Memory Allocation Showcase
                dynamicMemoryAllocation();
                break; }
            case 3: {
                // STL Containers Showcase
                showSTLContainers();
                break; }
            case 4: {
                // Function Overloading Showcase
                functionOverloading(5);
                functionOverloading(3.14);
                break; }
            case 5: {
                // Object Oriented Programming Showcase
                SampleClass obj;
                obj.display();
                break; }
            case 6: {
                // Display Memory Content
                const int SIZE = 10;
                int myArray[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
                
                displayMemoryContent(myArray, SIZE);
                break; }
            case 0: {
                cout << "Exiting program." << endl;
                break; }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    } while(choice != 0);

    return 0;
}
