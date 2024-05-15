//
// Created by Vincent on 20.03.24.
//

#ifndef SDLFORMS_ICONTROL_H
#define SDLFORMS_ICONTROL_H

#pragma once

#include "IOwner.h"
#include "SDL.h"
#include "../../Containers/Vector2.h"

namespace Forms {

    class IControl { //it's unnessesary to initialize something here. Check docs and structure

    public:
        virtual void Draw() {}
        virtual void EventCheckup(Uint32 type, SDL_Event *args) {}
        virtual bool IsMouseInside(Containers::Vector2 *position) { return false; }

        IOwner *owner;

    };
}
#endif //SDLFORMS_ICONTROL_H
