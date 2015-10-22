#include "Direction.h"
#include "AnimationState.h"
#include "Hero.h"

Hero::Hero()
{
    xp = 0;
    inBattle = false;
}

void Hero::update()
{
    int previous_state = getAnimationState();
    float speed;

<<<<<<< HEAD
    if (!inBattle)
    {
        if (event_receiver->GetKeyboardState(irr::KEY_LSHIFT))
        {
            setStealth(true);
            speed = 1.f;
        }
        else
        {
            setStealth(false);
            speed = 2.f;
        }

        if (event_receiver->GetKeyboardState(irr::KEY_KEY_W))
        {
            if (event_receiver->GetKeyboardState(irr::KEY_KEY_D))
            {
                move(UPPER_RIGHT, speed);
            }

            else if (event_receiver->GetKeyboardState(irr::KEY_KEY_A))
            {
                move(UPPER_LEFT, speed);
            }

            else
            {
                move(UP, speed);
            }
        }

        else if (event_receiver->GetKeyboardState(irr::KEY_KEY_S))
        {
            if (event_receiver->GetKeyboardState(irr::KEY_KEY_D))
            {
                move(DOWN_RIGHT, speed);
            }

            else if (event_receiver->GetKeyboardState(irr::KEY_KEY_A))
            {
                move(DOWN_LEFT, speed);
            }

            else
            {
                move(DOWN, speed);
            }
        }

        else if (event_receiver->GetKeyboardState(irr::KEY_KEY_D))
        {
            if (event_receiver->GetKeyboardState(irr::KEY_KEY_W))
            {
                move(UPPER_RIGHT, speed);
            }

            else if (event_receiver->GetKeyboardState(irr::KEY_KEY_S))
            {
                move(DOWN_RIGHT, speed);
            }

            else
            {
                move(RIGHT, speed);
            }
        }

        else if (event_receiver->GetKeyboardState(irr::KEY_KEY_A))
        {
            if (event_receiver->GetKeyboardState(irr::KEY_KEY_W))
            {
                move(UPPER_LEFT, speed);
            }

            else if (event_receiver->GetKeyboardState(irr::KEY_KEY_S))
            {
                move(DOWN_LEFT, speed);
            }

            else
            {
                move(LEFT, speed);
            }
        }

        else
        {
            move(NONE, speed);
        }
    }
    else 
    {
        move(NONE, 0.f);        
    }

    int state = getAnimationState();

    if (state != previous_state)
    {
        switch (state)
        {
            case WALKING:   getNode()->setFrameLoop(0, 13);
                            break;

            case IDLE:      getNode()->setFrameLoop(205, 249);
                            break;

            case STEALTH:   getNode()->setFrameLoop(14, 29);
                            break;

            default:        break;
        }
    }
 
}

void levelUp()
{
}
