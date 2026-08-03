#ifndef TRANSFORMATIONREGISTRY_H
#define TRANSFORMATIONREGISTRY_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Transformation.h"

class TransformationRegistry{

private:
    map<std::string, Transformation*> prototypes;
public:
    void registerStep(std::string, Transformation*);
    Transformation* create(std::string);
    ~TransformationRegistry();

}

#endif