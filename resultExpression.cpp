#include "project.h"

string negacao(string sub){
    //cout << "\nstring inserida : " << sub << "\n";
	for(int i = 0; i < sub.size() - 1; i++){
			if(sub[i] == 35){
				switch(sub[i+1]){
					case '0':
						sub[i+1] = '1';
						sub.erase(i, 1);
						break;
					case '1':
						sub[i+1] = '0';
						sub.erase(i, 1);
						break;
				}
			}
		}
        //cout << "\n string not: " << sub << "\n";
		return sub;
}

string andOUor(string sub){
	int x, y;
	for(int i = 0; i < sub.size()-1; i++){
		if(checarConectivos(sub[i])){
			switch(sub[i]){
				case '&':
					x = sub[i-1]-48;
					y = sub[i+1]-48;
					x = ((x&&y)?1:0);
					sub[i-1] = x +48;
					sub.erase(i,2); //x&y -> &y erase -> x;
                    i = 0;
					break;
				case '|':
					x = sub[i-1]-48;
					y = sub[i+1]-48;
					x = ((x||y)?1:0);
					sub[i-1] = x +48;
					sub.erase(i,2);// x|y -> |y erase -> x;
                    i = 0;
					break;
                default:
                    break;
			}
		}
	}
	return sub;
}

string ifThen(string sub){
    int x, y;
	for(int i = 0; i < sub.size()-1; i++){
		if(sub[i] == 62){
					x = sub[i-1]-48;
					y = sub[i+1]-48;
					x = ((!x||y)?1:0);
					sub[i-1] = x +48;
					sub.erase(i,2); //x->y -> ->y erase -> x;
                    i = 0;
	    }
    }
    return sub;
}

string ifOnlyIf( string sub){
    int x, y;
	for(int i = 0; i < sub.size()-1; i++){
		if(sub[i] == 60){
					x = sub[i-1]-48;
					y = sub[i+1]-48;
					x = (((!x||y)&&(!y||x))?1:0);
					sub[i-1] = x +48;
					sub.erase(i,2); //x->y -> ->y erase -> x;
                    i = 0;
	    }
    }
    return sub;
}


int resultExpression(string expression, string binvalue, string prop){
	int quant = 0, count = 0;
	int posP0 = -1, posP1 = -1; // posicao do parentese 0-abre| 1-fecha
    int result;
	string sub;


    // ---------- preparando variaveis e substituindo proposicoes -----------/
    for(int i = 0 ; i < expression.size() ; i++){
		if(checarSimb(expression[i])){
			while(expression[i]!=prop[count])
				count++;
			expression[i] = binvalue[count]; // Substituir a proposicao pelo seu respectivo valor
            count = 0;
		}
		if(expression[i] == 40) // quantidade de parenteses;
			quant++;
    }
    //------------------------ fim -----------------------------------//


    // ------------------- Ordem de resolucao --------------------//


    // -------------------- Resolvendo parenteses ------------------ //
    while(quant > 0){
    for(int i = 0; i < expression.size();i++){
            if(expression[i] == 40){
                    posP0 = i;
                for(int j = expression.size();j > 0; j-- ){
				if(expression[j] == 41){
					if(posP0 < j)
						posP1 = j;
				}
			}
            }

		}
	sub = expression.substr(posP0+1, (posP1 - posP0)-1);
	expression.erase(posP0+1, (posP1 - posP0));
	sub = negacao(sub); // resolvendo negaçoes;
	sub = andOUor(sub); // resolvendo 'E' ou 'OU';
    sub = ifThen(sub); // resolvendo "se, então";
    sub = ifOnlyIf(sub); // resolvendo "se, somente se";
    expression[posP0] = sub[0];
    //cout << "\n" <<sub << "\n" << expression << "\n";
    quant--;
    }

    expression = negacao(expression);
    expression = andOUor(expression);
    expression = ifThen(expression);
    expression = ifOnlyIf(expression);
    result = expression[0] -48;
	return result;
}
