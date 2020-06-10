#pragma once
#include "Buffer.h"
#include "Camera.h"
#include "Clock.h"
#include "Mesh.h"
#include "Graphics.h"
#include "Image.h"
#include "Input.h"
#include "MemoryManager.h"
#include "../RenderGraph/RenderGraph.h"
#include "System.h"
#include "Window.h"

namespace Aetherborne {

	class Engine
	{
    public:
        Engine();
        ~Engine();

        Graphics& getGraphics() { return *m_graphics; }
        SystemGroup& getUpdateGroup() { return *m_updateGroup; }

        void run();

        void addWindow(Window& window);

    private:
        Window* m_window;
        std::unique_ptr<SystemGroup> m_updateGroup;
        std::unique_ptr<Clock> m_updateClock;
        std::unique_ptr<Graphics> m_graphics;

    };
}


