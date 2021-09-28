#include <iostream>

//using namespace std;

class Incognizable {
public:
    Incognizable () {}
    Incognizable (const int& num) {
        a = num;
    }
    Incognizable (const int& num1, const int& num2) {
        a = num1;
        b = num2;
    }
private:
    int a;
    int b;
};

// int main() {
//   Incognizable a;
//   Incognizable b = {};
//   Incognizable c = {0};
//   Incognizable d = {0, 1};
//   return 0;
// }
