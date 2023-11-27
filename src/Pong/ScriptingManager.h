// ScriptingManager.h
#ifndef SCRIPTING_MANAGER_H
#define SCRIPTING_MANAGER_H

#include <sol/sol.hpp>
#include "Components.h"

class ScriptingManager {
public:
    static void initScripting(sol::state& lua);
};

#endif // SCRIPTING_MANAGER_H