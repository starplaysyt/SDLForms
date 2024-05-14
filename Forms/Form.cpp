#include "Form.h"

using namespace Forms;

void Form::StartWindowLoop()  { //starting loop sector
    std::cout << "Form.cpp >> Rendering Loop Started." << std::endl;
    auto *e = new SDL_Event();
    std::chrono::system_clock::time_point startPoint = std::chrono::system_clock::now(); //IS CODE IN WHILE A JOKE FOR YOU?
    std::chrono::system_clock::time_point endPoint = std::chrono::system_clock::now(); //IS CODE IN WHILE A JOKE FOR YOU?
    int PTi = 0;
    std::chrono::system_clock::time_point FPSTracerStart = std::chrono::system_clock::now();
    size_t midCD = 1;

    while (!*doClosing) {
        PTi++;
        startPoint =  std::chrono::system_clock::now();
        while (SDL_PollEvent(e) != 0) {
            auto *mousePosition = new Containers::Vector2();
            SDL_GetMouseState(mousePosition->x, mousePosition->y);
            bool isFrontMostObjectFound = false;
            if(e->type == SDL_QUIT) *doClosing = true;
            EventCheckup(e->type, e);
            //IM HIDING!
            for (int i = Controls->size()-1; i >= 0; i--) { //DO NOT FUCKN CHANGE INT TO LONG! CAUSE STUPID ERROR, DEVS WAS DRUNK
                if (Controls->at(i)->IsMouseInside(mousePosition) && isFrontMostObjectFound == false) {
                    isFrontMostObjectFound = true;
                    Controls->at(i)->EventCheckup(e->type, e);
                }
                else {
                    Controls->at(i)->EventCheckup(0, e);
                }
            }
            //HERE I AM!
            renderer->SetColor(BackgroundColor);
            renderer->ClearRenderer();
            for (auto & Control : *Controls)
            {
                Control->Draw();
            }
            renderer->CompleteRender();
        }

        endPoint = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> work_time = endPoint - startPoint;

        //TODO:Make changeable target FPS(hz)

        if (work_time.count() < 17.0) //5hz(FPS) = 200ms delay sAs 60hz = 17 ms delay
        {
            std::chrono::duration<double, std::milli> delta_ms(17.0 - work_time.count());
            auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
            std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
            midCD = (midCD + delta_ms_duration.count())/2;
        }
        std::chrono::duration<double, std::milli> FPSDur(endPoint - FPSTracerStart);
        if (FPSDur.count() >= 1000)
        {
            std::cout << "FPS: " << PTi << "Delta msDur: " << midCD << std::endl;
            FPSTracerStart = std::chrono::system_clock::now();
            PTi = 0;
        }

    }
    delete e;
    std::cout << "Form.cpp >> Rendering Loop Stopped. Closeup action issued?" << std::endl;
}

Form::Form(const std::string& title, Containers::Vector2 *position, Containers::Vector2 *size) { //parametrized constructor
    TTF_Init();
    this->Location = position;
    this->Size = size;
    this->title = title;

    doClosing = new bool();
    *doClosing = false;

    window = SDL_CreateWindow(title.c_str(), *position->x, *position->y, *size->x, *size->y, 0);
    sdlRenderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawBlendMode(sdlRenderer, SDL_BLENDMODE_BLEND);
    renderer = new Graphics::Renderer(sdlRenderer, window);
    textRenderer = new Graphics::TextRenderer(renderer, window);
    textRenderer->OpenFontFile("font.ttf", 24);

    Controls = new std::vector<IControl*>();

    BackgroundColor = new Graphics::Color();
    BackgroundColor->SetColor(Graphics::Black);

    std::cout << "Form.cpp >>> Parent Form Initialization completed." << std::endl;
}

void Form::AddControl(IControl *control) {
    control->owner = this;
    Controls->push_back(control);
}

void Form::EventCheckup(Uint32 type, SDL_Event *args) {

}

void Form::Close() {
    delete this;
}

Form::~Form() {
    delete Location;
    delete Size;
    textRenderer->CloseFontFile();
    TTF_Quit();
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Form.cpp >>> Bye, world! Being good to know ya. Form extinction completed.";
}

