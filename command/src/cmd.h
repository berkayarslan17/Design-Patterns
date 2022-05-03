#ifndef COMMAND_H
#define COMMAND_H

class GameActor
{
public:
    GameActor();
    ~GameActor();
    void jump();
};

class Command
{
public:
    virtual ~Command() {}
    virtual void execute(GameActor &actor) = 0;
};

class JumpCommand : public Command
{
public:
    virtual void execute(GameActor &actor)
    {
        actor.jump();
    }
};

#endif