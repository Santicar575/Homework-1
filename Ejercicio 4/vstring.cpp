#include <iostream>
#include <string>
#include <chrono>

bool equals(char* str1, int len_1, char* str2, int len_2);
bool equals(const std::string& str1, const std::string& str2);
bool equals_aux(const std::string& str1, const std::string& str2, long unsigned int len, long unsigned int  curr_char=0);

int main1(){
    const std::string str1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    const std::string str2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    const std::string str3 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567891";
    
    auto startTime = std::chrono::high_resolution_clock::now();
    std::cout<<"Comparo str1 y str2: "<< ((equals(str1,str2)) ? "Son iguales" : "Son diferentes") << '\n';
    std::cout<<"Comparo str1 y str3: "<< ((equals(str1,str3)) ? "Son iguales" : "Son diferentes") << '\n';
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    std::cout << "Tardo " << elapsedTime.count() << " nanosegundos" << std::endl;

    return 0;
}

bool equals(const std::string& str1, const std::string& str2){
    if(str1.length() != str2.length()){
        return false;
    }
    return equals_aux(str1,str2,str1.length());
}

bool equals_aux(const std::string& str1, const std::string& str2, long unsigned int  len, long unsigned int  curr_char){
    if(curr_char == len){
        return true;
    }
    if(str1[curr_char] != str2[curr_char]){
        return false;
    }else{
        return equals_aux(str1,str2,len,curr_char+1);
    }
}



