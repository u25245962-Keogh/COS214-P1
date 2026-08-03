#ifndef PIPELINE_H
#define PIPELINE_H

#include <iostream>
#include <string>
#include <vector>
#include "Transformation.h"
#include "ConnectorFactory.h"



class Pipeline{
protected:
ConnectorFactory* factory;
vector<Transformation*> steps;
int stage;
vector<std::string> records;

void connect();
void extract();
void transform();
void load();

public:
Pipeline(ConnectorFactory*);
void run();
void addStep(Transformation*);
RunCheckpoint* createCheckpoint();
void restore(RunCheckpoint*);
~Pipeline();


};

class BatchPipeline: public Pipeline{
    protected:
    void extract();
    void load();

};

class StreamingPipeline: public Pipeline{
    protected:
    void extract();
    void load();

};

#endif