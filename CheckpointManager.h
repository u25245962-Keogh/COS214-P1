#ifndef CHECKPOINTMANAGER_H
#define CHECKPOINTMANAGER_H

#include "RunCheckpoint.h"

class CheckpointManager{
    private:
    vector<RunCheckpoint*> history;

    public:
    CheckpointManager();
    ~CheckpointManager();
    void save(RunCheckpoint*);
    RunCheckpoint* undo();
};

#endif