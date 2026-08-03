#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transformation{ //abstract
    protected: 
    std::string name;

    public:
   Transformation(std::string name);

   std::string getName();

   ~Transformation(); //deconstructor

   
   virtual Transformation* clone() = 0;
   virtual vector<std::string> apply( vector<std::string>) = 0;
};


class DeduplicateStep: public Transformation{

    public:
   

    Transformation* clone();

    vector<std::string> apply( vector<std::string>);
};



class AggregateByRegionStep: public Transformation{

    public:
    

    Transformation* clone();

    vector<std::string> apply( vector<std::string>);
};

#endif