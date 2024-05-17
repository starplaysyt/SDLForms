//
// Created by Vincent on 25.03.24.
//

#ifndef SDLFORMS_TESTFORM1_H
#define SDLFORMS_TESTFORM1_H

#include "Forms/Form.h"
#include "Forms/Controls.h"
#include "iostream"

class TestForm1 : public Forms::Form  {
    public:
        Forms::Rectangle *rect1;
        Forms::Circle *circle1;
        Forms::Label *label;
        Forms::Button *button;
        Forms::TextBox *textbox1;

    public:
        void InitializeComponent();

        TestForm1() : Forms::Form(){
            InitializeComponent();
            std::cout << "TestForm.h >>> Child Form Initialization completed." << std::endl;
        }

        void Close();
};




#endif //SDLFORMS_TESTFORM1_H
