#include <iostream>
#include "Forms/Form.h"
#include "TestForm1.h"

using namespace Forms;
using namespace Containers;
using namespace std;

int main() {

    TestForm1 *form = new TestForm1("test", new Vector2(10,10), new Vector2(200,300));
    std::cout << "main.cpp >>> Child Form Object Creating completed." << std::endl;

    form->StartWindowLoop();

    delete form;

    return 0;
}
