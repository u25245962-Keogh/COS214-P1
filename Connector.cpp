#include "Connector.h"

    Connector::Connector(string s){
        source = s;
    }

    string Connector::getSource()
    {
        return source;
    }

    Connector::~Connector(){}
    