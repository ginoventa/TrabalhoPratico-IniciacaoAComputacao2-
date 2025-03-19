#include <iostream>
#include <ctime>
using namespace std;

int comparacoesInsercaoBinaria = 0, movimentacoesInsercaoBinaria = 0;

void ordenacaoInsercaoBinaria(int *vetorOrdenadoBinaria, int tamanhoVetor){

    int numeroAtual, meio, esquerda, direita, j;

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
            }else{
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
}

int main(){

    int tamanhoVetor;
    clock_t tempo1, tempo2;
    double tempo_total;

    cout << "Qual sera o tamanho n do vetor? ";
    cin >> tamanhoVetor;
    cin.ignore();

    int vetorOrdenadoBinaria[tamanhoVetor + 1];


    //Atribuicao de valores aleatorio - pares e impares tem padroes distintos
    for(int i = 1; i <= tamanhoVetor; i++){
        if(i%2){
            vetorOrdenadoBinaria[i] = 3*i;
        }
        else{
            vetorOrdenadoBinaria[i] = ((5*i)/2 + 3);
        }
    }
 /*
    cout << endl << "\nDefina cada posicao do vetor, partindo de 1 ate n: \n";
    for(int aux = 1; aux <= tamanhoVetor; aux++){
        cout << "\tVetor " << aux << ": ";
            cin >> vetorOrdenadoBinaria[aux];
            cin.ignore();
        cout << endl;
    }

    //Atribuicao de valores decrescentes
    int j = tamanhoVetor;
    for(int i = 1; i <= tamanhoVetor; i++){
        vetorOrdenadoBinaria[i] = j;
        j--;
    }

    //Atribuicao de valores crescentes
    for(int i = 1; i <= tamanhoVetor; i++){
        vetorOrdenadoBinaria[i] = i;
    }*/


    //Estrutura que fara o calculo de tempo
    cout << endl << endl;
    tempo1 = clock();
    ordenacaoInsercaoBinaria(vetorOrdenadoBinaria, tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout << endl << "Tempo total: " << tempo_total;

    cout << endl << "Ordenacao por insercao binaria: ";
    //Estrutura que printa vetor ordenado - usado para conferir a organizacaoo dos vetores dados
    /*for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorOrdenadoBinaria[aux3] << " ";
    }*/
    //Estrutura que printa o numero de movimentacoes e comparacoes
    cout << endl << "Movimentacoes: "<< movimentacoesInsercaoBinaria << " e comparacoes: "
    << comparacoesInsercaoBinaria;

}
