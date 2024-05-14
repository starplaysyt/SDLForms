//
// Created by Vincent on 20.03.24.
//
#pragma once
#include "Controls.h"
#include "../Events/BasicEventsAliases.h"
//Totaly unknown why this happens, but it doesnt work without this

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

    bool Rectangle::IsMouseInside(Containers::Vector2 *position) {
        return false;
    }

    void Rectangle::EventCheckup(Uint32 type, SDL_Event *args) {

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

    bool Circle::IsMouseInside(Containers::Vector2 *position) {
        return false;
    }

    void Circle::EventCheckup(Uint32 type, SDL_Event *args) {

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
        Text = new std::string();
        TextAllign = TextAllign::TopLeft;
    }

    bool Label::IsMouseInside(Containers::Vector2 *position) {
        return false;
    }

    void Label::EventCheckup(Uint32 type, SDL_Event *args) {

    }

    void Label::Draw() {
        assignedTextRenderer->SetRendererColor(ForegroundColor);
        SDL_Rect* dst = new SDL_Rect();
        dst->x = *Location->x;
        dst->y = *Location->y;
        SDL_Texture* texture = assignedTextRenderer->CreateTextTexture(*Text, dst);
        assignedRenderer->SetColor(BackgroundColor);
        if(!*AutoSize) {
            switch (TextAllign) {
                case TextAllign::TopLeft:
                    break;
                case TextAllign::TopCenter:
                    dst->x = dst->x + (*Size->x - dst->w)/2;
                    break;
                case TextAllign::TopRight:
                    dst->x = dst->x + (*Size->x - dst->w);
                    break;
                case TextAllign::MiddleLeft:
                    dst->y = dst->y + (*Size->y - dst->h)/2;
                    break;
                case TextAllign::MiddleCenter:
                    dst->y = dst->y + (*Size->y - dst->h)/2;
                    dst->x = dst->x + (*Size->x - dst->w)/2;
                    break;
                case TextAllign::MiddleRight:
                    dst->y = dst->y + (*Size->y - dst->h)/2;
                    dst->x = dst->x + (*Size->x - dst->w);
                    break;
                case TextAllign::BottomLeft:
                    dst->y = dst->y + (*Size->y - dst->h);
                    break;
                case TextAllign::BottomCenter:
                    dst->y = dst->y + (*Size->y - dst->h);
                    dst->x = dst->x + (*Size->x - dst->w)/2;
                    break;
                case TextAllign::BottomRight:
                    dst->y = dst->y + (*Size->y - dst->h);
                    dst->x = dst->x + (*Size->x - dst->w);
                    break;
            }
        }
        else {
            *Size->x = dst->w;
            *Size->y = dst->h;
        }
        assignedRenderer->FillRect(Location, Size);
        assignedTextRenderer->PasteTextTexture(texture, dst);
        SDL_DestroyTexture(texture);
        delete dst;
    }

    Label::~Label() {
        delete Location;
        delete Size;
        delete ForegroundColor;
        delete BackgroundColor;
        delete AutoSize;
        delete Text;
    }

    //#endregion
    //DONE: Create Draw Method

    //#region Button Methods
    Button::Button(Graphics::Renderer *renderer, Graphics::TextRenderer *textRenderer){
        assignedRenderer = renderer;
        assignedTextRenderer = textRenderer;
        Location = new Containers::Vector2;
        Size = new Containers::Vector2;
        AutoSize = new bool();
        BorderStyle = BorderStyle::None;
        ForegroundColor = new Graphics::Color();
        BackgroundColor = new Graphics::Color();
        Text = new std::string();
        TextAllign = TextAllign::TopLeft;
        OnClick = &Events::BasicEventsAliases::MouseClickEvent;
        OnEnter = &Events::BasicEventsAliases::MouseMotionEvent;
        OnMove = &Events::BasicEventsAliases::MouseMotionEvent;
        OnLeft = &Events::BasicEventsAliases::MouseMotionEvent;
        OnMouseDown = &Events::BasicEventsAliases::MouseClickEvent;
        OnMouseUp = &Events::BasicEventsAliases::MouseClickEvent;
        isMouseInside = new bool();
        isClicked = new bool();
        *isMouseInside = false;
        *isClicked = false;
    }

    bool Button::IsMouseInside(Containers::Vector2 *position) {
        if (*position->x > *Location->x && *position->x < *Location->x + *Size->x)
            if (*position->y > *Location->y && *position->y < *Location->y + *Size->y) {
                return true;
            }
        return false;
    }

    void Button::EventCheckup(Uint32 type, SDL_Event *event) {
        switch (type) {
            case 0: //nullevent code designed for leaving/not-encountered events or stuff
                if (*isMouseInside) {
                    *isMouseInside = false;
                    if(event->type == SDL_MOUSEMOTION) OnLeft(this, event->motion); //idk what shit should happen for this checkup worked
                }
                if (*isClicked) {
                    *isClicked = false;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                *isClicked = true;
                OnMouseDown(this, event->button);
                break;
            case SDL_MOUSEBUTTONUP:
                OnMouseUp(this, event->button);
                if (*isClicked)
                    OnClick(this, event->button);
                *isClicked = false;
            case SDL_MOUSEMOTION:
                if (*isMouseInside) {
                    OnMove(this, event->motion);
                }
                else {
                    *isMouseInside = true;
                    OnEnter(this, event->motion);
                }
                break;
            default:
                std::cout << "Button " << *Text << " >>> Unhandled event happened. It's not supported by the way." << std::endl;
                //TODO: REMOVE FUCKING SHIT, IT IS FUCKING WRONG(stupid cocksucker, it's designed for act like that, though)
                //UTODO: It should work like that
                break;
        }
    }

    void Button::Draw() {
        assignedTextRenderer->SetRendererColor(ForegroundColor);
        assignedRenderer->SetColor(BackgroundColor);
        if (*isMouseInside) {
            assignedRenderer->SetColor(ForegroundColor);
            assignedTextRenderer->SetRendererColor(BackgroundColor);
        }
        if (*isClicked) {
            assignedRenderer->SetColor(Graphics::ColorManager::GetColor(Graphics::Green));
            assignedTextRenderer->SetRendererColor(Graphics::ColorManager::GetColor(Graphics::White));
        }

        auto* dst = new SDL_Rect();
        dst->x = *Location->x;
        dst->y = *Location->y;
        SDL_Texture* texture = assignedTextRenderer->CreateTextTexture(*Text, dst);

        if(!*AutoSize) {
            switch (TextAllign) {
                case TextAllign::TopLeft:
                    break;
                case TextAllign::TopCenter:
                    dst->x = dst->x + (*Size->x - dst->w)/2;
                    break;
                case TextAllign::TopRight:
                    dst->x = dst->x + (*Size->x - dst->w);
                    break;
                case TextAllign::MiddleLeft:
                    dst->y = dst->y + (*Size->y - dst->h)/2;
                    break;
                case TextAllign::MiddleCenter:
                    dst->y = dst->y + (*Size->y - dst->h)/2;
                    dst->x = dst->x + (*Size->x - dst->w)/2;
                    break;
                case TextAllign::MiddleRight:
                    dst->y = dst->y + (*Size->y - dst->h)/2;
                    dst->x = dst->x + (*Size->x - dst->w);
                    break;
                case TextAllign::BottomLeft:
                    dst->y = dst->y + (*Size->y - dst->h);
                    break;
                case TextAllign::BottomCenter:
                    dst->y = dst->y + (*Size->y - dst->h);
                    dst->x = dst->x + (*Size->x - dst->w)/2;
                    break;
                case TextAllign::BottomRight:
                    dst->y = dst->y + (*Size->y - dst->h);
                    dst->x = dst->x + (*Size->x - dst->w);
                    break;
            }
        }
        else {
            *Size->x = dst->w;
            *Size->y = dst->h;
        }
        assignedRenderer->FillRect(Location, Size);
        if (BorderStyle == BorderStyle::FixedSingle) {
            assignedRenderer->SetColor(ForegroundColor);
            assignedRenderer->DrawRect(Location, Size);
        }
        assignedTextRenderer->PasteTextTexture(texture, dst);

        //Destruct area

        SDL_DestroyTexture(texture);
        delete dst;
    }

    Button::~Button() {
        delete Location;
        delete Size;
        delete ForegroundColor;
        delete BackgroundColor;
        delete AutoSize;
        delete Text;
    }
}
