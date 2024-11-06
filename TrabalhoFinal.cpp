#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;


int movimentacoesHeapSort = 0;
int comparacoesHeapsort = 0;

int movimentacoesMergeSort = 0;
int comparacoesMergesort = 0;

int movimentacoesQuickSort = 0;
int comparacoesQuickSort = 0;



void definirVetor(int *vetorNumeros, int tamanhoVetor){

    cout << "\nDefina cada posicao do vetor, partindo de 1 ate n: \n";
    for(int aux = 1; aux <= tamanhoVetor; aux++){
        cout << "\tVetor " << aux << ": ";
            cin >> vetorNumeros[aux];
            cin.ignore();
        cout << endl;
    }
}

void ordenacaoInsercaoDireta(int *vetorNumeros, int tamanhoVetor){

    int aux2, numeroAtual, vetorOrdenadoDireta[tamanhoVetor + 1];
    int comparacoes = 0, movimentacoes = 0;

    for(int i = 1; i <= tamanhoVetor; i++){
        vetorOrdenadoDireta[i] = vetorNumeros[i];
    }

    for(int aux1 = 2; aux1 <= tamanhoVetor; aux1 ++){
        numeroAtual = vetorOrdenadoDireta[aux1];
        vetorOrdenadoDireta[0] = numeroAtual;
        aux2 = aux1;
        movimentacoes = movimentacoes + 2;

        while(aux2 > 0 && numeroAtual < vetorOrdenadoDireta[aux2 - 1]){
            vetorOrdenadoDireta[aux2] = vetorOrdenadoDireta[aux2-1];
            aux2 = aux2 - 1;
            comparacoes++;
            movimentacoes++;
        }
        comparacoes++;
        vetorOrdenadoDireta[aux2] = numeroAtual;
        movimentacoes++;
    }

    cout << "Ordenacao por insercao direta: ";
    for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorOrdenadoDireta[aux3] << " ";
    }

    cout << endl << "Movimentacoes: "<< movimentacoes << " e comparacoes: " << comparacoes;
}

void ordenacaoInsercaoBinaria(int *vetorNumeros, int tamanhoVetor){

    int numeroAtual, meio, esquerda, direita, j, vetorOrdenadoBinaria[tamanhoVetor + 1];
    int comparacoes = 0, movimentacoes = 0;

    for(int i = 1; i <= tamanhoVetor; i++){
        vetorOrdenadoBinaria[i] = vetorNumeros[i];
    }

    for(int aux1 = 2; aux1 <= tamanhoVetor; aux1++){

        numeroAtual = vetorOrdenadoBinaria[aux1];
        esquerda = 1;
        direita = aux1;
        movimentacoes++;

        while(esquerda < direita){
            meio = floor((esquerda+direita)/2);

            comparacoes++;
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

            movimentacoes++;
        }
        vetorOrdenadoBinaria[direita] = numeroAtual;
        movimentacoes++;
    }

    cout << "Ordenacao por insercao binaria: ";
    for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorOrdenadoBinaria[aux3] << " ";
    }

    cout << endl << "Movimentacoes: "<< movimentacoes << " e comparacoes: " << comparacoes;
}

void ordenacaoSelecao(int *vetorNumeros, int tamanhoVetor){

    int indice_menor, numeroAtual, vetorOrdenadoSelecao[tamanhoVetor + 1], comparacoes = 0, movimentacoes = 0;

    for(int i = 1; i <= tamanhoVetor; i++){
        vetorOrdenadoSelecao[i] = vetorNumeros[i];
    }


    for(int aux1 = 1; aux1 <= tamanhoVetor - 1; aux1++){
        indice_menor = aux1;
        for(int j = aux1 + 1; j <= tamanhoVetor; j++){
            comparacoes++;
            if(vetorOrdenadoSelecao[j] < vetorOrdenadoSelecao[indice_menor])
                indice_menor = j;
            }
        numeroAtual = vetorOrdenadoSelecao[aux1];
        vetorOrdenadoSelecao[aux1] = vetorOrdenadoSelecao[indice_menor];
        vetorOrdenadoSelecao[indice_menor] = numeroAtual;
        movimentacoes = movimentacoes + 3;
    }

    cout << "Ordenacao por selecao: ";
    for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorOrdenadoSelecao[aux3] << " ";
    }
   cout << endl << "Movimentacoes: "<< movimentacoes << " e comparacoes: " << comparacoes;

}
void ordenacaoBubblesort(int *vetorNumeros, int tamanhoVetor){


    int vetorBubbleSort[tamanhoVetor + 1], numeroAtual;
    int comparacoes = 0, movimentacoes = 0;

    for(int i = 1; i <= tamanhoVetor; i++){
        vetorBubbleSort[i] = vetorNumeros[i];
    }

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
    for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorBubbleSort[aux3] << " ";
    }
    cout << endl << "Movimentacoes: "<< movimentacoes << " e comparacoes: " << comparacoes;
}


void heapify(int *vetorHeapSort, int L, int R){

    int i = L, j = 2*L;
    int x = vetorHeapSort[L];
    movimentacoesHeapSort++; //Atribuição de um elemento do vetorHeapSort


    comparacoesHeapsort++; //If a seguir realiza uma comparação entre chaves
    if(j < R && vetorHeapSort[j] < vetorHeapSort[j+1]){
        j++;
    }

    while(j <= R && x < vetorHeapSort[j]){
        vetorHeapSort[i] = vetorHeapSort[j];//Atribuição de um elemento do vetorHeapSort
        i = j;
        j = 2*j;
        movimentacoesHeapSort++;

        comparacoesHeapsort+=2; //If e while realizam uma comparação entre chaves

        if(j < R && vetorHeapSort[j] < vetorHeapSort[j+1]){
            j++;
        }
    }
    comparacoesHeapsort++; //Comparação de saída do while

    vetorHeapSort[i] = x;
    movimentacoesHeapSort++;//Atribuição de um elemento do vetorHeapSort
}

void ordenacaoHeapsort(int *vetorNumeros, int tamanhoVetor){

    int vetorHeapSort[tamanhoVetor + 1], w;

    for(int i = 1; i <= tamanhoVetor; i++){
        vetorHeapSort[i] = vetorNumeros[i];
    }

    for(int L = tamanhoVetor/2; L >= 1; L = L - 1){
        heapify(vetorHeapSort, L , tamanhoVetor);
    }

    for(int R = tamanhoVetor; R >= 2; R = R - 1){
        w = vetorHeapSort[1];
        vetorHeapSort[1] = vetorHeapSort[R];
        vetorHeapSort[R] = w;
        movimentacoesHeapSort += 3;//3 atribuições utilizando um elemento do vetorHeapSort
        heapify(vetorHeapSort, 1 , R - 1);
    }

    cout << "HeapSort: ";
    for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorHeapSort[aux3] << " ";
    }
    cout << endl << "Movimentacoes: "<< movimentacoesHeapSort << " e comparacoes: " << comparacoesHeapsort;

}

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


void ordenacaoMergesort(int *vetorNumeros, int tamanhoVetor){

    int vetorMergesort[tamanhoVetor + 1], p = 1, c[tamanhoVetor + 1], comparacoes = 0, movimentacoes = 0;

    for(int i = 1; i <= tamanhoVetor; i++){
        vetorMergesort[i] = vetorNumeros[i];
    }

    while( p < tamanhoVetor ){
        mpass(vetorMergesort, tamanhoVetor, p, c);
        p = 2*p;
        mpass(c, tamanhoVetor, p, vetorMergesort);
        p = 2*p;
    }

    cout << "Mergesort: ";
    for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorMergesort[aux3] << " ";
    }

    cout << endl << "Movimentacoes: "<< movimentacoesMergeSort << " e comparacoes: " << comparacoesMergesort;
}


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
            j = j - 1;
            comparacoesQuickSort++;
        }

        comparacoesQuickSort++;

        if(i <= j){
            w = vetorQuickSort[i];
            vetorQuickSort[i] = vetorQuickSort[j];
            vetorQuickSort[j] = w;
            movimentacoesQuickSort+=3;

            i = i + 1;
            j = j - 1;

        }

    }while(i <= j);


    if(L < j){
        qsort(vetorQuickSort, L, j);
    }

    if(i < R){
        qsort (vetorQuickSort, i, R);
    }
}

void ordenacaoQuicksort(int *vetorNumeros, int tamanhoVetor){

    int indice_menor, numeroAtual, vetorQuickSort[tamanhoVetor + 1];

    for(int i = 1; i <= tamanhoVetor; i++){
        vetorQuickSort[i] = vetorNumeros[i];
    }

    qsort(vetorQuickSort, 1, tamanhoVetor);

    cout << "Quicksort: ";
    for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorQuickSort[aux3] << " ";
    }
    cout << endl << "Movimentacoes: "<< movimentacoesQuickSort << " e comparacoes: " << comparacoesQuickSort;

}

int main(){

    int tamanhoVetor = 8, j = 1;
    clock_t tempo1, tempo2;
    double tempo_total;

    int vetorNumero[8] = {45,56,12,43,95,19,8,67};

    /*cout << "Qual sera o tamanho n do vetor? ";
    cin >> tamanhoVetor;
    cin.ignore();*/

    int vetorNumeros[tamanhoVetor + 1];

    for(int i = 0; i <= 7; i++){
        vetorNumeros[j] = vetorNumero[i];
        j++;
    }

    //definirVetor(vetorNumeros, tamanhoVetor);

    tempo1 = clock();
    ordenacaoInsercaoDireta(vetorNumeros, tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout << "\nTempo total: " << tempo_total;
    cout << endl << endl;

    tempo1 = clock();
    ordenacaoInsercaoBinaria(vetorNumeros, tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout << endl << "Tempo total: " << tempo_total;

    cout << endl << endl;
    tempo1 = clock();
    ordenacaoSelecao(vetorNumeros, tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout << "\nTempo total: " << tempo_total;

    cout << endl << endl;
    tempo1 = clock();
    ordenacaoBubblesort(vetorNumeros, tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout << "\nTempo total: " << tempo_total;

    cout << endl << endl;
    tempo1 = clock();
    ordenacaoMergesort(vetorNumeros,tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout <<  "\nTempo total: " << tempo_total;

    cout << endl << endl;
    tempo1 = clock();
    ordenacaoHeapsort(vetorNumeros,tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout << "\nTempo total: " << tempo_total;

    cout << endl << endl;
    tempo1 = clock();
    ordenacaoQuicksort(vetorNumeros,tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout << "\nTempo total: " << tempo_total;

}
