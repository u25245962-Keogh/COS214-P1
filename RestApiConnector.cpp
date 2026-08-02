#include "RestApiConnector.h"

RestApiConnector::RestApiConnector():Connector("restapi")
{

}

vector<string> RestApiConnector::extract(){
    vector<string> res = {"API:44","API:45","API:45"};
    return res;
}