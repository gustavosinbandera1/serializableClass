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
        settings_ = &settings;
        // settings_ = settings;
        std::cout<<"esto es una prueba mas"<<std::endl;
        std::cout<<"constructor working fine"<<std::endl;

        std::cout << "Showing Data" << std::endl;
        std::cout << "Settings.apChannel " << settings_->apChannel << std::endl;
        std::cout << "Settings.apMaxConn " << settings_->apMaxConn << std::endl;
        std::cout << "Settings.apPassword " << settings_->apPassword << std::endl;
        std::cout << "Settings.SSID " << settings_->apSSID << std::endl;
        std::cout << "Settings.Wap Enabled " << settings_->WAP_enabled << std::endl;
        std::cout << "Settings.WST " << settings_->WST_enabled << std::endl;  
        std::cout << "Settings.isOpen " << settings_->isOpen << std::endl;
    }
    WiFiDTO();

    virtual size_t serialize_size() const {
        size_t size;  
        size =  SerializablePOD<int>::serialize_size(settings_->apChannel) + 
        SerializablePOD<int>::serialize_size(settings_->apMaxConn) + 
        SerializablePOD<int>::serialize_size(settings_->WAP_enabled) +
        SerializablePOD<int>::serialize_size(settings_->WST_enabled) +
        SerializablePOD<int>::serialize_size(settings_->isOpen);
        SerializablePOD<char*>::serialize_size(settings_->apSSID)  + 
        SerializablePOD<char*>::serialize_size(settings_->apPassword);
          
                    
        return size; 
    }


    virtual void serialize(char* dataOut) const {
        std::cout <<"--------------------SERIALIZATION ---------->"<<std::endl;

        std::cout <<"apChannel: (int)------------->"<< static_cast<const void*>(dataOut)<<"------>"<<&settings_->apChannel<<"--->Value: "<< settings_->apChannel<<std::endl;
        dataOut = SerializablePOD<int>::serialize(dataOut, settings_->apChannel);

        std::cout <<"apMaxConn: (int)------------->"<< static_cast<const void*>(dataOut)<<"------->"<<&settings_->apMaxConn<<"--->Value: "<< settings_->apMaxConn<<std::endl;
        dataOut = SerializablePOD<int>::serialize(dataOut, settings_->apMaxConn);

        std::cout <<"Wap Enabled: bool------------->"<< static_cast<const void*>(dataOut)<<"------->"<<&settings_->WAP_enabled<<"--->Value: "<< settings_->WAP_enabled<<std::endl;
        dataOut = SerializablePOD<int>::serialize(dataOut, settings_->WAP_enabled);
        
        std::cout <<"WST_enabled(bool): ---------->"<< static_cast<const void*>(dataOut)<<"------->"<<&settings_->WST_enabled<<"--->Value: "<< settings_->WST_enabled<<std::endl;
        dataOut = SerializablePOD<int>::serialize(dataOut, settings_->WST_enabled);

        std::cout <<"isOpen: (bool)------------->"<< static_cast<const void*>(dataOut)<<"------->"<<&settings_->isOpen<<"--->Value: "<< settings_->isOpen<<std::endl;
        dataOut = SerializablePOD<int>::serialize(dataOut, settings_->isOpen);

        std::cout <<"apSSID: (char*) --------->"<< static_cast<const void*>(&settings_->apSSID)<<std::endl;
        dataOut = SerializablePOD<char*>::serialize(dataOut, settings_->apSSID);

       std::cout <<"apPassword: (char*) -------->"<< static_cast<const void*>(&settings_->apPassword)<<std::endl;
        dataOut  = SerializablePOD<char*>::serialize(dataOut, settings_->apPassword); 
        
    }
    virtual void deserialize(const char* dataIn) {
        std::cout <<"--------------------DESERIALIZATION ---------->"<<std::endl;

        //std::cout <<": ---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        SerializablePOD<int>::deserialize(dataIn, settings_->apChannel); 
        std::cout<<"dato deserializado en el metodo------------>"<<*(int*)dataIn<<"------->"<< static_cast<const void*>(&settings_->apChannel)<<std::endl;

        //std::cout <<": ---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        dataIn = SerializablePOD<int>::deserialize(dataIn, settings_->apMaxConn); 
        std::cout<<"dato deserializado en el metodo------------>"<<*(int*)dataIn<<"------->"<<static_cast<const void*>(&settings_->apMaxConn)<<std::endl;
        
        //std::cout <<": ---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        dataIn = SerializablePOD<int>::deserialize(dataIn, settings_->WAP_enabled);
        std::cout<<"dato deserializado en el metodo------------>"<<*(int*)dataIn<<"-------->"<<static_cast<const void*>(&settings_->WAP_enabled)<<std::endl;

        //std::cout <<": ---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        dataIn = SerializablePOD<int>::deserialize(dataIn, settings_->WST_enabled);
        std::cout<<"dato deserializado en el metodo------------>"<<*(int*)dataIn<<"-------->"<<static_cast<const void*>(&settings_->WST_enabled)<<std::endl;

        //std::cout <<": ---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        dataIn = SerializablePOD<int>::deserialize(dataIn, settings_->isOpen); 
        std::cout<<"dato deserializado en el metodo------------>"<<*(int*)dataIn<<"-------->"<<static_cast<const void*>(&settings_->apSSID)<<std::endl;
        dataIn = dataIn + 4;
        //std::cout <<": ---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        dataIn = SerializablePOD<char*>::deserialize(dataIn, settings_->apSSID); 
        std::cout<<"dato deserializado en el metodo------------>"<<static_cast<const void*>(&settings_->apPassword)<<std::endl;
        std::cout <<": Last---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        //std::cout <<": ---------->"<< static_cast<const void*>(dataIn)<<std::endl;
        /*  dataIn = SerializablePOD<char*>::deserialize(dataIn, settings_->apPassword); 
        std::cout<<"dato deserializado en el metodo------------>"<<*(char*)dataIn<<std::endl;   */

    }

    void setData(wifi_dto_config_t data) {
        settings_= &data;
    }

    void printData(void) {
        std::cout<<std::endl;
        std::cout<<"**************ADDRESSES STRUCT***********************************"<<std::endl;

        wifi_dto_config_t** ps = &settings_;
        std::cout <<"Main struct+----------"<<ps<<std::endl;
        std::cout <<"-----------------------------------------------"<<std::endl;
        //settings_ =settings_++;
        ;
        std::cout << "1: -->" <<*(int*)ps  <<"--->"<<ps<<std::endl;
        ps=ps+1;
        
         std::cout << "2: -->" << *(int*)ps<<"--->"<<ps <<std::endl;
        settings_ = settings_++;
        /*std::cout << "3: -->"<<*(int*)ps<<"--->"<<ps  <<std::endl;
        ps = ps +1;
        std::cout << "4: -->" <<"--->"<<ps <<std::endl;
        ps=ps+1;
        std::cout << "5: -->" <<"--->"<<ps <<std::endl; 
        ps=ps+1;
        std::cout << "6: -->" <<"--->"<<ps <<std::endl;  */
    }



private:
    wifi_dto_config_t* settings_;
};
