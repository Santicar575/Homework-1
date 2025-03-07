#include <iostream>
#include <fstream>
#include <string>

enum Labels{DEBUG, INFO, WARNING, ERROR, CRITICAL};

void logMessage(const std::string& mensaje, int NivelSeveridad){ //??????????????????????? const std::string& ???????????????????????
    std::ofstream outFile("log.txt",std::ios::app);
    if (outFile.is_open()) { 
        switch (NivelSeveridad)
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
        outFile<<mensaje<<'\n';
        outFile.close();
        }else{
            std::cerr << "Error abriendo el archivo!\n";
        }
}

int main(){
    logMessage("Prueba DEBUG",DEBUG);
    logMessage("Prueba INFO",INFO);
    logMessage("Prueba WARNING",WARNING);
    logMessage("Prueba ERROR",ERROR);
    logMessage("Prueba CRITICAL",CRITICAL);
    return 0;
}
