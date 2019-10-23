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
std::cout <<"address in main: "<< static_cast<const void*>(buffer)<<std::endl;

std::cout<<"------------------------------------------------------------"<<std::endl;
miPersona.deserialize(buffer);


//free(buffer);

    return 0;
}