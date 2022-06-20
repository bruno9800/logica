#include "project.h"
#include <string>

int truthTable(string str){
    string fnd = "", fnc = "";
    int expInt;
    list<char> prop;
    list<char>::iterator it=prop.begin();
    int binvalue;
    int tam, repetido = 0;
    string binary = "";
    string props;
    for(size_t i = 0; i < str.size() ; i++){
        if(checarSimb(str[i])){
        	for(it=prop.begin();it!=prop.end();++it){
        		if(str[i]== *it)
        			repetido  = 1;
			}
			if(repetido == 0)
            	prop.push_front(str[i]);
            repetido = 0;
        }

    }
    prop.sort(); // ordem
    for(size_t i = 0; i < prop.size(); i++){
        binary.append("1");
    }
    tam = pow(2, prop.size());
    //cout << binary << endl;
    binvalue = toDecimal(binary);


    // show table ---------------------------
    for(int i = 0; i <= tam; i++){
        if( i == 0){
            cout << "|";
            while(!prop.empty()){
            cout
                << setw(3)
                << prop.front()
                << setw(3)
                << "|";
                props += prop.front();
                prop.pop_front();
            }
            cout
                << setw(str.size()+1)
                << str
                << setw(3)
                << "|\n";
        }else{
            binary = toBinary(binvalue, binary.size());
            binvalue -= 1;
           // cout << "|  " << binary << "\n";
            for(size_t i = 0 ; i < binary.size(); i++){
                cout << "|  "<< binary[i] << "  ";
            }
            expInt = resultExpression(str, binary, props);
            if(expInt)
                fnd.append(fndEfnc(props,binary,expInt));
            else
                fnc.append(fndEfnc(props,binary,expInt));
            cout << "|"
                 << setw(str.size()-2)
                 << expInt
                 << setw(6)
                 << "|\n";
        }
    }
    if(fnd.size()>0)
        fnd.erase(fnd.end()-1);
    else
        fnd = "Nao existe";
    if(fnc.size()>0)
        fnc.erase(fnc.end()-1);
    else
        fnc = "Nao existe";
    cout << "\nFND = " << fnd
         << "\nFNC = " << fnc
         << "\n";
    return 0;
}
