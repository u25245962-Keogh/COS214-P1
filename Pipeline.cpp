#include "Pipeline.h"
#include <iostream>
#include <string>
#include <vector>

void Pipeline::connect(){

}
void Pipeline::extract(){
    
}
void Pipeline::transform(){
    
}
void Pipeline::load(){
    
}


Pipeline::Pipeline(ConnectorFactory*){
    
}
void Pipeline::run(){
    
}
void Pipeline::addStep(Transformation*){
    
}
RunCheckpoint* Pipeline::createCheckpoint(){
    
}
void Pipeline::restore(RunCheckpoint*){
    
}
Pipeline::~Pipeline(){
    
}

void BatchPipeline::extract(){
    
}

void BatchPipeline::load(){
    
}

void StreamingPipeline::extract(){
    
}

void StreamingPipeline::load(){
    
}

