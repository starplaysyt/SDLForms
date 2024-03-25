//
// Created by Vincent on 17.03.24.
//
#ifndef SDLFORMS_COLORMANAGER_H
#define SDLFORMS_COLORMANAGER_H

#pragma once
#include <SDL.h>
#include <iostream>

namespace Graphics
{
    enum ColorEnum{
        Red, Green, Blue, Black, White
    };

    struct Color {
    public:
        Uint8 r, g, b, a;

        void SetColor(SDL_Color* sdlColor);
        void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void SetColor(ColorEnum color);
        void SetColor(Color* color);

        Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        Color();
    };

    namespace ColorManager {
        Color* GetColor(SDL_Color* sdlColor);
        Color* GetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        Color* GetColor(ColorEnum color);
    };

}


#endif