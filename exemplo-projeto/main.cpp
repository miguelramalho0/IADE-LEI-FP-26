#include <iostream>
#include "util.h"

using namespace std;
using namespace util;

int main() {
    bool executando = true;

    while (executando) {
        cout << "\n";
        cout << "Use W, A, S, D ou as setas para mover.\n";
        cout << "Use Q ou ESC para sair.\n";

        Tecla tecla = lerTecla();

        switch (tecla) {
        case Tecla::Cima:
            cout << "Movimento para cima.\n";
            break;

        case Tecla::Baixo:
            cout << "Movimento para baixo.\n";
            break;

        case Tecla::Esquerda:
            cout << "Movimento para a esquerda.\n";
            break;

        case Tecla::Direita:
            cout << "Movimento para a direita.\n";
            break;

        case Tecla::Sair:
            cout << "Fim do jogo.\n";
            executando = false;
            break;

        case Tecla::Nenhuma:
            cout << "Tecla nao reconhecida.\n";
            break;
        }
    }

    return 0;
}