#pragma once
#include <../../Engine/Header Files/System.h>
#include <../../Engine/Header Files/Window.h>
#include <../../Engine/Header Files/Clock.h>

class FramerateCounter : public Aetherborne::System {

public:
    FramerateCounter(Aetherborne::Window& window, std::string titlePrefix);

    void update(Aetherborne::Clock& clock);

private:
    Aetherborne::Window* m_window;
    std::string m_titlePrefix;
    size_t m_frameCount;
    float m_timer;
};