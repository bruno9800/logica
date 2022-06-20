#include "project.h"

int checkFbf(string str){
	int error = 0;
	int size, count = 0;
	size = str.size();

    // validando caracteres
    for(int i = 0; i < size; i++){
        if(!(checarConectivos(str[i]) || checarSimb(str[i]) || str[i] == 40 || str[i] == 41 || str[i] == 35)){
            error = 1;
            break;
        }
    }


	// iniciando com um conectivo (tirando a negacao)
	if(checarConectivos(str[0]))
		error = 1;

	// conectivo no final;
	if(error == 0 &&(str[size - 1]== 124 || str[size - 1] == 62 || str[size - 1]== 60 || str[size - 1] == 38 || str[size - 1] == 35))
		error = 1;

	if(error == 0){
		for(int i = 0 ; i < size -1 ; i++){
				if( (checarConectivos(str[i]) && checarConectivos(str[i+1])))
					error = 1;
				if( checarSimb(str[i]) && checarSimb(str[i+1]))
					error = 1;

			// parenteses
				if(str[i] == 40){
					if(checarConectivos(str[i+1]))
						error = 1;
					else{
						count++;
					}

				}
				if(str[i] == 41){
					if(checarConectivos(str[i - 1]))
						error = 1;
					else{
						if(str[i - 1]== 35) // corrigindo o caso do parentese fechar entre a negacao e a proposicao
							error = 1;
						count--;
					}
					if(str[i+1]){
						if(!checarConectivos(str[i + 1]))
							error = 1;
					}
				}
				//printf("error = %d\n", error);

				if(count < 0)
					error = 1;
				if(error == 1)
					break;
		}
	}
	if(str[size-1] == 41)
		count--;
	if(count != 0)
		error = 1;


	return error;
}

