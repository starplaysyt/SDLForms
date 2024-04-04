//
// Created by Vincent on 20.03.24.
//

#include "Controls.h"

namespace Forms
{
    //#region Rectangle Methods
    Rectangle::Rectangle(Graphics::Renderer* renderer) {
        assignedRenderer = renderer;
        Location = new Containers::Vector2();
        Size = new Containers::Vector2();
        BorderStyle = BorderStyle::None;
        BackgroundColor = new Graphics::Color();
        ForegroundColor = new Graphics::Color();
    }

    void Rectangle::Draw() {
        switch (BorderStyle) {
            case BorderStyle::None:
                assignedRenderer->SetColor(BackgroundColor);
                assignedRenderer->FillRect(Location, Size);
                break;
            case BorderStyle::FixedSingle:
                assignedRenderer->SetColor(BackgroundColor);
                assignedRenderer->FillRect(Location,Size);
                assignedRenderer->SetColor(ForegroundColor);
                assignedRenderer->DrawRect(Location, Size);
                break;
            default:
                std::cout << "<RectangleRenderer> This BorderStyle is not supported";
                break;
        }
    }

    Rectangle::~Rectangle() {
        delete Location;
        delete Size;
        delete ForegroundColor;
        delete BackgroundColor;
    }
    //#endregion
    //DONE: Create Draw Method

    //#region Circle Methods
    Circle::Circle(Graphics::Renderer *renderer) {
        assignedRenderer = renderer;
        Location = new Containers::Vector2();
        Radius = new int();
        BorderStyle = BorderStyle::None;
        ForegroundColor = new Graphics::Color();
        BackgroundColor = new Graphics::Color();
    }

    void Circle::Draw() {
        switch (BorderStyle) {
            case BorderStyle::None:
                assignedRenderer->FillCircle(Location, *Radius);
                break;
            case BorderStyle::FixedSingle:
                assignedRenderer->SetColor(BackgroundColor);
                assignedRenderer->FillCircle(Location, *Radius);
                assignedRenderer->SetColor(ForegroundColor);
                assignedRenderer->DrawCircle(Location, *Radius);
                break;
            default:
                std::cout << "<CircleRenderer> This BorderStyle is not supported";
                break;
        }
    }

    Circle::~Circle() {
        delete Location;
        delete Radius;
        delete ForegroundColor;
        delete BackgroundColor;
    }
    //#endregion
    //DONE: Create Draw Method

    //#region Label Methods
    Label::Label(Graphics::Renderer *renderer, Graphics::TextRenderer *textRenderer) {
        assignedRenderer = renderer;
        assignedTextRenderer = textRenderer;
        Location = new Containers::Vector2;
        Size = new Containers::Vector2;
        AutoSize = new bool();
        BorderStyle = BorderStyle::None;
        ForegroundColor = new Graphics::Color();
        BackgroundColor = new Graphics::Color();
    }

    void Label::Draw() {
        std::cout << "label drawing started" << std::endl;
        assignedTextRenderer->SetRendererColor(*ForegroundColor);
        assignedTextRenderer->RenderText("testText1", 30, 30);
    }

    Label::~Label() {
        delete Location;
        delete Size;
        delete ForegroundColor;
        delete BackgroundColor;
        delete AutoSize;
    }

    //#endregion

}
