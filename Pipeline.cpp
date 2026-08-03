#include "Pipeline.h"
#include "Connector.h"
#include <iostream>
#include <string>
#include <vector>

void Pipeline::connect(){
    if (factory != nullptr) {
        Connector* connector = factory->createConnector();
        if (connector != nullptr) {
            std::cout << "Connecting to " << connector->getSource() << std::endl;
            delete connector; 
        }
    }
    stage = 1;


}

void Pipeline::transform(){
    for (Transformation* step : steps) {
        if (step != nullptr) {
            records = step->apply(records);
        }
    }
    stage = 3;
    
}





Pipeline::Pipeline(ConnectorFactory* connectorFactory){
    factory = connectorFactory;
    stage =0;
    records.clear();    
}
Pipeline::~Pipeline(){
    delete factory;
    factory = nullptr;

    for (Transformation* step : steps) {
        delete step;
    }
    steps.clear();
    
}



void Pipeline::run(){
    connect();
    extract();
    transform();
    load();
    
}
void Pipeline::addStep(Transformation* t){
    steps.push_back(t);
    
}
RunCheckpoint* Pipeline::createCheckpoint(){
    return new RunCheckpoint(stage, records);
}
void Pipeline::restore(RunCheckpoint* cp){
    if (cp != nullptr) {
        stage = cp->getStage();
        records = cp->getRecords();
    }
    
}


void BatchPipeline::extract() {
    if (factory != nullptr) {
        Connector* connector = factory->createConnector();
        if (connector != nullptr) {
            records = connector->extract();
            delete connector;
        }
    }
    std::cout << "Batch extract: " << records.size() << " records" << std::endl;
    stage = 2;
}

void BatchPipeline::load() {
    std::cout << "Batch load: " << records.size() << " records written" << std::endl;
    stage = 4;
}

void StreamingPipeline::extract(){
    if (factory != nullptr) {
        Connector* connector = factory->createConnector();
        if (connector != nullptr) {
            records = connector->extract();
            delete connector;
        }
    }
    std::cout << "Streaming extract: " << records.size() << " records" << std::endl;
    stage = 2;
}

void StreamingPipeline::load(){
    std::cout << "Streaming load: " << records.size() << " records streamed" << std::endl;
    stage = 4;
}

