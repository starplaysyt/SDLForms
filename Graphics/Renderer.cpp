#include "Renderer.h"

using namespace Graphics;

Renderer::Renderer(SDL_Renderer *sdlRenderer, SDL_Window *window) {
    this->sdlRenderer = sdlRenderer;
    this->parentWindow = window;
    std::cout << "Render.cpp >>> Renderer initialization completed" << std::endl;
}

void Renderer::CompleteRender() {
    SDL_RenderPresent(sdlRenderer);
    SDL_RenderClear(sdlRenderer);
}

void Renderer::SetColor(Graphics::Color *color) {
    SDL_SetRenderDrawColor(sdlRenderer, color->r, color->g, color->b, color->a);
}


//TODO: Make it smarter, shit is slow(maybe)
void Renderer::SetColor(Graphics::ColorEnum ecolor) {
    Color *color = new Color();
    color = ColorManager::GetColor(ecolor);
    SDL_SetRenderDrawColor(sdlRenderer, color->r, color->g, color->b, color->a);
    delete color;
}

void Renderer::DrawLine(Containers::Vector2* pos1, Containers::Vector2* pos2) {
    SDL_RenderDrawLine(sdlRenderer, pos1->x, pos1->y, pos2->x, pos2->y);
}

void Renderer::DrawRect(Containers::Vector2* position, Containers::Vector2* size) {
    auto *rect = new SDL_Rect();
    rect->x = position->x;
    rect->y = position->y;
    rect->w = size->x;
    rect->h = size->y;
    SDL_RenderDrawRect(sdlRenderer, rect);
    delete rect;
}

void Renderer::FillRect(Containers::Vector2* position, Containers::Vector2* size) {
    auto *rect = new SDL_Rect();
    rect->x = position->x;
    rect->y = position->y;
    rect->w = size->x;
    rect->h = size->y;
    SDL_RenderFillRect(sdlRenderer, rect);
    delete rect;
}

void Renderer::FillCircle(Containers::Vector2* centre, int radius) {
    int *diameter = new int(); *diameter = (radius * 2);
    int *x = new int(); *x = (radius - 1);
    int *y = new int(); *y = 0;
    int *tx = new int(); *tx = 1;
    int *ty = new int(); *ty = 1;
    int *error = new int(); *error = (*tx - *diameter);

    while (*x >= *y)
    {
        SDL_RenderDrawLine(sdlRenderer, centre->x - *x, centre->y - *y, centre->x, centre->y - *y);
        SDL_RenderDrawLine(sdlRenderer, centre->x - *y, centre->y - *x, centre->x, centre->y - *x);
        SDL_RenderDrawLine(sdlRenderer, centre->x - *x, centre->y + *y, centre->x, centre->y + *y);
        SDL_RenderDrawLine(sdlRenderer, centre->x - *y, centre->y + *x, centre->x, centre->y + *x);
        SDL_RenderDrawLine(sdlRenderer, centre->x + *x, centre->y - *y, centre->x, centre->y - *y);
        SDL_RenderDrawLine(sdlRenderer, centre->x + *y, centre->y - *x, centre->x, centre->y - *x);
        SDL_RenderDrawLine(sdlRenderer, centre->x + *y, centre->y + *x, centre->x, centre->y + *x);
        SDL_RenderDrawLine(sdlRenderer, centre->x + *x, centre->y + *y, centre->x, centre->y + *y);
        if (*error <= 0)
        {
            ++*y;
            *error += *ty;
            *ty += 2;
        }
        if (*error > 0)
        {
            --*x;
            *tx += 2;
            *error += (*tx - *diameter);
        }
    }

    delete diameter;
    delete x; delete y; delete tx; delete ty; delete error;
}

void Renderer::DrawCircle(Containers::Vector2 *centre, int radius) {
    int *diameter = new int(); *diameter = (radius * 2);
    int *x = new int(); *x = (radius - 1);
    int *y = new int(); *y = 0;
    int *tx = new int(); *tx = 1;
    int *ty = new int(); *ty = 1;
    int *error = new int(); *error = (*tx - *diameter);

    while (*x >= *y)
    {
        SDL_RenderDrawPoint(sdlRenderer, centre->x + *x, centre->y - *y);
        SDL_RenderDrawPoint(sdlRenderer, centre->x + *x, centre->y + *y);
        SDL_RenderDrawPoint(sdlRenderer, centre->x - *x, centre->y - *y);
        SDL_RenderDrawPoint(sdlRenderer, centre->x - *x, centre->y + *y);
        SDL_RenderDrawPoint(sdlRenderer, centre->x + *y, centre->y - *x);
        SDL_RenderDrawPoint(sdlRenderer, centre->x + *y, centre->y + *x);
        SDL_RenderDrawPoint(sdlRenderer, centre->x - *y, centre->y - *x);
        SDL_RenderDrawPoint(sdlRenderer, centre->x - *y, centre->y + *x);

        if (*error <= 0)
        {
            ++*y;
            *error += *ty;
            *ty += 2;
        }
        if (*error > 0)
        {
            --*x;
            *tx += 2;
            *error += (*tx - *diameter);
        }
    }
    delete diameter;
    delete x; delete y; delete tx; delete ty; delete error;
}

void Renderer::ClearRenderer() {
    SDL_RenderClear(sdlRenderer);
}

SDL_Renderer *Renderer::GetSDLRenderer() {
    return sdlRenderer;
}