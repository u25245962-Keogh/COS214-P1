#include "PostgresConnector.h"

PostgresConnector::PostgresConnector():Connector("postgres")
{

}

vector<string> PostgresConnector::extract(){
    vector<string> res = {"PG:001","PG:002","PG:002","PG:003"};
    return res;
}