#include "log.h"
#include <iostream>

using namespace std;

int main()
{
    Log l1("C:/Users/nhant/directory.txt");
    l1 << "hello";
    l1.close_log();
    cout << "Hello World!" << endl;
    return 0;
}
