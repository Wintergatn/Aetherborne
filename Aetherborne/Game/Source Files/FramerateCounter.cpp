#include "../Header Files/FramerateCounter.h"
#include <sstream>
#include <iomanip>

FramerateCounter::FramerateCounter(Aetherborne::Window& window, std::string titlePrefix) {
    m_window = &window;
    m_titlePrefix = titlePrefix;
    m_frameCount = 0;
    m_timer = 0;
}

void FramerateCounter::update(Aetherborne::Clock& clock) {
    m_timer += clock.delta();
    m_frameCount++;

    if (m_timer > 0.25f) {
        float frameRate = m_frameCount / m_timer;
        std::stringstream stream;
        stream << m_titlePrefix << " (" << std::fixed << std::setprecision(0) << frameRate << " fps)";
        m_window->setTitle(stream.str());

        m_timer = 0;
        m_frameCount = 0;
    }
}