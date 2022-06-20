#include <iostream>
#include <string>
#include<algorithm>
#include <list>
#include <math.h>
#include <string.h>
#include <iomanip>

using namespace std;


int checarConectivos(char x); // verifica se � conectivo ( nega��o n�o considerada);
int checarSimb(char x); // verificar se � Simbolo ( letras Maiusc. e Minusc );

// bin-to-int e int-to-bin;
string toBinary(int valor, int x); // inteiro em binario;
int toDecimal(string binario); // binario em inteiro;

//---------principais fun��es;
int checkFbf(string str); // verificar se � uma FBF;
int truthTable(string str); // constroi a tabela verdade;
string fndEfnc(string props, string binvalue, int exp);

// ---------opera��es l�gicas-------------
string negacao(string sub); // realiza as operacoes de negacao;
string andOUor(string sub); // realiza as operacoes de and e or;
string ifThen(string sub); // realiza as operacoes de se, ent�o;
string ifOnlyIf( string sub); // realiza as operoes de se, somente se;

// -----retorna a resposta da expressao com os valores definidos pela tabela;
int resultExpression(string expression, string binvalue, string prop);


