#ifndef UTIL_H
#define UTIL_H

#ifdef _WIN32
    #include <curses.h>   // PDCurses
#else
    #include <ncurses.h>  // Linux/macOS
#endif

namespace util {

enum class Tecla {
    Nenhuma,
    Cima,
    Baixo,
    Esquerda,
    Direita,
    Sair
};

namespace detalhe {

inline Tecla converterTecla(int tecla) {
    switch (tecla) {
        case 'w':
        case 'W':
        case KEY_UP:
            return Tecla::Cima;

        case 's':
        case 'S':
        case KEY_DOWN:
            return Tecla::Baixo;

        case 'a':
        case 'A':
        case KEY_LEFT:
            return Tecla::Esquerda;

        case 'd':
        case 'D':
        case KEY_RIGHT:
            return Tecla::Direita;

        case 'q':
        case 'Q':
        case 27: // ESC
            return Tecla::Sair;

        default:
            return Tecla::Nenhuma;
    }
}

inline void descartarRepeticoes() {
    /*
     * Coloca a leitura em modo não bloqueante.
     * getch() retornará ERR caso não exista outro evento disponível.
     */
    nodelay(stdscr, TRUE);

    /*
     * Aguarda um intervalo curto para que eventuais repetições
     * automáticas do teclado cheguem ao buffer.
     */
    napms(60);

    /*
     * Remove do buffer as repetições da tecla.
     */
    while (getch() != ERR) {
        // Descarta os eventos repetidos.
    }

    nodelay(stdscr, FALSE);
}

} // namespace detalhe

inline Tecla lerTecla() {
    /*
     * Inicializa o curses apenas durante a leitura.
     * Assim, o restante do programa pode continuar usando cout e cin.
     */
    initscr();

    cbreak();             // Não exige o pressionamento de Enter
    noecho();             // Não mostra a tecla no terminal
    keypad(stdscr, TRUE); // Reconhece as teclas direcionais
    curs_set(0);          // Oculta o cursor

    int tecla = getch();

    detalhe::descartarRepeticoes();

    /*
     * Restaura o terminal para que cout e cin funcionem normalmente.
     */
    endwin();

    return detalhe::converterTecla(tecla);
}

} // namespace util

#endif // UTIL_H