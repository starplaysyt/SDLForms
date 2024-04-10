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
        /*
         * Open
         */
        void OpenFontFile(std::string path, int size);

        void CloseFontFile();

        /*
         * Creates instance of TextRenderer.
         * Quick guide to use TextRenderer:
         * - First things first you need to open font file, use OpenFontFile.
         * - Use RenderText for simple rendering text on window.
         * - Use CreateTextTexture and PasteTextTexture for advanced rendering.
         * - After finishing working with TextRendering, use CloseFontFile to
         *      close font file.
         */
        TextRenderer(Renderer *renderer, SDL_Window *window);

        void RenderText(std::string text, int x, int y);

        /*
         * Creates texture with text, advanced version of RenderText.
         * Useful when size of text is needed, with PasteTextTexture.
         */
        SDL_Texture* CreateTextTexture(std::string text, SDL_Rect* dst);

        /*
         * Pastes texture with text into renderers' buffer.
         * Useful with CreateTextTexture.
         * Doesnt destroy texture, you should destroy it manually.
         */
        void PasteTextTexture(SDL_Texture* texture, SDL_Rect* dst);


        ~TextRenderer();

        void SetRendererColor(Color* color);

    private:

        TTF_Font *TextFont{};
        int *TextSize;
        bool *isFontOpened;
        Renderer *renderer;
        SDL_Window *sdlWindow;
        Color *ForegroundColor;
    };
}

#endif //SDLFORMS_TEXTRENDERER_H
