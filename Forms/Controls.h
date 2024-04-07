//
// Created by Vincent on 20.03.24.
//
#pragma once
#include "IDrawable.h"
#include "../Containers/BorderStyle.h"
#include "../Containers/Vector2.h"
#include "../Graphics/Renderer.h"
#include "../Graphics/ColorManager.h"
#include "../Containers/Vector1.h"
#include "../Graphics/TextRenderer.h"

#ifndef SDLFORMS_CONTROLS_H
#define SDLFORMS_CONTROLS_H

namespace Forms {
    class Rectangle : public IDrawable {
    public:
        void Draw() override;

    public:
        Containers::Vector2 *Location;
        Containers::Vector2 *Size;
        BorderStyle::BorderStyleEnum BorderStyle;
        Graphics::Color *BackgroundColor;
        Graphics::Color *ForegroundColor;

        Rectangle(Graphics::Renderer *renderer);

        ~Rectangle();

    private:
        Graphics::Renderer *assignedRenderer;
    };

    class Circle : public IDrawable {
    public:
        void Draw() override;

    public:
        Containers::Vector2 *Location;
        int *Radius;
        BorderStyle::BorderStyleEnum BorderStyle;
        Graphics::Color *BackgroundColor;
        Graphics::Color *ForegroundColor;

        Circle(Graphics::Renderer *renderer);

        ~Circle();

    private:
        Graphics::Renderer *assignedRenderer;
    };

    class Label : public IDrawable {
    public:
        void Draw() override;

    public:
        Containers::Vector2 *Location;
        Containers::Vector2 *Size;
        bool *AutoSize;
        BorderStyle::BorderStyleEnum BorderStyle;
        Graphics::Color *BackgroundColor;
        Graphics::Color *ForegroundColor;
        std::string *Text;

        Label(Graphics::Renderer *renderer, Graphics::TextRenderer *textRenderer);

        ~Label();

    private:
        Graphics::Renderer *assignedRenderer;
        Graphics::TextRenderer *assignedTextRenderer;
    };


}

#endif //SDLFORMS_CONTROLS_H
