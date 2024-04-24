//
// Created by Vincent on 20.03.24.
//

#ifndef SDLFORMS_ICONTROL_H
#define SDLFORMS_ICONTROL_H

#pragma once
#include "../Events/MouseEventType.h"
#include "../Events/MouseEventArgs.h"

namespace Forms {
    class IControl {
    public:
        virtual void Draw() {};
        virtual void EventCheckup(Events::MouseEventType::MouseEventTypeEnum eventType, Events::MouseEventArgs* args) {};
        virtual bool IsMouseInside(Containers::Vector2 position);
    };
}
#endif //SDLFORMS_ICONTROL_H
