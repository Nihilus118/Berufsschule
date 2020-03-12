#include <iostream>

using namespace std;

class Test {
   private:
    string text;

   public:
    Test();
    ~Test();
};

Test::Test() {
    text = "Test 1";
    cout << text << endl;
}

Test::~Test() {
    cout << "Test 2" << endl;
}
