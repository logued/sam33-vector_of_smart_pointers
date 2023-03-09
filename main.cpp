// 		Vector of Smart Pointers (unique_ptr)		March 2023
//
// https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170
// Smart pointers are defined in the std namespace in the <memory> header file.

// This sample is based on the "inheritance-abstract-base-class-shape" sample and
// all changes were made only in the main.cpp file.
//
// This uses a vector of SMART POINTERS (unique_ptr type) to point at Shape objects
// and therefore there is no need for the programmer to remember to delete
// the memory allocated from the heap, as the smart pointer looks after that
// aspect automatically (When the smart pointer's life ends, then a call is made
// to delete the object that the smart pointer is pointing at))
// Programmers are far less likely to have memory leaks in their code when
// using smart pointers.
//
// A unique_ptr can not be copied or assigned, so we use references to the
// unique pointers to access them.
//
// As before ......
// Virtual functions are member functions whose behavior can be overridden in derived classes.
//
// Demonstrates definition of Pure Virtual Functions (=0) in a Base class.
// Defining one (or more) pure virtual functions makes a class an "Abstract class".
// Derived classes (subclasses) must implement all pure virtual functions
// inherited from a Base class.
//
// **** Dynamic Binding - Runtime Binding - Runtime Polymorphism ****
// When the draw() method is called using a pointer of the Base class type (i.e. Shape*)
// it is not known which concrete implementation of the draw() method will be called until runtime
// i.e. (is it draw() for a Circle or draw() for a Rectangle ?)
// (The pointer could be pointing at any class derived from the Base class)
//
// If the object pointed at is a Circle object, then the draw() function that was
// defined in the Circle class is called.
// If the object pointed at is a Rectangle object, then the draw() function
// defined in Rectangle is called.  This is behavior is called
// "Runtime Polymorphism" or "Run Time Binding" or "Late Binding",
// because the version of draw() to call is not known
// until the type of the object is presented. (We can't 'bind' to the draw() method
// until we see what type of object we are presented with.

// **** virtual functions and 'pure' virtual functions ****
//
// An abstract class contains at least one pure virtual function.
// You declare a pure virtual function by using a pure specifier (= 0)
// in the declaration of a virtual member function in the class declaration.
//
// A "virtual function" has a definition/implementation in the Base class and is preceded by the word "virtual".
//     	virtual void draw() { cout << "Drawing a Shape"; }
//
// This tells the compiler that we want to allow derived classes to define their own version of the
// virtual function, and, that we want to use Runtime Polymorphism (runtime binding) when we use
// pointers of the Base class type to point at derived class objects.
//
// A "pure virtual function" is declared in the Base class but with NO implementation, and
// is followed by the 'pure virtual' specifier "=0"
// 	    virtual void draw() =0;
//
// This tells the compiler that ALL derived classes MUST implement the function.
//
// If a class contains at least one pure virtual function, then that
// class becomes an Abstract Class.  This means that we can NOT instantiate objects
// of this base class type.  (In our example, we can't make Shape objects, because
// Shape is an Abstract class.)
//

#include <iostream>
#include <vector>
#include <memory>       // for unique_ptr (SMART POINTER)
#include "Circle.h"
#include "Shape.h"
#include "Rectangle.h"

using namespace std;

void fillShapesVector(vector<unique_ptr<Shape>>& vec);

int main() //  polymorphism in Action - polymorphism ONLY works with POINTERS (or references)
{
    //https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170
    // Smart pointers are defined in the std namespace in the <memory> header file.

    // Vector of unique_ptr (SMART POINTERS) to Shape objects.
    // unique_ptr is a type of smart pointer.
    vector<unique_ptr<Shape>> shapes;

    fillShapesVector(shapes);

//    shapes.push_back( unique_ptr<Shape> (new Circle(1, 3, 5)));
//    shapes.push_back( unique_ptr<Shape> (new Rectangle(8, 6, 20, 25)));

    for (unique_ptr<Shape>& shapePtr : shapes)      // must use reference so as not to copy
    {
        // use the smart pointer just as we use raw pointer
        shapePtr->draw();		// polymorphic behaviour, uses dynamic binding
    }
    // No longer any need to explicitly delete the shape objects that were pointed at by vector elements.

    cout << "About to clear the contents of the vector. This will free the vector elements "
            << "from the stack, and their life will end. Just before the elements are destroyed, "
            << "a destructor is called that deletes the memory pointed to by the unique_ptr. "
            << "We see below that the destructors for the Circle and Rectangle are called. "
            << "Thus, the memory is deleted automatically for us, and we don't have to worry about "
            << "forgetting to free that memory.  This idiom is known as RAII" << endl;

    shapes.clear(); // clear the contents of the vector as the objects they point to have been freed.

    cout<< "At end of main()" << endl;
}

void fillShapesVector(vector<unique_ptr<Shape>>& vectorRef)  // reference to a vector
{
    // Dynamically allocate a Circle object.
    // Pass it immediately into a unique_ptr constructor.
    // The unique_ptr is created on the stack (so it is an automatic variable)
    // Add the unique pointer to the vector.
    vectorRef.push_back( unique_ptr<Shape> (new Circle(1, 3, 5)));
    vectorRef.push_back( unique_ptr<Shape> (new Rectangle(8, 6, 20, 25)));

    // etc.. shapes could be read from a file
}