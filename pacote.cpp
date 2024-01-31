
//realiza opera��es bit-a-bit com os dados recebidos e retorna o resultado, que futuramente ser� a vari�vel global "rede"
unsigned int empacotar(unsigned int passo, unsigned int cor, unsigned int pos, unsigned int vel, unsigned int oleo) {

    passo = passo & 0xFF;
    cor = cor & 0xFF;
    pos = pos & 0x7F;
    vel = vel & 0xF;
    oleo = oleo & 0x1;


    unsigned int resultado = 0;
    resultado |= (passo << 24);
    resultado |= (cor << 16);
    resultado |= (pos << 9);
    resultado |= (vel << 5);
    resultado |= (oleo << 4);

    return resultado;
}

/*as fun��es a seguir recebem o resultado de empacotar(rede) e fragmenta em partes menores, que ser�o usadas tanto para exibir para o usu�rio como para
calcular a pr�xima posi��o em rede.cpp*/

unsigned int passoPacote(unsigned int resultado) {
    unsigned int passo = (resultado >> 24) & 0xFF;
    return passo;
}

unsigned int corPacote(unsigned int resultado) {
    unsigned int cor = (resultado >> 16) & 0xFF;
    return cor;
}

unsigned int posicaoPacote(unsigned int resultado) {
    unsigned int posicao = (resultado >> 9) & 0x7F;
    return posicao;
}

unsigned int velocidadePacote(unsigned int resultado) {
    unsigned int velocidade = (resultado >> 5) & 0xF;
    return velocidade;
}

unsigned int oleoPacote(unsigned int resultado) {
    unsigned int oleo = (resultado >> 4) & 0x1;
    return oleo;
}
