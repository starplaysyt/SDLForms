//
// Created by Vincent on 12.04.24.
//

#ifndef SDLFORMS_MOUSEMOVEEVENTARGS_H
#define SDLFORMS_MOUSEMOVEEVENTARGS_H

#pragma once
#include "../Containers/Vector2.h"

namespace Events {
    class MouseMoveEventArgs {
    public:
        Containers::Vector2 *MousePosition;

        MouseMoveEventArgs()
        {
            MousePosition = new Containers::Vector2();
        }

        MouseMoveEventArgs(Containers::Vector2 MousePosition){
            *this->MousePosition = MousePosition;
        }

        ~MouseMoveEventArgs()
        {
            delete MousePosition;
        }
    };
}

#endif //SDLFORMS_MOUSEMOVEEVENTARGS_H
