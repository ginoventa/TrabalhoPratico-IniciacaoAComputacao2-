#include <iostream>
#include <ctime>
using namespace std;

int movimentacoesMergeSort = 0;
int comparacoesMergesort = 0;

void merge1(int *vetorMergesort, int L, int h, int R, int *c){

    int i = L, j = h + 1, k = L - 1;

    while(i <= h && j<= R){
        k = k + 1;
        comparacoesMergesort++;
        if(vetorMergesort[i] < vetorMergesort[j]){
            c[k] = vetorMergesort[i];
            i++;
            movimentacoesMergeSort++;
        }
        else{
            c[k] = vetorMergesort[j];
            j++;
            movimentacoesMergeSort++;
        }
    }

    while(i <= h){
        k++;
        c[k] = vetorMergesort[i];
        i++;

        movimentacoesMergeSort++;
    }

    while(j <= R){
        k++;
        c[k] = vetorMergesort[j];
        j++;
        movimentacoesMergeSort++;
    }
}

void mpass(int *vetorMergesort, int tamanhoVetor, int p, int *c){

    int i = 1;

    while(i <= tamanhoVetor - 2*p + 1){
        merge1(vetorMergesort, i, i+p-1, i+2*p-1, c);
        i = i + 2*p;
    }
    if(i + p - 1 < tamanhoVetor){
        merge1(vetorMergesort, i, i+p-1, tamanhoVetor, c);
    }
    else{
        for(int j = i; j <= tamanhoVetor; j++){
            c[j] = vetorMergesort[j];
            movimentacoesMergeSort++;
        }
    }
}


void ordenacaoMergesort(int *vetorMergesort, int tamanhoVetor){

    int p = 1, c[tamanhoVetor + 1], comparacoes = 0, movimentacoes = 0;

    while( p < tamanhoVetor ){
        mpass(vetorMergesort, tamanhoVetor, p, c);
        p = 2*p;
        mpass(c, tamanhoVetor, p, vetorMergesort);
        p = 2*p;
    }
}

int main(){

    int tamanhoVetor;
    clock_t tempo1, tempo2;
    double tempo_total;

    cout << "Qual sera o tamanho n do vetor? ";
    cin >> tamanhoVetor;
    cin.ignore();

    int vetorMergesort[tamanhoVetor + 1];


    /*
    //Atribuicao de valores aleatorio - pares e impares tem padroes distintos
    for(int i = 1; i <= tamanhoVetor; i++){
        if(i%2){
            vetorMergesort[i] = 3*i;
        }
        else{
            vetorMergesort[i] = ((5*i)/2 + 3);
        }
    }

    cout << endl << "\nDefina cada posicao do vetor, partindo de 1 ate n: \n";
    for(int aux = 1; aux <= tamanhoVetor; aux++){
        cout << "\tVetor " << aux << ": ";
            cin >> vetorMergesort[aux];
            cin.ignore();
        cout << endl;
    }

    //Atribuicao de valores decrescentes
    int j = tamanhoVetor;
    for(int i = 1; i <= tamanhoVetor; i++){
        vetorMergesort[i] = j;
        j--;
    }

    /*
    //Atribuicao de valores crescentes
    for(int i = 1; i <= tamanhoVetor; i++){
        vetorMergesort[i] = i;
    }*/

    //Estrutura que fara o calculo de tempo
    cout << endl << endl;
    tempo1 = clock();
    ordenacaoMergesort(vetorMergesort,tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout <<  "\nTempo total: " << tempo_total;

    cout << endl << "Mergesort: ";
    //Estrutura que printa vetor ordenado - usado para conferir a organizacao dos vetores dados
    /*for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorMergesort[aux3] << " ";
    }*/


    //Estrutura que printa o numero de movimentacoes e comparacoes
    cout << endl << "Movimentacoes: "<< movimentacoesMergeSort
    << " e comparacoes: " << comparacoesMergesort;
}
