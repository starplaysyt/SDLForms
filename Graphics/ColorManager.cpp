//
// Created by Vincent on 17.03.24.
//

#include "ColorManager.h"

using namespace Graphics;

Color::Color() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 255;
}

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

Color* ColorManager::GetColor(SDL_Color* sdlColor) {
    return new Color(sdlColor->r, sdlColor->g, sdlColor->b, sdlColor->a);
}

Color* ColorManager::GetColor(Graphics::ColorEnum color) {
    switch (color) {
        case Red: return new Color(255,0,0,255);
        case Green: return new Color(0,255,0,255);
        case Blue: return new Color(0,0,255,255);
        case Black: return new Color(0,0,0,255);
        case White: return new Color(255,255,255,255);
        default:
            std::cout << "<ColorManager> This color don't supported.";
            break;
    }
}

Color* ColorManager::GetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    return new Color(r, g, b, a);
}

void Color::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Color::SetColor(SDL_Color *sdlColor) {
    r = sdlColor->r;
    g = sdlColor->g;
    b = sdlColor->b;
    a = sdlColor->a;
}

void Color::SetColor(ColorEnum color) {
    switch (color) {
        case Red:
            SetColor(255,0,0,255);
            break;
        case Green:
            SetColor(0,255,0,255);
            break;
        case Blue:
            SetColor(0,0,255,255);
            break;
        case Black:
            SetColor(0,0,0,255);
            break;
        case White:
            SetColor(255,255,255,255);
            break;
        default:
            std::cout << "<ColorManager> This color is not supported.";
            break;
    }
}

void Color::SetColor(Graphics::Color *color) {
    r = color->r;
    g = color->g;
    b = color->b;
    a = color->a;
}

