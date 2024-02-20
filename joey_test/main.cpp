#include <iostream>
#include <vector>
#include <map>

using namespace std;

// namespace First
namespace First {
    int value() { return 5; }

    namespace FirstNext {
        int value() { return 6; }
    }
}
// end namespace First

// namespace Second
namespace Second {
    const double x = 100;
    double value() { return 2*x; }
}
// end namespace Second


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

void showNamespaces() {
    
    // Access in namespace First
    std::cout << "First::value: " << First::value() << std::endl;
        
    // Access value in namespace Second
    std::cout << "Second::value: " << Second::value() << std::endl;
    
    
    std::cout << "First::FirstNext::value: " << First::FirstNext::value() << std::endl;
}

void dynamicMemoryAllocation() {
    int userInput;
    cout << "INPUT: Enter an integer (whole number)";
    cin >> userInput;
    
    int* userPtr = new int(userInput);
    cout << "Dynamically allocated integer: " << *userPtr << "\nAt Memory Location: " << &userPtr << "\n" << endl;
    delete userPtr;
}

void showSTLContainers() {
    char userInput;
    
    vector<int> vec;
    map<string, int> mp = {{"apple", 1}, {"banana", 2}};
    
    do {
        cout << "Do you want to insert your own vector elements? y/n" << endl;
        cin >> userInput;
    } while ((userInput != 'y' ) && (userInput != 'n'));
    
    signed int track_number = 0;
    if (userInput == 'y') {
        int userInput2;
        while (true) {
            cout << "Enter elment #" << track_number << ". Type -1 to exit." << endl;
            cin >> userInput2;
            if (userInput2 == -1) {
                break; // leave loop user input
            }
            vec.push_back(userInput2);
            
        }
        
        // Display vector
        cout << "Vector elements: ";
        for(int n : vec) {
            cout << n << " ";
        }
        cout << endl;
    } else {
        cout << "No vector inputs" << endl;
    }
        
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

    cout << "\nINPUT: Enter the index of the array element to view its memory content (or -1 to exit): ";
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
    
    // Set the variable's value
    void setValue(int newValue) {
        this->value = newValue;
    }
    
    // Get the private variable's value
    int getValue() {
        return this->value;
    }
    
private:
    int value;
};

class Point {
public:
    int x, y;
    
    Point(int x, int y) : x(x), y(y) {}
    
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }
    
    Point operator-(const Point& other) {
        return Point(x - other.x, y - other.y);
    }
    
    Point operator*(const Point& other) {
        return Point(x * other.x, y * other.y);
    }
    
    Point operator%(const Point& other) {
        return Point(int(x % other.x), int(y % other.y));
    }
    
    void print() { cout << "(" << x << ", " << y << ")"; }
    
    friend ostream& operator<<(ostream& os, const Point& p);
};

// Overloading the 'vv' operator to print a Point
ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
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
        cout << "7. Namespaces\n";
        cout << "8. Operator Overloading\n";
        cout << "0. Exit\n";
        cout << "INPUT: Enter your choice: ";
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
                int userValue;
                obj.display();
                cout << "Set the value for the class: " << endl;
                cin >> userValue;
                obj.setValue(userValue);
                cout << "The new value is: " << obj.getValue() << "." << endl;
                break; }
            case 6: {
                // Display Memory Content
                const int SIZE = 10;
                int myArray[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
                
                displayMemoryContent(myArray, SIZE);
                break; }
            case 7: {
                showNamespaces();
                break;
            }
            case 8: {
                Point p1(1,2);
                Point p2(3,4);
                
                Point sum = p1 + p2;
                Point sub = p1 - p2;
                Point multiplication = p1 * p2;
                
                // Display points to user
                cout << "Point 1: " << p1 << endl;
                cout << "point 2: " << p2 << endl;
                
                // Cout overloading
                cout << "Sum: " << sum << endl;
                cout << "Sub: " << sub << endl;
                
                // Using print method
                cout << "Multiplication:";
                //multiplication.print();
                cout << endl;
                break;
            }
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
