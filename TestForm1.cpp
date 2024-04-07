//
// Created by Vincent on 25.03.24.
//

#include "TestForm1.h"


void TestForm1::InitializeComponent() {


    rect1 = new Forms::Rectangle(renderer);
    rect1->Location->Fill(100,100);
    rect1->Size->Fill(100,100);
    rect1->BackgroundColor->SetColor(Graphics::Red);
    rect1->ForegroundColor->SetColor(Graphics::Black);
    rect1->BorderStyle = BorderStyle::FixedSingle;
    Controls->push_back(static_cast<Forms::IDrawable*>(rect1));

    circle1 = new Forms::Circle(renderer);
    circle1->Location->Fill(100,100);
    *circle1->Radius = 50;
    circle1->BackgroundColor->SetColor(Graphics::White);
    circle1->ForegroundColor->SetColor(Graphics::Green);
    circle1->BorderStyle = BorderStyle::FixedSingle;
    Controls->push_back(static_cast<Forms::IDrawable*>(circle1));

    label = new Forms::Label(renderer, textRenderer);
    label->Location->Fill(100,100);
    label->Size->Fill(100,100);
    label->BackgroundColor->SetColor(Graphics::Red);
    label->ForegroundColor->SetColor(Graphics::Red);
    Controls->push_back(static_cast<Forms::IDrawable*>(label));
}

void TestForm1::Close() {
    delete rect1;
    delete circle1;
    delete label;
    Forms::Form::Close();
}