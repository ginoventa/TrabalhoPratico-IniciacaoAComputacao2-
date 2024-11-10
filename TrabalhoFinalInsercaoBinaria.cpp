#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void ordenacaoInsercaoBinaria(int *vetorOrdenadoBinaria, int tamanhoVetor){

    int numeroAtual, meio, esquerda, direita, j;
    int comparacoesInsercaoBinaria = 0, movimentacoesInsercaoBinaria = 0;

    for(int aux1 = 2; aux1 <= tamanhoVetor; aux1++){

        numeroAtual = vetorOrdenadoBinaria[aux1];
        esquerda = 1;
        direita = aux1;
        movimentacoesInsercaoBinaria++;

        while(esquerda < direita){
            meio = (esquerda+direita)/2;

            comparacoesInsercaoBinaria++;
            if(vetorOrdenadoBinaria[meio] <= numeroAtual){
                esquerda = meio + 1;
            }

            else{
                direita = meio;
            }
        }
        j = aux1;

        while(j > direita){
            vetorOrdenadoBinaria[j] = vetorOrdenadoBinaria[j-1];
            j = j - 1;

            movimentacoesInsercaoBinaria++;
        }
        vetorOrdenadoBinaria[direita] = numeroAtual;
        movimentacoesInsercaoBinaria++;
    }

    cout << "Ordenacao por insercao binaria: ";
    /*for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorOrdenadoBinaria[aux3] << " ";
    }

    cout << endl << "Movimentacoes: "<< movimentacoesInsercaoBinaria << " e comparacoes: " << comparacoesInsercaoBinaria;*/
}

int main(){

    int tamanhoVetor;
    clock_t tempo1, tempo2;
    double tempo_total;

    cout << "Qual sera o tamanho n do vetor? ";
    cin >> tamanhoVetor;
    cin.ignore();

    int vetorOrdenadoBinaria[tamanhoVetor + 1];

    /*cout << endl << "\nDefina cada posicao do vetor, partindo de 1 ate n: \n";
    for(int aux = 1; aux <= tamanhoVetor; aux++){
        cout << "\tVetor " << aux << ": ";
            cin >> vetorOrdenadoBinaria[aux];
            cin.ignore();
        cout << endl;
    }*/

    for(int i = 1; i >= tamanhoVetor; i++){
        vetorOrdenadoBinaria[i] = i;
    }
    tempo1 = clock();
    ordenacaoInsercaoBinaria(vetorOrdenadoBinaria, tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout << endl << "Tempo total: " << tempo_total;

}
