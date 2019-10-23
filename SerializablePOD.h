#include <stdio.h>
#include <iostream>
#include <cstring>


template <typename POD>
class SerializablePOD
{
public:

    static size_t serialize_size(POD str)
    {
        std::cout<<"el TAMANO ES "<<sizeof(str)<<std::endl;
        return sizeof(str);
    }

    static char* serialize( char* target, POD value )
    {  
        char* temp;
        std::cout<<"vamos a verificar"<<std::endl;
        temp = (char*)memcpy( target, &value, serialize_size(value) );
        std::cout<<"verificado"<<serialize_size(value)<<std::endl;
        return temp;
    } 

    static const char* deserialize( const char* source, POD& target )
    {
        std::cout<<"Vamos a deserializar"<<std::endl;
        memcpy( &target, source, serialize_size(target) );
        return source + serialize_size(target);
     
    }
};

template<>
size_t SerializablePOD<char*>::serialize_size(char* str)
{
    std::cout<<"el TAMANO del char* "<<sizeof(size_t) + strlen(str)<<std::endl;
    return sizeof(size_t) + strlen(str);
}

template<>
const char* SerializablePOD<char*>::deserialize( const char* source, char*& target )
{
    //source = source + 8;

     size_t length;
     memcpy( &length, source, 8);
    //size_t t = *(size_t*)length; 
    std::cout<<std::endl<<"--------------el tamano es :"<<length<<std::endl;
   // memcpy( &target, source , length );
    return source + sizeof(size_t) + length;
}

template<>
char* SerializablePOD<char*>::serialize( char* target, char* value )
{  
    char* temp;
    size_t l = strlen(value);
    std::cout<<"vamos a serializar char*->"<<l<<std::endl;
    memcpy( target,&l , sizeof(size_t) );
    target = target + sizeof(size_t);
    std::cout<<target<<std::endl;
    
    temp = (char*)memcpy( target, value, strlen(value) );
    
    //std::cout<<"verificado"<<serialize_size(value)<<std::endl;
    //target = target+serialize_size(value);//move the pointer 
    return temp;
} 