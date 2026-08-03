#ifndef RUNCHECKPOINT_H
#define RUNCHECKPOINT_H

#include <string>
#include <vector>

using namespace std;

class RunCheckpoint{
    private:
    int stage;
    vector<string> records;  

    public:
    RunCheckpoint(int, vector<string>);
    ~RunCheckpoint();
    int getStage();
    vector<string> getRecords();
};

#endif