#include "CheckpointManager.h"

CheckpointManager::CheckpointManager(){}

void CheckpointManager::save(RunCheckpoint* cp){
        history.push_back(cp);
}

RunCheckpoint* CheckpointManager::undo(){
    if(history.empty()) {
        return nullptr;
    } 

    RunCheckpoint* prev = history.back();
    history.pop_back();
    return prev;
}

CheckpointManager::~CheckpointManager(){
    for(RunCheckpoint* h : history)
    {
        delete h;
    }
    history.clear();
}