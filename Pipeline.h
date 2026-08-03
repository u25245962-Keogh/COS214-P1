#ifndef PIPELINE_H
#define PIPELINE_H

#include <iostream>
#include <string>
#include <vector>
#include "Transformation.h"
#include "ConnectorFactory.h"
#include "RunCheckpoint.h"



class Pipeline{
protected:
ConnectorFactory* factory;
std::vector<Transformation*> steps;
int stage;
std::vector<std::string> records;

void connect();
virtual void extract() =0;
void transform();
virtual void load() =0;

public:
Pipeline(ConnectorFactory*);
~Pipeline();

void run();
void addStep(Transformation*);


RunCheckpoint* createCheckpoint();
void restore(RunCheckpoint*);



};

class BatchPipeline: public Pipeline{
    public:
    BatchPipeline(ConnectorFactory* factory) : Pipeline(factory) {}
    protected:
    void extract();
    void load();

};

class StreamingPipeline: public Pipeline{
    public:
    StreamingPipeline(ConnectorFactory* factory) : Pipeline(factory) {}
    protected:
    void extract();
    void load();

};

#endif