#include <iostream>
#include "Persona.h"




int main() {


char array[10]= "gustavo";
Persona miPersona(array,32,45.65,5400);
size_t length =  miPersona.serialize_size();

/* std::cout<<"el length es : "<<length<<std::endl;
std::cout<<"el tamano de la estructura es "<<sizeof(miPersona)<<std::endl;
 */

char* buffer;
buffer  = (char*)malloc(sizeof(char)*length);

miPersona.serialize(buffer);
size_t len = *(size_t*)buffer;
std::cout<<"------------------------------------------------------------"<<std::endl;
std::cout <<"address(l): "<< static_cast<const void*>(buffer)<<std::endl;
std::cout<<"el buffer "<<len<<std::endl;//length
buffer = buffer + sizeof(size_t);
std::cout <<"address(char*): "<< static_cast<const void*>(buffer)<<std::endl;
std::cout<<"salida2------>"<<buffer<<std::endl;//name
buffer = buffer + len ;
std::cout <<"address(int): "<< static_cast<const void*>(buffer)<<std::endl;
std::cout<<"salida 3------>"<<*(int*)buffer<<std::endl; //age
buffer = buffer + sizeof(int);
std::cout <<"address(float): "<< static_cast<const void*>(buffer)<<std::endl;
std::cout<<"salida4---->"<<*(float*)buffer<<std::endl;
buffer = buffer + sizeof(float);
std::cout <<"address(double): "<< static_cast<const void*>(buffer)<<std::endl;
std::cout<<"salida4---->"<<*(double*)buffer<<std::endl;
//std::cout <<"address: "<< static_cast<const void*>(buffer)<<std::endl;
//miPersona.deserialize(buffer);
//std::cout<<"buffer serializado: "<<*(double*)buffer<<std::endl;

//miPersona.deserialize(buffer);

//char* buf = new char[length];

//free(buffer);

    return 0;
}