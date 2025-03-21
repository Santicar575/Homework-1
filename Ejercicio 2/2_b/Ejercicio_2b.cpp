#include <iostream>
#include <fstream>
#include <string>

enum Labels{DEBUG, INFO, WARNING, ERROR, CRITICAL};

//declaracion de funciones 
void logMessage(const std::string& error, const std::string& file, int line);
void logMessage(const std::string& msg, int severity_level);
void logMessage(const std::string& access_msg, const std::string& user_name);


int main(){
    logMessage("Prueba DEBUG",DEBUG);
    logMessage("Prueba INFO",INFO);
    logMessage("Prueba WARNING",WARNING);
    logMessage("Prueba ERROR",ERROR);
    logMessage("Prueba CRITICAL",CRITICAL);
    logMessage("Algo salio mal","log.txt",18);
    logMessage("Access Granted","User1");
    //Prueba de excepciones
    try{
        int a = 20;
        int b = 0;
        if (b == 0) {
            throw std::runtime_error("Error: División por cero");
        }
        std::cout<<a/b<<'\n';
    }catch(const std::exception& e){
        //Se guarda el mensaje de error en el archivo log.txt
        logMessage(e.what(),"log.txt",25);
        return 1;
    }
    return 0;
}

void logMessage(const std::string& access_msg, const std::string& user_name){
    std::ofstream outFile("log.txt",std::ios::app);
    if (outFile.is_open()) {
        outFile<<"[SECURITY] "<<user_name<<':'<<access_msg<<'\n';
        outFile.close();
    }else{
            std::cerr << "Error abriendo el archivo\n";
    }
}

void logMessage(const std::string& error_msg, const std::string& file, int line){
    std::ofstream outFile(file,std::ios::app);
    if (outFile.is_open()) {
        outFile<<"[ERROR][Ln:"<<line<<"] "<<error_msg<<'\n';
        outFile.close();
    }else{
            std::cerr << "Error abriendo el archivo\n";
    }
}

void logMessage(const std::string& msg, int severity_level){ 
    std::ofstream outFile("log.txt",std::ios::app);
    if (outFile.is_open()) { 
        switch (severity_level)
        {
        case DEBUG:
            outFile<<"[DEBUG] ";
            break;
        case INFO:
            outFile<<"[INFO] ";
            break;
        case WARNING:
            outFile<<"[WARNING] ";
            break;
        case ERROR:
            outFile<<"[ERROR] ";
            break;
        case CRITICAL:
            outFile<<"[CRITICAL] ";
            break;
        default:
            std::cerr << "La etiqueta no existe\n";
            outFile.close();
            return;
        }
        outFile<<msg<<'\n';
        outFile.close();
        }else{
            std::cerr << "Error abriendo el archivo\n";
        }
}