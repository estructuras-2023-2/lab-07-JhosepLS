#include <vector>
#include <queue>

using namespace std;

class Jugadores {
public:
    vector<int> Torneo(vector<int> habilidades, int N, int K);
};

vector<int> Jugadores::Torneo(vector<int> habilidades, int N, int K) {
    queue<int> cola;
    int actualGanador = habilidades[0];
    int actualPerdedor = habilidades[1];
    int contadorVictorias = 0;

    for (int i = 2; i < habilidades.size(); ++i) {
        cola.push(habilidades[i]);
    }
}
