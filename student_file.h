#include <vector>
#include <queue>

using namespace std;

class Jugadores {
public:
    vector<int> Torneo(vector<int> habilidades, int N, int K);
};

vector<int> Jugadores::Torneo(vector<int> habilidades, int N, int K) {
    queue<int> cola;
    
    for (int i = 2; i < habilidades.size(); ++i) {
        cola.push(habilidades[i]);
    }

    int juegosGanados = 0;
    int jugadorActual = habilidades[0];
    int jugadorDesafiante = habilidades[1];

    vector<int> resultado(2);
    for (int juego = 1; juego <= K; ++juego) {
        if (jugadorActual > jugadorDesafiante) {
            juegosGanados++;
            resultado = {jugadorDesafiante, jugadorActual};
            cola.push(jugadorDesafiante);
        } else {
            juegosGanados = 1;
            resultado = {jugadorActual, jugadorDesafiante};
            cola.push(jugadorActual);
            jugadorActual = jugadorDesafiante;
        }
        //Si el jugador gano n juegos, va al final
        if (juegosGanados == N) {
            cola.push(jugadorActual);
            jugadorActual = cola.front();
            cola.pop();
            juegosGanados = 0;
        }
        jugadorDesafiante = cola.front();
        cola.pop();
    }
    return resultado;
}
