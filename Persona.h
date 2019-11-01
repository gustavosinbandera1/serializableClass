#include "Serializable.h"
#include <stdio.h>
#include <string.h>
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
        std::cout <<"address(INT): "<< static_cast<const void*>(dataOut)<<std::endl;
        dataOut = SerializablePOD<int>::serialize(dataOut, age);
        std::cout<<"address(INT-DATA):"<<*(int*)dataOut<<std::endl;
        std::cout <<"address: (float)"<< static_cast<const void*>(dataOut)<<std::endl;
        dataOut = SerializablePOD<float>::serialize(dataOut, weight);
        std::cout <<"address: (DOUBLE) "<< static_cast<const void*>(dataOut)<<std::endl;
        dataOut = SerializablePOD<double>::serialize(dataOut, money);
    }
    virtual void deserialize(const char* dataIn)
    {   
        dataIn = SerializablePOD<char*>::deserialize(dataIn, name);
        dataIn = SerializablePOD<int>::deserialize(dataIn, age);
        dataIn = SerializablePOD<float>::deserialize(dataIn, weight); 

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
    void change_name(char* name_) {
        name = name_;
    }

    void setMoney(double money_) {
        money = money_;
    }
    void setWeight(float peso){
        weight = peso;
    }
    void setAge(int edad) {
        age = edad;
    }

    void printData(void) {
        std::cout <<"--------------------------------------------------------"<< std::endl;
        std::cout <<"Name: " << name <<std::endl;
        std::cout <<"Money: " << money << std::endl;
        std::cout <<"Weight: " << weight << std::endl;
        std::cout <<"Age: " << age << std::endl;
    }
private:
    char *name;
    int   age;
    float weight;
    double money;
};
