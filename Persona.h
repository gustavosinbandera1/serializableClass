#include <stdio.h>
#include <string.h>
#include "Serializable.h"
#include "SerializablePOD.h"



class Persona : public Serializable
{
public:
    Persona(char* _name = NULL,int _age = 0, float _weight = 0, double _money = 0) : 
            name(_name),age(_age), weight(_weight), money(_money) {}
    
    virtual size_t serialize_size() const
    {
        size_t size =   SerializablePOD<char*>::serialize_size(name) +
                        SerializablePOD<int>::serialize_size(age) +
                        SerializablePOD<float>::serialize_size(weight)  + 
                        SerializablePOD<double>::serialize_size(money);               
        return size;
    }

    virtual void serialize(char* dataOut) const
    {
         std::cout <<"address: String"<< static_cast<const void*>(dataOut)<<std::endl;
         dataOut = SerializablePOD<char*>::serialize(dataOut, name);
         dataOut = dataOut + strlen(name);
         std::cout <<"address(INT): "<< static_cast<const void*>(dataOut)<<std::endl;
         SerializablePOD<int>::serialize(dataOut, age);
         std::cout<<"address(INT-DATA):"<<*(int*)dataOut<<std::endl;
         dataOut += sizeof(int);
         std::cout <<"address: (float)"<< static_cast<const void*>(dataOut)<<std::endl;
         SerializablePOD<float>::serialize(dataOut, weight);
         dataOut +=sizeof(float);
         std::cout <<"address: (DOUBLE) "<< static_cast<const void*>(dataOut)<<std::endl;
         SerializablePOD<double>::serialize(dataOut, money);
         dataOut += sizeof(double);
         //std::cout <<"address: "<< static_cast<const void*>(dataOut)<<std::endl; 
    }
    virtual void deserialize(const char* dataIn)
    {   //dataIn = dataIn + 7;
        //std::cout<<"DATA:"<<*(int*)dataIn<<std::endl;
        dataIn = SerializablePOD<char*>::deserialize(dataIn, name);
        // dataIn = SerializablePOD<int>::deserialize(dataIn, age);
        //dataIn = SerializablePOD<float>::deserialize(dataIn, weight); 
        //dataIn = SerializablePOD<double>::deserialize(dataIn, money); 
    } 

    int getAge()
    {
        return age;
    }
    float getWeight()
    {
        return weight;
    }
    double getMoney()
    {
        return money;
    }
private:
    char *name;
    int   age;
    float weight;
    double money;
};