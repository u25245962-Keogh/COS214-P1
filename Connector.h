#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <vector>
#include <string>

using namespace std;

class Connector{
    protected:
    string source;

    public:
    Connector(string source);
    virtual ~Connector();
    virtual vector<string> extract() = 0;
    string getSource();
};

#endif