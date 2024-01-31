#include <iostream>
#include "cores.h"
using namespace std;

/*recebe parâmetros que definem a cor da fonte e do fundo usando códigos de escape ANSI,
no arquivo cores.h estão algumas pré-definições de cores para serem usadas*/
void ajustaCor(int corTexto, int corFundo) {
	cout << "\033[38;5;" << corTexto << "m";
	cout << "\033[48;5;" << corFundo << "m";
}
//define a cor de fonte e fundo para as padrões do sistema
void resetaCor() {
	cout << "\033[0m";
}