#include <iostream>
#include <chrono>

bool equals(const char* str1, const char* str2, int curr_char=0);

int main(){
    //Utilizo const char* en lugar de string ya que al no guardar ningun tipo de metadato es un poco mas rapido
    const char* str_1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    const char* str_2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567891";
    
    auto startTime = std::chrono::high_resolution_clock::now();
    std::cout<<"Comparo str1 y str1: "<< ((equals(str_1,str_1)) ? "Son iguales" : "Son diferentes") << '\n';
    std::cout<<"Comparo str1 y str2: "<< ((equals(str_1,str_2)) ? "Son iguales" : "Son diferentes") << '\n';
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    std::cout << "Tardo " << elapsedTime.count() << " nanosegundos" << '\n';
    return 0;
}

bool equals(const char* str1, const char* str2,int curr_char){
    //Si llegue al final de ambos strings, son iguales  
    if(str1[curr_char] == '\0' && str2[curr_char] == '\0'){
        return true;
    }
    //Si en algun punto no coinciden entonces retorno false
    if(str1[curr_char] != str2[curr_char]){
        return false;
    }else{
        return equals(str1,str2,curr_char+1);
    }
}

