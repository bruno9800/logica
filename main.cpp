#include "project.h"

using namespace std;

int checarConectivos(char x){
	if(x== 124 || x == 62 || x== 60 || x == 38)
		return 1;
	return 0;
}

int checarSimb(char x){
	if( (x > 64 && x < 91) || (x > 96 && x < 122) )
		return 1;
	return 0;
}

int main() {
	string str;
    int error, op;

    do{
    system("cls");
	cout << "Ola\n";
	cout <<"--------------- Simbolos utilizados no codigo -------------\n";
	cout <<"| pontuacao               ->>            '('  ')'          \n";
	cout <<"| simbolos proposicionais ->>      todas as letras         \n";
	cout << endl;
	cout <<"------------------------------------------------------ \n";
	cout <<"                       Conectivos                      \n";
	cout <<"                 nao        >>   #\n";
	cout <<"                  e         >>   &\n";
	cout <<"                 ou         >>   |\n";
	cout <<"             se..., entao   >>   >\n";
	cout <<"         se, e somente se   >>   <\n";
	cout <<"------------------------------------------------------ \n";
	cout << "insirir string : ";
    fflush(stdin);
	getline(cin, str);
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); // remover espacos
	error = checkFbf(str);
    if(!error){
        cout << "\n--------------" << str << "--------------\n\n";
    truthTable(str);
    }else{
        cout << "\nerror:A string inserida nao eh uma FBF!\n";
    }
    cout << "\nDeseja visualizar uma nova tabela verdade ?"
         << "\n1 -  sim"
         << "\n0 -  nao"
         << "\nresposta >> ";
    cin >> op;
    }while(op!=0);

    cout << "\nFinalizar Programa...\n";
    system("pause");
}
