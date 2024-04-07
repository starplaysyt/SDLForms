//
// Created by Vincent on 27.03.24.
//

#include "TextRenderer.h"

using namespace Graphics;

void TextRenderer::OpenFontFile(std::string path, int size) {
    if (*isFontOpened) {
        std::cout << "Font File is already opened."; //TODO: Make standard error output
        return;
    }
    TextFont = TTF_OpenFont(path.c_str(), size);
    *isFontOpened = true;
}

TextRenderer::TextRenderer(Renderer *renderer, SDL_Window *window) {
    this->renderer = renderer;
    this->sdlWindow = window;
    isFontOpened = new bool();
    TextSize = new int();
    ForegroundColor = new Color();
    BackgroundColor = new Color();
}

void TextRenderer::CloseFontFile() {
    if (!*isFontOpened) {
        std::cout << "Font File is already closed."; //TODO: Make standard error output
        return;
    }
    TTF_CloseFont(TextFont);
    *isFontOpened = false;
}

void TextRenderer::SetRendererColor(Graphics::Color *color) {
    ForegroundColor = color;
}

void TextRenderer::RenderText(std::string text, int x, int y) {
    if (!*isFontOpened) {
        std::cout << "Font File is not loaded."; //TODO: Make standard error output
        return;
    }
    //std::cout << "Test:: Text Output";
    auto *RpcColor = new SDL_Color();
    RpcColor->r = ForegroundColor->r;
    RpcColor->g = ForegroundColor->g;
    RpcColor->b = ForegroundColor->b;
    RpcColor->a = ForegroundColor->a;
    SDL_Surface *surf = TTF_RenderUTF8_Blended(TextFont, text.c_str(), *RpcColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer->GetSDLRenderer(), surf);
    if (texture == 0){
        TTF_Quit();
        SDL_Quit();
        std::cout << "Failed to create texture. Quitting...";
        return;
    }
    SDL_FreeSurface(surf);
    uint *format = new uint();
    int *access = new int();
    int *w = new int();
    int *h = new int();
    SDL_QueryTexture(texture, format, access, w, h);
    auto *dst = new SDL_Rect();
    dst->x = x;
    dst->y = y;
    dst->w = *w;
    dst->h = *h;

    SDL_RenderCopy(renderer->GetSDLRenderer(), texture, 0, dst);
    SDL_DestroyTexture(texture);

    delete format;
    delete access;
    delete w; delete h;
    delete dst;
    delete RpcColor;
}

SDL_Texture *TextRenderer::CreateTextTexture(std::string text, SDL_Rect *dst) {

}



