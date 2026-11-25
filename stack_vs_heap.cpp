
// ACTIVITY 2: STACK VS HEAP OBJECTS
// Learning Outcome: Analyse stack vs heap allocation

#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string model;

    // Constructor
    Car(string m) {
        model = m;
        cout << "Car created: " << model << endl;
    }

    // Destructor: Runs automatically when a stack object is destroyed
    ~Car() {
        cout << "Car destroyed: " << model << endl;
    }

};

int main() {

    cout << "Creating a stack object..." << endl;
    // Stack allocation: Memory is managed automatically.
    // Note: No 'new' keyword.
    Car stackCar("Toyota");

    cout << "\nCreating a heap object..." << endl;
    // Heap allocation: Memory must be managed manually using 'new'.
    // Note: We use a pointer (*) to hold the memory address
    Car* heapCar = new Car("Honda");

    // To access the heap object's members, we use the arrow operator (->)
    cout << "Heap Car Model: " << heapCar->model << endl;

    cout << "\n--- End of main function ---" << endl;

    // We must manually delete the heap objects to avoid a memory leak.
    delete heapCar;

    // The stack object will be automatically destroyed when it goes out of scope (at the end of main).
    return 0;
}