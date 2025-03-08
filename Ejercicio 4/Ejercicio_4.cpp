#include <iostream>
#include <chrono>

constexpr bool equals(const char* str1, const char* str2, int curr_char=0);

#define str_1 "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
#define str_2 "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567891"


constexpr bool equals(const char* str1, const char* str2,int curr_char){
    if(str1[curr_char] == '\0' && str2[curr_char] == '\0'){
        return true;
    }
    if(str1[curr_char] != str2[curr_char]){
        return false;
    }else{
        return equals(str1,str2,curr_char+1);
    }
}


int main(){
    //Utilizo const char* en lugar de string ya que al no guardar ningun tipo de metadato es un poco mas rapido
    constexpr bool res_1 = equals(str_1,str_1);
    constexpr bool res_2 = equals(str_1,str_2);
    
    auto startTime = std::chrono::high_resolution_clock::now();
    std::cout<<"Comparo str1 y str2: "<< ((res_1) ? "Son iguales" : "Son diferentes") << '\n';
    std::cout<<"Comparo str1 y str3: "<< ((res_2) ? "Son iguales" : "Son diferentes") << '\n';
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    std::cout << "Tardo " << elapsedTime.count() << " nanosegundos" << '\n';

    return 0;
}


