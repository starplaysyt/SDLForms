#include <iostream>
#include "Forms/Form.h"
#include "TestForm1.h"

using namespace Forms;
using namespace Containers;
using namespace std;

int main() {

    Vector2 *point = new Vector2(10,10);
    cout << point->x << endl;
    point->x += 11;
    cout << point->x << endl;
    std::cout << "Hello, World!" << std::endl;

    TestForm1 *form = new TestForm1("test", new Vector2(10,10), new Vector2(200,300));
    std::cout << "Comp";

    form->StartWindowLoop();

    delete form;


    return 0;
}
