#include <iostream>
#include "cores.h"
using namespace std;

/*recebe par�metros que definem a cor da fonte e do fundo usando c�digos de escape ANSI,
no arquivo cores.h est�o algumas pr�-defini��es de cores para serem usadas*/
void ajustaCor(int corTexto, int corFundo) {
	cout << "\033[38;5;" << corTexto << "m";
	cout << "\033[48;5;" << corFundo << "m";
}
//define a cor de fonte e fundo para as padr�es do sistema
void resetaCor() {
	cout << "\033[0m";
}