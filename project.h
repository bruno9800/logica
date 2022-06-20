#include <iostream>
#include <string>
#include<algorithm>
#include <list>
#include <math.h>
#include <string.h>
#include <iomanip>

using namespace std;


int checarConectivos(char x); // verifica se é conectivo ( negação não considerada);
int checarSimb(char x); // verificar se é Simbolo ( letras Maiusc. e Minusc );

// bin-to-int e int-to-bin;
string toBinary(int valor, int x); // inteiro em binario;
int toDecimal(string binario); // binario em inteiro;

//---------principais funções;
int checkFbf(string str); // verificar se é uma FBF;
int truthTable(string str); // constroi a tabela verdade;
string fndEfnc(string props, string binvalue, int exp);

// ---------operações lógicas-------------
string negacao(string sub); // realiza as operacoes de negacao;
string andOUor(string sub); // realiza as operacoes de and e or;
string ifThen(string sub); // realiza as operacoes de se, então;
string ifOnlyIf( string sub); // realiza as operoes de se, somente se;

// -----retorna a resposta da expressao com os valores definidos pela tabela;
int resultExpression(string expression, string binvalue, string prop);


