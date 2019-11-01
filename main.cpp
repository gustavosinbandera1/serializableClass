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
 
  // wifi_dto.printData();
    return 0;
}
  

