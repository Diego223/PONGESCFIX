// PaddleAIAgent.h
#ifndef PADDLE_AI_AGENT_H
#define PADDLE_AI_AGENT_H

#include "ScriptingManager.h"

class PaddleAIAgent {
public:
    static void movePaddleTowardsBall(TransformComponent& paddleTransform, const TransformComponent& ballTransform, double dT, int screen_height, sol::state& lua) {
        int paddleCenterY = paddleTransform.position.y + (paddleTransform.height / 2);
        int ballCenterY = ballTransform.position.y + (ballTransform.height / 2);

        if (paddleCenterY < ballCenterY) {
            paddleTransform.position.y += paddleTransform.speed * dT;
        } else if (paddleCenterY > ballCenterY) {
            paddleTransform.position.y -= paddleTransform.speed * dT;
        }

        if (paddleTransform.position.y < 0) {
            paddleTransform.position.y = 0;
        } else if (paddleTransform.position.y + paddleTransform.height > screen_height) {
            paddleTransform.position.y = screen_height - paddleTransform.height;
        }

        sol::protected_function_result result = lua["movePaddle"](paddleTransform.position.y, ballTransform.position.y, dT, screen_height);
        if (!result.valid()) {
            sol::error err = result;
            // Handle Lua script execution error
        } else {
            paddleTransform.position.y = result;
        }
    }
};

#endif