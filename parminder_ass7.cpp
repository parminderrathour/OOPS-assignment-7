// ============================================================
//  Lab Assignment 7 — Object Oriented Programming
//  Name   : Parminder Rathour
//  Topics : Polymorphism | Virtual Functions | Operator Overloading
// ============================================================


// ============================================================
// Q1. Polymorphism using Base Class Pointer (Polygon → Rectangle & Triangle)
// Concept: A base class pointer can point to derived class objects.
//          Using virtual functions, the correct derived version is called.
// ============================================================
/*
#include <iostream>
using namespace std;

class Polygon {
public:
    int width, height;

    void set_value(int w, int h) {
        width = w;
        height = h;
    }

    // virtual ensures the derived class version is called via base pointer
    virtual void calculate_area() =0;
};

class Rectangle : public Polygon {
public:
    void calculate_area() {
        cout << "Rectangle Area = " << width * height << endl;
    }
};

class Triangle : public Polygon {
public:
    void calculate_area() {
        cout << "Triangle Area = " << (width * height) / 2 << endl;
    }
};

int main() {
    Rectangle r;
    Triangle t;

    // Base class pointers pointing to derived objects
    Polygon *p1 = &r;
    Polygon *p2 = &t;

    p1->set_value(4, 5);
    p2->set_value(4, 5);

    p1->calculate_area();   
    p2->calculate_area();  

    return 0;
}
*/

// ============================================================
// Q2. Virtual Functions — Shape, Circle, Rectangle, Triangle
// Concept: Pure virtual function (= 0) forces derived classes
//          to provide their own implementation.
// ============================================================


#include <iostream>
#include <cmath>
using namespace std;

// Abstract base class
class Shape {
public:
    virtual double area() = 0;    // pure virtual
    virtual void display() = 0;   // pure virtual
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) { radius = r; }

    double area() {
        return 3.14159 * radius * radius;
    }

    void display() {
        cout << "Shape   : Circle" << endl;
        cout << "Radius  : " << radius << endl;
        cout << "Area    : " << area() << endl;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) { width = w; height = h; }

    double area() {
        return width * height;
    }

    void display() {
        cout << "Shape   : Rectangle" << endl;
        cout << "Width   : " << width << ", Height: " << height << endl;
        cout << "Area    : " << area() << endl;
    }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) { base = b; height = h; }

    double area() {
        return 0.5 * base * height;
    }

    void display() {
        cout << "Shape   : Triangle" << endl;
        cout << "Base    : " << base << ", Height: " << height << endl;
        cout << "Area    : " << area() << endl;
    }
};

int main() {
    Circle    c(5);
    Rectangle r(4, 6);
    Triangle  t(3, 8);

    c.display(); cout << endl;
    r.display(); cout << endl;
    t.display();

    return 0;
}



// ============================================================
// Q3. Function Overloading — Triangle Area (Right, Equilateral, Isosceles)
// Concept: Same function name, different parameters.
//          Compiler picks the correct version based on arguments.
// ============================================================

/*
#include <iostream>
#include <cmath>
using namespace std;

// Right angle triangle: (1/2) * base * height
double area(double base, double height) {
    return 0.5 * base * height;
}

// Equilateral triangle: (sqrt(3)/4) * side^2
double area(double side) {
    return (sqrt(3) / 4) * side * side;
}

// Isosceles triangle: (base/4) * sqrt(4*side^2 - base^2)
// 'flag' differentiates this from the right-angle overload
double area(double base, double side, int flag) {
    return (base / 4) * sqrt(4 * side * side - base * base);
}

int main() {
    cout << "Right Angle Triangle Area (base=6, height=4) : " << area(6.0, 4.0)    << endl;
    cout << "Equilateral Triangle Area (side=5)           : " << area(5.0)          << endl;
    cout << "Isosceles Triangle Area  (base=6, side=5)   : " << area(6.0, 5.0, 1)  << endl;

    return 0;
}
*/


// ============================================================
// Q4. Abstract Class — Student with Engineering, Medicine, Science
// Concept: Abstract class has at least one pure virtual function.
//          Objects of derived classes are accessed via base class pointer array.
// ============================================================

/*
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int rollNo;

    Student(string n, int r) { name = n; rollNo = r; }

    virtual void display() = 0;  // pure virtual
};

class Engineering : public Student {
public:
    Engineering(string n, int r) : Student(n, r) {}
    void display() {
        cout << "[Engineering] Name: " << name << ", Roll: " << rollNo << endl;
    }
};

class Medicine : public Student {
public:
    Medicine(string n, int r) : Student(n, r) {}
    void display() {
        cout << "[Medicine]    Name: " << name << ", Roll: " << rollNo << endl;
    }
};

class Science : public Student {
public:
    Science(string n, int r) : Student(n, r) {}
    void display() {
        cout << "[Science]     Name: " << name << ", Roll: " << rollNo << endl;
    }
};

int main() {
    Engineering e("Parminder", 101);
    Medicine    m("Rahul",     202);
    Science     s("Priya",     303);

    // Array of base class pointers
    Student* arr[3] = { &e, &m, &s };

    for (int i = 0; i < 3; i++) {
        arr[i]->display();
    }

    return 0;
}
*/


// ============================================================
// Q5. Operator Overloading — Add Two Time Objects using '+'
// Concept: Redefine the '+' operator for your own class.
//          Carry-over seconds → minutes → hours is handled manually.
// ============================================================

/*
#include <iostream>
using namespace std;

class Time {
    int h, m, s;
public:
    Time() { h = 0; m = 0; s = 0; }

    Time(int hh, int mm, int ss) {
        h = hh; m = mm; s = ss;
    }

    // Overload '+' operator
    Time operator+(Time t) {
        Time result;
        result.s = s + t.s;
        result.m = m + t.m + result.s / 60;
        result.s = result.s % 60;
        result.h = h + t.h + result.m / 60;
        result.m = result.m % 60;
        return result;
    }

    void show() {
        cout << h << " hours, " << m << " minutes, " << s << " seconds" << endl;
    }
};

int main() {
    Time t1(5, 15, 34), t2(9, 53, 58), t3;
    t3 = t1 + t2;
    cout << "Sum of times: ";
    t3.show();
    return 0;
}
*/


// ============================================================
// Q6. Operator Overloading — STRING class (== and +)
// Concept: Overload == to compare strings, + to concatenate.
// ============================================================

/*
#include <iostream>
#include <cstring>
using namespace std;

class STRING {
    char str[100];
public:
    STRING() { str[0] = '\0'; }

    STRING(const char* s) { strcpy(str, s); }

    // Overload == : compare two strings
    bool operator==(STRING s) {
        return strcmp(str, s.str) == 0;
    }

    // Overload + : concatenate two strings
    STRING operator+(STRING s) {
        STRING temp;
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    void display() { cout << str << endl; }
};

int main() {
    STRING s1("Hello "), s2("World"), s3;

    s3 = s1 + s2;
    cout << "Concatenated: ";
    s3.display();

    if (s1 == s2)
        cout << "Strings are equal." << endl;
    else
        cout << "Strings are not equal." << endl;

    return 0;
}
*/


// ============================================================
// Q7. Operator Overloading — Matrix * using Friend Function
// Concept: Friend function has access to private members.
//          Used here to overload * for two matrix objects.
// ============================================================

/*
#include <iostream>
using namespace std;

class Matrix {
    int a[2][2];
public:
    void input() {
        cout << "Enter 4 elements (2x2 matrix):" << endl;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                cin >> a[i][j];
    }

    void display() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    // Friend function to overload *
    friend Matrix operator*(Matrix m1, Matrix m2);
};

Matrix operator*(Matrix m1, Matrix m2) {
    Matrix result;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            result.a[i][j] = 0;
            for (int k = 0; k < 2; k++)
                result.a[i][j] += m1.a[i][k] * m2.a[k][j];
        }
    return result;
}

int main() {
    Matrix m1, m2, m3;
    m1.input();
    m2.input();
    m3 = m1 * m2;
    cout << "Result Matrix:" << endl;
    m3.display();
    return 0;
}
*/


// ============================================================
// Q8. Overload '[]' — Array Index Out of Bounds Check
// Concept: Overloading [] lets us add a safety check
//          before accessing any element of our array.
// ============================================================

/*
#include <iostream>
using namespace std;

class SafeArray {
    int arr[5];
    int size;
public:
    SafeArray() {
        size = 5;
        for (int i = 0; i < size; i++)
            arr[i] = i * 10;  // sample data: 0, 10, 20, 30, 40
    }

    // Overload []
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "ERROR: Index " << index << " is out of bounds!" << endl;
            exit(1);
        }
        return arr[index];
    }
};

int main() {
    SafeArray a;
    cout << "a[2] = " << a[2] << endl;  // valid
    cout << "a[4] = " << a[4] << endl;  // valid
    cout << "a[7] = " << a[7] << endl;  // out of bounds — will show error
    return 0;
}
*/


// ============================================================
// Q9. Overload '()' — Arbitrary Number of Input Arguments
// Concept: Overloading () lets an object behave like a function.
//          Different versions handle different argument counts.
// ============================================================

/*
#include <iostream>
using namespace std;

class Input {
public:
    void operator()(int a) {
        cout << "One argument  : " << a << endl;
    }

    void operator()(int a, int b) {
        cout << "Two arguments : " << a << ", " << b << endl;
    }

    void operator()(int a, int b, int c) {
        cout << "Three arguments: " << a << ", " << b << ", " << c << endl;
    }
};

int main() {
    Input obj;
    obj(10);
    obj(10, 20);
    obj(10, 20, 30);
    return 0;
}
*/


// ============================================================
// Q10. Overload Input (>>) and Output (<<) Operators
// Concept: >> and << must be overloaded as friend functions
//          because the left operand is cin/cout, not our object.
// ============================================================

/*
#include <iostream>
using namespace std;

class Student {
    string name;
    int rollNo;
public:
    friend istream& operator>>(istream& in, Student& s) {
        cout << "Enter name       : ";
        in >> s.name;
        cout << "Enter roll number: ";
        in >> s.rollNo;
        return in;
    }

    friend ostream& operator<<(ostream& out, Student& s) {
        out << "Name: " << s.name << ", Roll No: " << s.rollNo;
        return out;
    }
};

int main() {
    Student s;
    cin >> s;   // uses overloaded >>
    cout << s;  // uses overloaded <<
    return 0;
}
*/


// ============================================================
// Q11. Type Conversion — float to User-Defined Type (Object)
// Concept: A constructor that accepts a basic type enables
//          automatic conversion from that type to the class object.
// ============================================================

/*
#include <iostream>
using namespace std;

class Test {
    float value;
public:
    // Conversion constructor: float -> Test
    Test(float f) {
        value = f;
        cout << "Converted float " << f << " to Test object." << endl;
    }

    void display() {
        cout << "Value inside object: " << value << endl;
    }
};

int main() {
    float f = 3.14;
    Test t = f;   // automatic conversion using constructor
    t.display();
    return 0;
}
*/


// ============================================================
// Q12. Type Conversion — User-Defined Type (Object) to float
// Concept: A conversion operator (operator float()) allows
//          an object to be automatically converted to a basic type.
// ============================================================

/*
#include <iostream>
using namespace std;

class Test {
    float value;
public:
    Test(float v) { value = v; }

    // Conversion operator: Test -> float
    operator float() {
        cout << "Converting Test object to float..." << endl;
        return value;
    }
};

int main() {
    Test t(9.81);
    float f = t;   // automatic conversion using operator float()
    cout << "Float value: " << f << endl;
    return 0;
}
*/


// ============================================================
// Q13. Type Conversion — UDT to UDT (Polar to Cartesian)
// Concept: A conversion constructor in the destination class
//          that takes the source class enables UDT-to-UDT conversion.
//          x = r * cos(theta),  y = r * sin(theta)
// ============================================================

/*
#include <iostream>
#include <cmath>
using namespace std;

class Cartesian;  // forward declaration needed

class Polar {
public:
    double r, theta;
    Polar(double r, double t) { this->r = r; this->theta = t; }
};

class Cartesian {
    double x, y;
public:
    // Conversion constructor: Polar -> Cartesian
    Cartesian(Polar p) {
        x = p.r * cos(p.theta);
        y = p.r * sin(p.theta);
    }

    void show() {
        cout << "Cartesian: x = " << x << ", y = " << y << endl;
    }
};

int main() {
    Polar p(10, 0.5236);  // r=10, theta=30 degrees in radians
    Cartesian c = p;      // automatic conversion
    c.show();
    return 0;
}
*/
