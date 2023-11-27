// ScriptingManager.cpp
#include "ScriptingManager.h"

void ScriptingManager::initScripting(sol::state& lua) {
    lua.new_simple_usertype<TransformComponent>("TransformComponent",
        "position", &TransformComponent::position,
        "width", &TransformComponent::width,
        "height", &TransformComponent::height,
        "speed", &TransformComponent::speed
    );

    lua.script_file("path_to_script_file.lua");
}