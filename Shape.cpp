// Shape.cpp

#include "Shape.h"
#include<iostream>

using namespace std;

//Implementation of the virtual destructor

// When a derived class of Shape (e.g. Circle object) is destroyed
// its destructor is called ( ~Circle() )
// Then, the destructor of the Shape class is called.  This gives the opportunity
// to the derived class to free up its resources, and then gives the Shape class
// the chance for it to free up any resources it may have dynamically allocated.

Shape::~Shape() {
    cout << "~Shape() destructor was called. The Shape base destructor is called "
    << "after the destructor of the derived class was called.\n"; }

