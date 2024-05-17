#ifndef SDLFORMS_FORM_H
#define SDLFORMS_FORM_H

#pragma once
#include <iostream>
#include <SDL.h>
#include "../Graphics/Renderer.h"
#include "../Graphics/TextRenderer.h"
#include "Interfaces/IControl.h"
#include "Controls.h"
#include "Interfaces/IOwner.h"
#include "../Graphics/ColorManager.h"
#include <vector>
#include <thread>


namespace Forms{
    class Form : IOwner {

    private:
        SDL_Renderer *sdlRenderer;
        SDL_Window *window;
        void InternalInitializeComponent();

    public:
        void AddControl(IControl* control);

        void StartWindowLoop() final;

        //#region StateVarsRegion

        bool *DoClosing;


        //#endregion

        Containers::Vector2 *Location;
        Containers::Vector2 *Size;
        std::string* Title;

        Graphics::Color *BackgroundColor;

        Graphics::Renderer *renderer;
        Graphics::TextRenderer *textRenderer;

        std::vector<IControl*> *Controls;

        //#region ControlStateVarsRegion

        IControl *selectedObject;

        //#endregion

        Form();

        ~Form();

        virtual void EventCheckup(Uint32 type, SDL_Event *args);

        virtual void Close();
    };

    //TODO: Make getter and setter for Location and Size

    //DONE: Move that shit to more likely place
}

#endif