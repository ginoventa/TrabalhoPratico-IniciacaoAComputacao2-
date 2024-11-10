#include <iostream>
#include <ctime>
using namespace std;

void ordenacaoSelecao(int *vetorOrdenadoSelecao, int tamanhoVetor){

    int indice_menor, numeroAtual, comparacoesSelecao = 0, movimentacoesSelecao = 0;

    for(int aux1 = 1; aux1 <= tamanhoVetor - 1; aux1++){
        indice_menor = aux1;
        for(int j = aux1 + 1; j <= tamanhoVetor; j++){
            comparacoesSelecao++;
            if(vetorOrdenadoSelecao[j] < vetorOrdenadoSelecao[indice_menor])
                indice_menor = j;
            }
        numeroAtual = vetorOrdenadoSelecao[aux1];
        vetorOrdenadoSelecao[aux1] = vetorOrdenadoSelecao[indice_menor];
        vetorOrdenadoSelecao[indice_menor] = numeroAtual;
        movimentacoesSelecao += 3;
    }

    cout << "Ordenacao por selecao: ";
    /*for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorOrdenadoSelecao[aux3] << " ";
    }
    cout << endl << "Movimentacoes: "<< movimentacoesSelecao << " e comparacoes: " << comparacoesSelecao;
*/
}

int main(){

    int tamanhoVetor = 250000;
    clock_t tempo1, tempo2;
    double tempo_total;

    cout << "Qual sera o tamanho n do vetor? ";
    //cin >> tamanhoVetor;
    //cin.ignore();

    int vetorOrdenadoSelecao[tamanhoVetor + 1];

    /*cout << endl << "\nDefina cada posicao do vetor, partindo de 1 ate n: \n";
    for(int aux = 1; aux <= tamanhoVetor; aux++){
        cout << "\tVetor " << aux << ": ";
            cin >> vetorOrdenadoSelecao[aux];
            cin.ignore();
        cout << endl;
    }*/

    for(int i = tamanhoVetor; i <= 1; i--){
        vetorOrdenadoSelecao[i] = i;
    }

    cout << endl << endl;
    tempo1 = clock();
    ordenacaoSelecao(vetorOrdenadoSelecao, tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout << "\nTempo total: " << tempo_total;

}
