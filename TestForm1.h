//
// Created by Vincent on 25.03.24.
//

#ifndef SDLFORMS_TESTFORM1_H
#define SDLFORMS_TESTFORM1_H

#pragma once
#include "Forms/Form.h"
#include "Forms/Controls.h"
#include "iostream"

class TestForm1 : public Forms::Form  {
    private:
        Forms::Rectangle *rect1;
        Forms::Circle *circle1;
        Forms::Label *label;

    public:
        void InitializeComponent();

        TestForm1(std::string _title, Containers::Vector2* _position, Containers::Vector2* _size) : Forms::Form(_title, _position, _size){
            InitializeComponent();
            std::cout << "TestForm.h >>> Child Form Initialization completed." << std::endl;
        }

        void Close();
};


#endif //SDLFORMS_TESTFORM1_H
