#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Funzione che mappa un valore da [1,5] all'intervallo [-1,2]
double mappaValori(double x) {
    return 0.75 * x - 1.75;
}

int main() {
    // Apertura del file di input
    ifstream input("data.txt");
    if (!input.is_open()){
        cerr << "Errore nell'apertura del file data.txt" << endl;
        return 1;
    }
    
    // Lettura dei valori dal file
    vector<double> valori;
    double x;
    while (input >> x) {
        valori.push_back(x);
    }
    input.close();

    // Apertura del file di output
    ofstream output("risultato.txt");
    if (!output.is_open()){
        cerr << "Errore nell'apertura del file risultato.txt" << endl;
        return 1;
    }
    
    // Scrittura dell'intestazione
    output << "# N Media" << endl;
    
    double somma = 0.0;
    // Calcolo e stampa della media per ogni i-esimo valore
    for (size_t i = 0; i < valori.size(); i++) {
        double mappati = mappaValori(valori[i]);
        somma += mappati;
        double media = somma / (i + 1);
        // Formattazione in notazione scientifica
        output << (i + 1) << " " << scientific << setprecision(16) << media << endl;
    }
    
    output.close();

    return 0;
}

