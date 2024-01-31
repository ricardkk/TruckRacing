#include <iostream>
#include "cores.h"
#include "pacote.h"
#include "rede.h"
#include <ctime>
using namespace std;


void limpaTela() {
	system("cls");
}

void WhiteSpace(int qtd) {
	while (qtd-- > 0) cout << ' ';
}


void desenhaCaminhao(int posicao, int cor) {
	ajustaCor(cor);
	cout << "\n"; WhiteSpace(posicao); cout << "\xDB\xDB\xDB\xDB\xDB\xDB \xDB\xDB\xDC";
	cout << "\n"; WhiteSpace(posicao); cout << "\xDF\xDFOO\xDF\xDF\xDF\xDFO\xDF";
	cout << "\n---------------------------------------------------------------------------------------------------|--------------------\n";
	cout << "                                                                                                  100";
	resetaCor();
}

int main()
{
	int posicaoA = 0, velocidadeA, corA, posicaoB = 0, velocidadeB, corB, r;
	bool estadoPistaA, estadoPistaB;

	int passo = 0;
	do
	{
		// ------------------
		// Limpa tela
		// Desenha caminhões
		// ------------------

		/*
		CORES DISPONÍVEIS:
		vermelho
		azulEscuro
		amarelo
		branco
		vinho
		azulClaro
		verde
		roxo
		*/

		corA = roxo; corB = verde;

		limpaTela();
		ajustaCor(15, 238); cout << "\n                                                     Truck Racing                                                       \n";
		desenhaCaminhao(posicaoA, corA);
		desenhaCaminhao(posicaoB, corB);

		// ------------------------
		// Atualiza velocidade
		// Atualiza estado da pista
		// ------------------------
		srand(unsigned(time(NULL)));
		velocidadeA = rand() % 10 + 1;
		velocidadeB = rand() % 10 + 1;
		estadoPistaA = rand() % 2;
		estadoPistaB = rand() % 2;

		// ----------------------------------
		// Transmite, recebe e processa dados
		// Calcula Próxima posição
		// ----------------------------------
		cout << endl;
		transmitir(passo, corA, posicaoA, velocidadeA, estadoPistaA);
		r = receber();
		posicaoA = processar(r);
		cout << endl;
		transmitir(passo, corB, posicaoB, velocidadeB, estadoPistaB);
		r = receber();
		posicaoB = processar(r);

		// -------------------------------
		// Aguarda pressionamento de tecla
		// -------------------------------

		cout << endl;
		system("pause");
		passo = passo + 1;
	} while (posicaoA <= 100 && posicaoB <= 100);

	// --------------------
	// Limpa tela
	// Desenha caminhões
	// Exibe resultados
	// --------------------
	limpaTela();
	ajustaCor(15, 238); cout << "\n                                                     Truck Racing                                                       \n";
	desenhaCaminhao(posicaoA, corA);
	desenhaCaminhao(posicaoB, corB);

	ajustaCor(15, 238); cout << "\n                                                     Corrida Concluída                                                      " << endl; resetaCor();
	cout << "\nPassos " << passo << endl;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(2);
	cout << "Posição " << posicaoA << " Velocidade média " << float(posicaoA) / float(passo) << endl;
	cout << "Posição " << posicaoB << " Velocidade média " << float(posicaoB) / float(passo) << endl;
}




