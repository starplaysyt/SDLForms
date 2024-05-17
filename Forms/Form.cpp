#include "Form.h"

using namespace Forms;

void Form::InternalInitializeComponent() {
    SDL_SetWindowPosition(window, *Location->x, *Location->y);
    SDL_SetWindowSize(window, *Size->x, *Size->y);
    SDL_SetWindowTitle(window, Title->c_str());
}

Form::Form() { //parametrized constructor
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    Location = new Containers::Vector2(100,100);
    Size = new Containers::Vector2(400,300);
    Title = new std::string();
    *Title = "SDLForms Application Window";

    DoClosing = new bool();
    *DoClosing = false;

    window = SDL_CreateWindow(Title->c_str(), *Location->x, *Location->y, *Size->x, *Size->y, 0);
    sdlRenderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawBlendMode(sdlRenderer, SDL_BLENDMODE_BLEND);
    renderer = new Graphics::Renderer(sdlRenderer, window);
    textRenderer = new Graphics::TextRenderer(renderer, window);
    textRenderer->OpenFontFile("font.ttf", 12);

    Controls = new std::vector<IControl*>();

    BackgroundColor = new Graphics::Color();
    BackgroundColor->SetColor(Graphics::Black);

    std::cout << "Form.cpp >>> Parent Form Initialization completed." << std::endl;
}

void Form::StartWindowLoop()  { //starting loop sector
    std::cout << "Form.cpp >> Rendering Loop Started." << std::endl;

    InternalInitializeComponent();
    std::cout << "Form.cpp >> Form internal initialization completed." << std::endl;
    auto *e = new SDL_Event();
    std::chrono::system_clock::time_point startPoint = std::chrono::system_clock::now(); //IS CODE IN WHILE A JOKE FOR YOU?
    std::chrono::system_clock::time_point endPoint = std::chrono::system_clock::now(); //IS CODE IN WHILE A JOKE FOR YOU?
    int PTi = 0;
    std::chrono::system_clock::time_point FPSTracerStart = std::chrono::system_clock::now();
    size_t midCD = 1;

    while (!*DoClosing) {
        PTi++;
        startPoint =  std::chrono::system_clock::now();

        while (SDL_PollEvent(e) != 0) {
            auto *mousePosition = new Containers::Vector2();
            SDL_GetMouseState(mousePosition->x, mousePosition->y);
            bool isFrontMostObjectFound = false;
            if(e->type == SDL_QUIT) *DoClosing = true;
            EventCheckup(e->type, e);
            //IM HIDING!
            for (int i = Controls->size()-1; i >= 0; i--) { //DO NOT FUCKN' CHANGE INT TO unsinged long long OR DERIVATIVES! CAUSE STUPID ERROR, DEVS WAS DRUNK
                if (Controls->at(i)->IsMouseInside(mousePosition) && isFrontMostObjectFound == false) {
                    isFrontMostObjectFound = true;
                    Controls->at(i)->EventCheckup(e->type, e); //I know, we can simply give this function SDL_Event var only, but it's way too smart, so we use it as it is
                }
                else {
                    Controls->at(i)->EventCheckup(0, e); //Oh, i forgot bout that, we use two vars to send info 'bout zero-event, or other event stuff. As Todd Howard said: "It's just works"
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

        //WARNING! SMART SHIT FORWARD! BEWARE OF EMOTIONAL DAMAGE! Ok, it's not very funny. We just use hypersonic trans-singulary alpha-beta-combiner to control apps' framerate
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

