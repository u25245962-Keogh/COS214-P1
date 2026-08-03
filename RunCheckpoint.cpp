#include "RunCheckpoint.h"

RunCheckpoint::RunCheckpoint(int s, vector<string> r):stage(s), records(r){}

RunCheckpoint::~RunCheckpoint(){}

int RunCheckpoint::getStage(){return this->stage;}
vector<string> RunCheckpoint::getRecords(){return this->records;}