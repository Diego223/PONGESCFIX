// PaddleAIAgent.h
#ifndef PADDLE_AI_AGENT_H
#define PADDLE_AI_AGENT_H

#include "Components.h"

class PaddleAIAgent {
public:
    static void movePaddleTowardsBall(TransformComponent& paddleTransform, const TransformComponent& ballTransform, double dT, int screen_height) {
        // Adjust the paddle's position based on the ball's position
        int paddleCenterY = paddleTransform.position.y + (paddleTransform.height / 2);
        int ballCenterY = ballTransform.position.y + (ballTransform.height / 2);

        // Simple tracking mechanism: move the paddle towards the ball's Y position
        if (paddleCenterY < ballCenterY) {
            // Ball is below paddle, move paddle down
            paddleTransform.position.y += paddleTransform.speed * dT;
        } else if (paddleCenterY > ballCenterY) {
            // Ball is above paddle, move paddle up
            paddleTransform.position.y -= paddleTransform.speed * dT;
        }

        // Ensure paddle doesn't go out of bounds
        if (paddleTransform.position.y < 0) {
            paddleTransform.position.y = 0;
        } else if (paddleTransform.position.y + paddleTransform.height > screen_height) {
            paddleTransform.position.y = screen_height - paddleTransform.height;
        }
    }
};

#endif // PADDLE_AI_AGENT_H

