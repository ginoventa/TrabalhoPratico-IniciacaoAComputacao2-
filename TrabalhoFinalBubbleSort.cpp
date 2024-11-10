#include <iostream>
#include <ctime>
using namespace std;

void ordenacaoBubblesort(int *vetorBubbleSort, int tamanhoVetor){


    int numeroAtual;
    int comparacoes = 0, movimentacoes = 0;

    for(int aux1 = 2; aux1 <= tamanhoVetor; aux1++){
        for(int aux2 = tamanhoVetor; aux2 >=  aux1; aux2 = aux2 - 1){
            comparacoes++;
            if(vetorBubbleSort[aux2 - 1] > vetorBubbleSort[aux2])
            {
                numeroAtual = vetorBubbleSort[aux2-1];
                vetorBubbleSort[aux2-1] = vetorBubbleSort[aux2];
                vetorBubbleSort[aux2] = numeroAtual;
                movimentacoes += 3;
            }
        }

    }

    cout << "Ordenacao por metodo bolha: ";
    /*for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorBubbleSort[aux3] << " ";
    }
    cout << endl << "Movimentacoes: "<< movimentacoes << " e comparacoes: " << comparacoes;*/
}

int main(){

    int tamanhoVetor;
    clock_t tempo1, tempo2;
    double tempo_total;

    cout << "Qual sera o tamanho n do vetor? ";
    cin >> tamanhoVetor;
    cin.ignore();

    int vetorBubbleSort[tamanhoVetor + 1];

    /*cout << endl << "\nDefina cada posicao do vetor, partindo de 1 ate n: \n";
    for(int aux = 1; aux <= tamanhoVetor; aux++){
        cout << "\tVetor " << aux << ": ";
            cin >> vetorBubbleSort[aux];
            cin.ignore();
        cout << endl;
    }*/

    for(int i = 1; i <= tamanhoVetor; i++){
        vetorBubbleSort[i] = i++;
    }

    cout << endl << endl;
    tempo1 = clock();
    ordenacaoBubblesort(vetorBubbleSort, tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout << "\nTempo total: " << tempo_total;

}

