 #include <iostream>
//#include "Persona.h"
#include "WiFiDTO.h"


char ssid[] = "miSSIDPersonal";
char pass[] = "miPassword";
int main (void) {
    
    wifi_dto_config_t wifi_params = {
    wifi_params.apChannel = 8,
    wifi_params.apMaxConn = 7,
    wifi_params.WAP_enabled = 1, // Default value
    wifi_params.WST_enabled = 1, // Default value
    wifi_params.isOpen = 1,
    wifi_params.apSSID = ssid,
    wifi_params.apPassword = pass,
        
    };  

    size_t length;
    char* buffer;
    char** pBuffer = &buffer; //when serialized buffer point to different address , that is why pBuffer can hold the initial address
        
    
    WiFiDTO wifi_dto(wifi_params);
    length = wifi_dto.serialize_size(); //get the length of the dto class
    //buffer to store the serialized data
   
    buffer = (char*)malloc(sizeof(char)*length);
    wifi_dto.serialize(buffer);
    std::cout << "<-------------------------> fin de la serializacion <-----------------> " << std::endl;
    std::cout <<"------------------>>>" << static_cast<const void*>(buffer)<<""<<std::endl;
    
    buffer = *pBuffer; //recover the initial address to deserialized information
    std::cout <<"ADDRESS BUFFER TO DESERIALIZE>"<< static_cast<const void*>(buffer)<<"------>"<<std::endl;
     wifi_dto.printData();
    wifi_dto.deserialize(buffer);
 
   wifi_dto.printData();
    return 0;
}
  


/* 
int main() {


char array[10]= "gustavo";
Persona miPersona(array,32,45.65,5400);
size_t length =  miPersona.serialize_size();

char* buffer;
buffer  = (char*)malloc(sizeof(char)*length);

miPersona.serialize(buffer);
// size_t len = *(size_t*)buffer;
// std::cout<<"------------------------------------------------------------"<<std::endl;
// std::cout <<"address(l): "<< static_cast<const void*>(buffer)<<std::endl;
// std::cout<<"el buffer "<<len<<std::endl;//length
// buffer = buffer + sizeof(size_t);
// std::cout <<"address(char*): "<< static_cast<const void*>(buffer)<<std::endl;
// std::cout<<"salida2------>"<<buffer<<std::endl;//name
// buffer = buffer + len ;
// std::cout <<"address(int): "<< static_cast<const void*>(buffer)<<std::endl;
// std::cout<<"salida 3------>"<<*(int*)buffer<<std::endl; //age
// buffer = buffer + sizeof(int);
// std::cout <<"address(float): "<< static_cast<const void*>(buffer)<<std::endl;
// std::cout<<"salida4---->"<<*(float*)buffer<<std::endl;
// buffer = buffer + sizeof(float);
// std::cout <<"address(double): "<< static_cast<const void*>(buffer)<<std::endl;
// std::cout<<"salida4---->"<<*(double*)buffer<<std::endl; 

char nameTest[] = "carlos";
miPersona.setMoney(12000);
miPersona.setWeight(68.8);
miPersona.setAge(38);
miPersona.printData();
miPersona.change_name(nameTest);

miPersona.deserialize(buffer);
miPersona.printData();
    return 0;
}   */