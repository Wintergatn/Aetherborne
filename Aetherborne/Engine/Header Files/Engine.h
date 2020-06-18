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
#include "FreeListAllocator.h"

namespace Aetherborne {

    class RenderGraph;

    class Engine {

    public:
        Engine();
        ~Engine();

        Graphics& getGraphics() { return *m_graphics; }
        SystemGroup& getUpdateGroup() { return *m_updateGroup; }
        RenderGraph& renderGraph() { return *m_renderGraph; }

        void run();

        void addWindow(Window& window);
        void setRenderGraph(RenderGraph& renderGraph);

    private:
        Window* m_window;
        RenderGraph* m_renderGraph;

        std::unique_ptr<SystemGroup> m_updateGroup;
        std::unique_ptr<Clock> m_updateClock;
        std::unique_ptr<Graphics> m_graphics;
    };
}


