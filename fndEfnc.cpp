#include "project.h"
#include <sstream>


string fndEfnc(string props, string binvalue, int exp){
    string str;
    if(exp){
        str.append("(");
        for(size_t i = 0; i < props.size(); i++){
            if(binvalue[i] == '1'){
                str += props[i];
            }
            else{
              str.append("#");
              str += props[i];
            }
            if(i == props.size()-1)
                str.append(")|");
            else
                str.append("&");
        }
    }else{
        str.append("(");
        for(size_t i = 0; i < props.size(); i++){
            if(binvalue[i] == '0'){
                str += props[i];
            }
            else{
              str.append("#");
              str += props[i];
            }
            if(i == props.size()-1)
                str.append(")&");
            else
                str.append("|");
        }
    }
    return str;
}

