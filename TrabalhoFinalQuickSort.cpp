#include <iostream>
#include <ctime>
using namespace std;

int movimentacoesQuickSort = 0;
int comparacoesQuickSort = 0;

void qsort(int *vetorQuickSort, int L, int R){

    int i = L, j = R, w;
    int x = vetorQuickSort[((R+L)/2)];
    movimentacoesQuickSort++; //Movimenta o vetorQuickSort[R+L/2] para x

    do{
        while(vetorQuickSort[i] < x){
            i++;
            comparacoesQuickSort++;
        }
        comparacoesQuickSort++;

        while(x < vetorQuickSort[j]){
            j--;
            comparacoesQuickSort++;
        }
        comparacoesQuickSort++;

        if(i <= j){
            w = vetorQuickSort[i];
            vetorQuickSort[i] = vetorQuickSort[j];
            vetorQuickSort[j] = w;
            movimentacoesQuickSort+=3;

            i++;
            j--;
        }

    }while(i <= j);

    if(L < j){
        qsort(vetorQuickSort, L, j);
    }
    if(i < R){
        qsort (vetorQuickSort, i, R);
    }
}

void ordenacaoQuicksort(int *vetorQuickSort, int tamanhoVetor){

    int indice_menor, numeroAtual;

    qsort(vetorQuickSort, 1, tamanhoVetor);

}

int main(){

    int tamanhoVetor;
    clock_t tempo1, tempo2;
    double tempo_total;

    cout << "Qual sera o tamanho n do vetor? ";
    cin >> tamanhoVetor;
    cin.ignore();

    int vetorQuickSort[tamanhoVetor + 1];


    /*
    //Atribuicao de valores aleatorio - pares e impares tem padroes distintos
    for(int i = 1; i <= tamanhoVetor; i++){
        if(i%2){
            vetorQuickSort[i] = 3*i;
        }
        else{
            vetorQuickSort[i] = ((5*i)/2 + 3);
        }
    }

    cout << endl << "\nDefina cada posicao do vetor, partindo de 1 ate n: \n";
    for(int aux = 1; aux <= tamanhoVetor; aux++){
        cout << "\tVetor " << aux << ": ";
            cin >> vetorQuickSort[aux];
            cin.ignore();
        cout << endl;
    }*/

    //Atribuicao de valores decrescentes
    int j = tamanhoVetor;
    for(int i = 1; i <= tamanhoVetor; i++){
        vetorQuickSort[i] = j;
        j--;
    }

     /*
    //Atribuicao de valores crescentes
    for(int i = 1; i <= tamanhoVetor; i++){
        vetorQuickSort[i] = i;
    }*/


    //Estrutura que fara o calculo de tempo
    cout << endl << endl;
    tempo1 = clock();
    ordenacaoQuicksort(vetorQuickSort,tamanhoVetor);
    tempo2 = clock();
    cout << endl << "Quicksort: ";
    cout << "\nTempo total: " << difftime(tempo2,tempo1)/CLOCKS_PER_SEC;

    //Estrutura que printa vetor ordenado - usado para conferir a organizacao dos vetores dados
    for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorQuickSort[aux3] << " ";
    }

    //Estrutura que printa o numero de movimentacoes e comparacoes
    cout << endl << "Movimentacoes: "<< movimentacoesQuickSort << " e comparacoes: " << comparacoesQuickSort;

}
