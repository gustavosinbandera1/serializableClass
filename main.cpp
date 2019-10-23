#include <iostream>
#include "Persona.h"




int main() {


char array[10]= "gustavo";
Persona miPersona(array,32,45.65,5400);
size_t length =  miPersona.serialize_size(); //get the complete  size of the Class' attributes 

char* buffer; //buffer to save the serialized data
buffer  = (char*)malloc(sizeof(char)*length);

miPersona.serialize(buffer); //serialize data 
std::cout<<"------------------------------------------------------------"<<std::endl;
miPersona.deserialize(buffer); //restore the data 


free(buffer);

    return 0;
}