#pragma once
#include <../../Engine/Header Files/Engine.h>
#include <../../Engine/Header Files/Math.h>
#include <optional>
#include "../Header Files/World.h"
//#include "SelectionBox.h"

class World;
class BlockManager;

class FreeCam : public Aetherborne::System {
public:
    FreeCam(Aetherborne::Camera& camera, Aetherborne::Input& input, World& world, BlockManager& blockManager/*, SelectionBox& selectionBox*/);

    glm::vec3 position() { return m_position; }
    void setPosition(glm::vec3 pos);

    void update(Aetherborne::Clock& clock);

private:
    Aetherborne::Camera* m_camera;
    Aetherborne::Input* m_input;
    World* m_world;
    BlockManager* m_blockManager;
    //SelectionBox* m_selectionBox;

    bool m_locked = false;
    glm::vec2 m_look;
    glm::vec3 m_position;
    glm::quat m_rotation;
    int32_t m_placeType;

    void handleKeyInput(Aetherborne::Key key, Aetherborne::KeyState);
};