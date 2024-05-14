//
// Created by Vincent on 20.03.24.
//

#ifndef SDLFORMS_ICONTROL_H
#define SDLFORMS_ICONTROL_H

#pragma once

#include "../Events/MouseEventType.h"
#include "../Events/MouseEventArgs.h"
#include "IOwner.h"
#include "SDL.h"

namespace Forms {

    class IControl {

    public:
        virtual void Draw() {}
        virtual void EventCheckup(Uint32 type, SDL_Event *args) {}
        virtual bool IsMouseInside(Containers::Vector2 *position) { return false; }

        IOwner *owner;

    };
}
#endif //SDLFORMS_ICONTROL_H
