#include "TransformationRegistry.h"

Transformation* TransformationRegistry::create(std::string key) {
    auto it = prototypes.find(key);
    if (it != prototypes.end() && it->second != nullptr) {
        return it->second->clone();
    }
    return nullptr;
}


void TransformationRegistry::registerStep(std::string key, Transformation* prototype) {
    auto it = prototypes.find(key);
    if (it != prototypes.end()) {
        delete it->second;
    }
    prototypes[key] = prototype;
}

TransformationRegistry::~TransformationRegistry() {
    for (auto const& pair : prototypes) {
        delete pair.second;
    }
    prototypes.clear();
}