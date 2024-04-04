//
// Created by Vincent on 27.03.24.
//

#ifndef SDLFORMS_TEXTRENDERER_H
#define SDLFORMS_TEXTRENDERER_H

#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "ColorManager.h"
#include "Renderer.h"

namespace Graphics {
    class TextRenderer {
    public:
        void OpenFontFile(std::string path, int size);

        void CloseFontFile();

        TextRenderer(Renderer *sdlRenderer, SDL_Window *window);

        void RenderText(std::string text, int x, int y);

        ~TextRenderer();

        void SetRendererColor(Color color);

        Color GetRendererColor();

    private:

        TTF_Font *TextFont{};
        int *TextSize;
        bool *isFontOpened;
        Renderer *renderer;
        SDL_Window *sdlWindow;
        Color *BackgroundColor;
        Color *ForegroundColor;
    };
}

#endif //SDLFORMS_TEXTRENDERER_H
