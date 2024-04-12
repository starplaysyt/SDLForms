#ifndef SDLFORMS_FORM_H
#define SDLFORMS_FORM_H

#pragma once
#include <iostream>
#include <SDL.h>
#include "../Graphics/Renderer.h"
#include "IDrawable.h"
#include "Controls.h"
#include "../Graphics/ColorManager.h"
#include <thread>


namespace Forms {
    class Form {

    private:
        SDL_Renderer *sdlRenderer;
        SDL_Window *window;

    public:
        void StartWindowLoop();

    protected:

        Containers::Vector2 *Location;
        Containers::Vector2 *Size;
        std::string title;

        Graphics::Color *BackgroundColor;

        Graphics::Renderer *renderer;
        Graphics::TextRenderer *textRenderer;

        std::vector<IDrawable*> *Controls;

        Form(std::string title, Containers::Vector2 *position, Containers::Vector2 *size);

        ~Form();

        virtual void Close();
    };

    //TODO: Make getter and setter for Location and Size

    //DONE: Move that shit to more likely place
}

#endif