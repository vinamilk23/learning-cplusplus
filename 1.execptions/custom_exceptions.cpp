#include <iostream>
#include <exception>
using namespace std;

class MyException: public exception {
public:
    virtual const char* what() const throw() {
        return "Something bad happened!";
    }
};

class Test {
public: 
    void goesWrong() {
        throw MyException();
    }
};

int main() {
    Test test;
    try {
        test.goesWrong();
    } catch (MyException &e) {
        cout << "Caught exectpion: " << e.what() << endl;
    }
    
    cout << "Still running" << endl;
    return 0;
}