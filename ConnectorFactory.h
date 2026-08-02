#ifndef CONNECTORFACTORY_H
#define CONNECTORFACTOR_H

#include "Connector.h"

class ConnectorFactory{
    public:
    ConnectorFactory();
    virtual Connector* createConnector() = 0;
    virtual ~ConnectorFactory();
};

#endif