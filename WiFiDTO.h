#include <iostream>
#include "Serializable.h"
#include "SerializablePOD.h"



/*
This class represent the data that need to travel throught: 
1. System storage
2. Sockets
3. Serial communication
*/

   typedef struct wifi_dto_config_t {
    int apChannel;
    int apMaxConn;
    int WAP_enabled; // Default value
    int  WST_enabled; // Default value
    int isOpen;
    char* apSSID;
    char* apPassword;
    
   
} wifi_dto_config_t;

class WiFiDTO : public Serializable {

public:
 

    WiFiDTO(wifi_dto_config_t& settings) {
        settings_ = settings;
        // settings_ = settings;
        std::cout<<"esto es una prueba mas"<<std::endl;
        std::cout<<"constructor working fine"<<std::endl;

        std::cout << "Showing Data" << std::endl;
        std::cout << "Settings.apChannel " << settings_.apChannel << std::endl;
        std::cout << "Settings.apMaxConn " << settings_.apMaxConn << std::endl;
        std::cout << "Settings.apPassword " << settings_.apPassword << std::endl;
        std::cout << "Settings.SSID " << settings_.apSSID << std::endl;
        std::cout << "Settings.Wap Enabled " << settings_.WAP_enabled << std::endl;
        std::cout << "Settings.WST " << settings_.WST_enabled << std::endl;  
        std::cout << "Settings.isOpen " << settings_.isOpen << std::endl;
    }
    WiFiDTO();

    virtual size_t serialize_size() const {
        size_t size;  
        size =  SerializablePOD<int>::serialize_size(settings_.apChannel) + 
        SerializablePOD<int>::serialize_size(settings_.apMaxConn) + 
        SerializablePOD<int>::serialize_size(settings_.WAP_enabled) +
        SerializablePOD<int>::serialize_size(settings_.WST_enabled) +
        SerializablePOD<int>::serialize_size(settings_.isOpen);
        SerializablePOD<char*>::serialize_size(settings_.apSSID)  + 
        SerializablePOD<char*>::serialize_size(settings_.apPassword);
          
                    
        return size; 
    }


    virtual void serialize(char* dataOut) const {
        std::cout <<"--------------------SERIALIZATION ---------->"<<std::endl;

        std::cout <<"apChannel: (int)------------->"<< static_cast<const void*>(dataOut)<<"------>"<<settings_.apChannel<<std::endl;
        dataOut = SerializablePOD<int>::serialize(dataOut, settings_.apChannel);

        std::cout <<"apMaxConn: (int)------------->"<< static_cast<const void*>(dataOut)<<"------->"<<settings_.apMaxConn<<std::endl;
        dataOut = SerializablePOD<int>::serialize(dataOut, settings_.apMaxConn);

        std::cout <<"Wap Enabled: bool------------->"<< static_cast<const void*>(dataOut)<<"------->"<<settings_.WAP_enabled<<std::endl;
        dataOut = SerializablePOD<int>::serialize(dataOut, settings_.WAP_enabled);
        
        std::cout <<"WST_enabled(bool): ---------->"<< static_cast<const void*>(dataOut)<<"------->"<<settings_.WST_enabled<<std::endl;
        dataOut = SerializablePOD<int>::serialize(dataOut, settings_.WST_enabled);

        std::cout <<"isOpen: (bool)------------->"<< static_cast<const void*>(dataOut)<<"------->"<<settings_.isOpen<<std::endl;
        dataOut = SerializablePOD<int>::serialize(dataOut, settings_.isOpen);

        std::cout <<"apSSID: (char*) --------->"<< static_cast<const void*>(dataOut)<<std::endl;
        dataOut = SerializablePOD<char*>::serialize(dataOut, settings_.apSSID);

       std::cout <<"apPassword: (char*) -------->"<< static_cast<const void*>(dataOut)<<std::endl;
        dataOut  = SerializablePOD<char*>::serialize(dataOut, settings_.apPassword); 
        
    }
    virtual void deserialize(const char* dataIn) {
        std::cout <<"--------------------DESERIALIZATION ---------->"<<std::endl;

        //std::cout <<": ---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        SerializablePOD<int>::deserialize(dataIn, settings_.apChannel); 
        std::cout<<"dato deserializado en el metodo------------>"<<*(int*)dataIn<<"------->"<< static_cast<const void*>(dataIn)<<std::endl;

        //std::cout <<": ---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        dataIn = SerializablePOD<int>::deserialize(dataIn, settings_.apMaxConn); 
        std::cout<<"dato deserializado en el metodo------------>"<<*(int*)dataIn<<"------->"<<static_cast<const void*>(dataIn)<<std::endl;
        
        //std::cout <<": ---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        dataIn = SerializablePOD<int>::deserialize(dataIn, settings_.WAP_enabled);
        std::cout<<"dato deserializado en el metodo------------>"<<*(int*)dataIn<<"-------->"<<static_cast<const void*>(dataIn)<<std::endl;

        //std::cout <<": ---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        dataIn = SerializablePOD<int>::deserialize(dataIn, settings_.WST_enabled);
        std::cout<<"dato deserializado en el metodo------------>"<<*(int*)dataIn<<"-------->"<<static_cast<const void*>(dataIn)<<std::endl;

        //std::cout <<": ---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        dataIn = SerializablePOD<int>::deserialize(dataIn, settings_.isOpen); 
        std::cout<<"dato deserializado en el metodo------------>"<<*(int*)dataIn<<"-------->"<<static_cast<const void*>(dataIn)<<std::endl;
        dataIn = dataIn + 4;
        //std::cout <<": ---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        dataIn = SerializablePOD<char*>::deserialize(dataIn, settings_.apSSID); 
        std::cout<<"dato deserializado en el metodo------------>"<<static_cast<const void*>(dataIn)<<std::endl;
        std::cout <<": Last---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        //std::cout <<": ---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        dataIn = SerializablePOD<char*>::deserialize(dataIn, settings_.apPassword); 
        std::cout<<"dato deserializado en el metodo------------>"<<*(char*)dataIn<<std::endl; 

    }

    void setData(wifi_dto_config_t data) {
        settings_= data;
    }

    void printData(void) {
        std::cout<<"el dato de test"<<settings_.apChannel <<std::endl;
        std::cout<<"el dato de test"<<settings_.apMaxConn<<std::endl;
        std::cout<<"el dato de test"<<settings_.isOpen <<std::endl;
        std::cout<<"el dato de test"<<settings_.WAP_enabled <<std::endl;
        std::cout<<"el dato de test"<<settings_.WST_enabled <<std::endl;

        std::cout<<"*************************************************"<<std::endl;

        wifi_dto_config_t* ps = &settings_;
        std::cout << "first: -->" << *((int*)ps)<<"--->"<<ps <<std::endl;
        std::cout << "second: -->" << *((int*)ps +1) <<"--->"<<ps+1<<std::endl;
        std::cout << "3: -->" << *((int*)ps + 2)<<"--->"<<ps + 2 <<std::endl;
        std::cout << "4: -->" << *((int*)ps+3)<<"--->"<<ps + 3 <<std::endl;
        std::cout << "5: -->" << *((int*)ps + 4)<<"--->"<<ps + 4 <<std::endl;
        std::cout << "6: -->" << *((char*)ps + 5)<<"--->"<<ps + 5 <<std::endl;
    }



private:
    wifi_dto_config_t settings_;
};
