#include <iostream>
#include <vector>

#include "cmd.h"

int main()
{
    GameActor *actor = new GameActor;
    std::vector<Command*> command_queue;

    JumpCommand *c1 = new JumpCommand;
    command_queue.push_back(c1);
    JumpCommand *c2 = new JumpCommand;
    command_queue.push_back(c2);
    JumpCommand *c3 = new JumpCommand;
    command_queue.push_back(c3);
    JumpCommand *c4 = new JumpCommand;
    command_queue.push_back(c4);

    for (int i = 0; i < command_queue.size(); i++)
    {
        command_queue[i]->execute(*actor);
    }
    
    return 0;
}