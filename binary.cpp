#include "project.h"

string toBinary(int valor, int x){
    string binary;
    while(valor){
    binary.append((valor % 2 )== 0? "0":"1");
    valor /= 2;
    }
    if(binary.size() < x){
        for(size_t i = binary.size(); i < x; i++){
            binary.append("0");
        }
    }
    string inverter(binary.rbegin(), binary.rend());
    return inverter;
}

int toDecimal(string binario){
    int x, valor=0;
    for(size_t i = 0; i < binario.size() ; i++){
        x = binario[i]- 48;
        valor += x * pow(2, (binario.size()-1) - i);
    }

    return valor;
}
