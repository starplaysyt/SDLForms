//
// Created by Vincent on 25.03.24.
//

#include "TestForm1.h"

namespace UserEvents {
    void button1_OnClick(Forms::IControl *sender, SDL_MouseButtonEvent args) {
        
    }

    void button1_OnEnter(Forms::IControl *sender, SDL_MouseMotionEvent args) {
        //std::cout << "enter" << std::endl;
    }

    void button1_OnMove(Forms::IControl *sender, SDL_MouseMotionEvent args) {
        //std::cout << "moved" << std::endl;
    }

    void button1_OnLeft(Forms::IControl *sender, SDL_MouseMotionEvent args) {
        //std::cout << "left" << std::endl;
    }

    void button1_OnMouseDown(Forms::IControl *sender, SDL_MouseButtonEvent args) {
        std::cout << "Down" << std::endl;
    }

    void button1_OnMouseUp(Forms::IControl *sender, SDL_MouseButtonEvent args) {
        std::cout << "Up" << static_cast<int>(args.button) << std::endl;
    }
}

void TestForm1::InitializeComponent() {
    Location->Fill(100, 100);
    Size->Fill(500, 400);
    *Title = "300";

    rect1 = new Forms::Rectangle(renderer);
    rect1->Location->Fill(100,100);
    rect1->Size->Fill(100,100);
    rect1->BackgroundColor->SetColor(Graphics::Red);
    rect1->ForegroundColor->SetColor(Graphics::Black);
    rect1->BorderStyle = BorderStyle::FixedSingle;
    AddControl(rect1);

    circle1 = new Forms::Circle(renderer);
    circle1->Location->Fill(100,100);
    *circle1->Radius = 50;
    circle1->BackgroundColor->SetColor(Graphics::White);
    circle1->ForegroundColor->SetColor(Graphics::Green);
    circle1->BorderStyle = BorderStyle::FixedSingle;
    AddControl(circle1);

    label = new Forms::Label(renderer, textRenderer);
    label->Location->Fill(100,50);
    label->Size->Fill(120,200);
    label->BackgroundColor->SetColor(0,255,255,255);
    label->ForegroundColor->SetColor(0,0,0,255);
    *label->AutoSize = true;
    *label->TextSize = 30;
    label->TextAllign = TextAllign::TopRight;
    *label->Text = "test";
    AddControl(label);

    button = new Forms::Button(renderer, textRenderer);
    button->Location->Fill(100,100);
    button->Size->Fill(120, 120);
    button->BackgroundColor->SetColor(0,255,0,100);
    button->ForegroundColor->SetColor(0,0,0,255);
    *button->AutoSize = false;
    button->TextAllign = TextAllign::TopRight;
    *button->Text = "testFUCK";
    button->BorderStyle = BorderStyle::FixedSingle;
    button->OnClick = &UserEvents::button1_OnClick;
    button->OnEnter = &UserEvents::button1_OnEnter;
    button->OnMove = &UserEvents::button1_OnMove;
    button->OnLeft = &UserEvents::button1_OnLeft;
    button->OnMouseDown = &UserEvents::button1_OnMouseDown;
    button->OnMouseUp = &UserEvents::button1_OnMouseUp;
    AddControl(button);

    textbox1 = new Forms::TextBox(renderer, textRenderer);
    textbox1->Location->Fill(200,200);
    textbox1->Size->Fill(20,20);
    textbox1->BackgroundColor->SetColor(0,255,0,100);
    textbox1->ForegroundColor->SetColor(0,0,0,255);
    *textbox1->AutoSize = true;
    textbox1->TextAllign = TextAllign::TopLeft;
    *textbox1->Text = "area";
    textbox1->BorderStyle = BorderStyle::None;
    AddControl(textbox1);
}

void TestForm1::Close() {
    delete rect1;
    delete circle1;
    delete label;
    Forms::Form::Close();
}

