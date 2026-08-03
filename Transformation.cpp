#include "Transformation.h"
#include <iostream>
#include <string>
#include <vector>



Transformation::Transformation(std::string name){
 this->name = name;
};

Transformation::~Transformation(){
   
   };
   


std::string Transformation::getName(){
    return name;
};



 Transformation* DeduplicateStep::clone(){ //           ?????
    return new DeduplicateStep(*this);
}

Transformation* AggregateByRegionStep::clone(){ //             ????
    return new AggregateByRegionStep(*this);
}

  vector<std::string> DeduplicateStep::apply(vector<std::string> vec){

    vector<std::string> temp = vec;
    for(int i = 0; i < vec.size(); i++){
        temp[i] = vec[i];
    } //copy over into temp


    for(int i = 0; i < vec.size(); i++){
      //  std::cout<< vec[i]<<std::endl;

        if( i != 0 && temp[i] == temp[i-1]){//not first iteration, if current is equal to element before it
            temp.erase(temp.begin() + i-1); //then remove the first of the duplicates
        }
    }

    return temp; //return new edited vector (temp)
 }


   vector<std::string> AggregateByRegionStep::apply( vector<std::string> vec){

    int count = vec.size();
    std::string str= "COUNT="+std::to_string(count);
    vector<std::string> temp ={str};
    
return temp;

   }