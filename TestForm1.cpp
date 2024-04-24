//
// Created by Vincent on 25.03.24.
//

#include "TestForm1.h"

namespace UserEvents {
    void button1_OnClick(Forms::IControl *sender, Events::MouseEventArgs *args) {

    }
}

void TestForm1::InitializeComponent() {
    rect1 = new Forms::Rectangle(renderer);
    rect1->Location->Fill(100,100);
    rect1->Size->Fill(100,100);
    rect1->BackgroundColor->SetColor(Graphics::Red);
    rect1->ForegroundColor->SetColor(Graphics::Black);
    rect1->BorderStyle = BorderStyle::FixedSingle;
    Controls->push_back(static_cast<Forms::IControl*>(rect1));

    circle1 = new Forms::Circle(renderer);
    circle1->Location->Fill(100,100);
    *circle1->Radius = 50;
    circle1->BackgroundColor->SetColor(Graphics::White);
    circle1->ForegroundColor->SetColor(Graphics::Green);
    circle1->BorderStyle = BorderStyle::FixedSingle;
    Controls->push_back(static_cast<Forms::IControl*>(circle1));

    label = new Forms::Label(renderer, textRenderer);
    label->Location->Fill(100,50);
    label->Size->Fill(120,200);
    label->BackgroundColor->SetColor(0,255,255,255);
    label->ForegroundColor->SetColor(0,0,0,255);
    *label->AutoSize = true;
    label->TextAllign = TextAllign::TopRight;
    *label->Text = "test";
    Controls->push_back(static_cast<Forms::IControl*>(label));

    button = new Forms::Button(renderer, textRenderer);
    button->Location->Fill(100,100);
    button->Size->Fill(120, 200);
    button->BackgroundColor->SetColor(0,255,0,255);
    button->ForegroundColor->SetColor(0,0,0,255);
    *button->AutoSize = true;
    button->TextAllign = TextAllign::TopRight;
    *button->Text = "testFUCK";
    button->OnClick = &UserEvents::button1_OnClick;
    Controls->push_back(static_cast<Forms::IControl*>(button));
}

void TestForm1::Close() {
    delete rect1;
    delete circle1;
    delete label;
    Forms::Form::Close();
}

