#ifndef SDLFORMS_RENDERER_H
#define SDLFORMS_RENDERER_H

#pragma once
#include <SDL.h>
#include "../Containers/Vector2.h"
#include "../Graphics/ColorManager.h"

namespace Graphics
{
    class Renderer
    {
        public:
            void DrawLine(Containers::Vector2* pos1, Containers::Vector2* pos2);

            void DrawRect(Containers::Vector2* position, Containers::Vector2* size);

            void FillRect(Containers::Vector2* position, Containers::Vector2* size);

            void FillCircle(Containers::Vector2* centre, int radius);

            void DrawCircle(Containers::Vector2* centre, int radius);

            void CompleteRender(); //at the end of render

            void ClearRenderer();

            Renderer(SDL_Renderer *sdlRenderer, SDL_Window *window);


            void SetColor(Graphics::Color* color);

            void SetColor(Graphics::ColorEnum ecolor);

            SDL_Renderer* GetSDLRenderer();

        private:
            bool isFontOpened;
            SDL_Window *parentWindow;
            SDL_Renderer *sdlRenderer;
    };

}

#endif