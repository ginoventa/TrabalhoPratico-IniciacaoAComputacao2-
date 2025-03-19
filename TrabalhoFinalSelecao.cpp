#include <iostream>
#include <ctime>
using namespace std;

int comparacoesSelecao = 0, movimentacoesSelecao = 0;

void ordenacaoSelecao(int *vetorOrdenadoSelecao, int tamanhoVetor){

    int indice_menor, numeroAtual;
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
}

int main(){

    int tamanhoVetor;
    clock_t tempo1, tempo2;
    double tempo_total;

    cout << "Qual sera o tamanho n do vetor? ";
    cin >> tamanhoVetor;
    cin.ignore();

    int vetorOrdenadoSelecao[tamanhoVetor + 1];


    //Atribuicao de valores aleatorio - pares e impares tem padroes distintos
    for(int i = 1; i <= tamanhoVetor; i++){
        if(i%2){
            vetorOrdenadoSelecao[i] = 3*i;
        }
        else{
            vetorOrdenadoSelecao[i] = ((5*i)/2 + 3);
        }
    }

    cout << endl << "\nDefina cada posicao do vetor, partindo de 1 ate n: \n";
    for(int aux = 1; aux <= tamanhoVetor; aux++){
        cout << "\tVetor " << aux << ": ";
            cin >> vetorOrdenadoSelecao[aux];
            cin.ignore();
        cout << endl;
    }

    //Atribuicao de valores decrescentes
    int j = tamanhoVetor;
    for(int i = 1; i <= tamanhoVetor; i++){
        vetorOrdenadoSelecao[i] = j;
        j--;
    }
    /*
    //Atribuicao de valores crescentes
    for(int i = 1; i <= tamanhoVetor; i++){
        vetorOrdenadoSelecao[i] = i;
    }*/

    //Estrutura que fara o calculo de tempo
    cout << endl << endl;
    tempo1 = clock();
    ordenacaoSelecao(vetorOrdenadoSelecao, tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout << "\nTempo total: " << tempo_total;

    cout << "Ordenacao por selecao: ";
    //Estrutura que printa vetor ordenado - usado para conferir a organizacaoo dos vetores dados
    /*for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorOrdenadoSelecao[aux3] << " ";
    }*/

    //Estrutura que printa o numero de movimentacoes e comparacoes
    cout << endl << "Movimentacoes: "<< movimentacoesSelecao
    << " e comparacoes: " << comparacoesSelecao;

}
