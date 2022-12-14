#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string &test) {
    return test.size() == 3;
}

class Check {
public:
    bool operator()(string &test) {
        return test.size() == 5;
    }
} check1;

void run(function<bool(string&)> check) {
    string test = "stars";
    cout << check(test) << endl;;
}

int main() {
    int size = 5;
    
    auto lamda = [size](string test){ return test.size() == size;};
    
    vector<string> vec{"one", "two", "three"};
    int count = count_if(vec.begin(), vec.end(), 
                lamda);
    cout << count << endl;
    
    count = count_if(vec.begin(), vec.end(), check);
    cout << count << endl;

    count = count_if(vec.begin(), vec.end(), check1);
    cout << count << endl;

    run(lamda);
    run(check1);
    run(check);

    function<int(int, int)> add = [](int one, int two) {return one+two;};
    cout << add(7, 3) << endl;

    return 0;
}
