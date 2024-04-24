//
// Created by Vincent on 24.04.24.
//

#ifndef SDLFORMS_MOUSEEVENTARGS_H
#define SDLFORMS_MOUSEEVENTARGS_H

#pragma once
#include "../Containers/Vector2.h"

namespace Events {
    class MouseEventArgs {
    public:
        Containers::Vector2 *mousePosition;

        MouseEventArgs(){
            mousePosition = new Containers::Vector2();
        }
    };
}


#endif //SDLFORMS_MOUSEEVENTARGS_H
