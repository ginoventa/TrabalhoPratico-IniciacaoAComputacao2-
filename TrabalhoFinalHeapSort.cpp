#include <iostream>
#include <ctime>
using namespace std;

int movimentacoesHeapSort = 0;
int comparacoesHeapsort = 0;

void heapify(int *vetorHeapSort, int L, int R){

    int i = L, j = 2*L;
    int x = vetorHeapSort[L];
    movimentacoesHeapSort++; //Atribuicao de um elemento do vetorHeapSort

    comparacoesHeapsort++;
    if(j < R && vetorHeapSort[j] < vetorHeapSort[j+1]){
        j++;
    }

    while(j <= R && x < vetorHeapSort[j]){
        vetorHeapSort[i] = vetorHeapSort[j];//Atribuicao de um elemento do vetorHeapSort
        i = j;
        j = 2*j;
        movimentacoesHeapSort++;
        comparacoesHeapsort+= 2;

        if(j < R && vetorHeapSort[j] < vetorHeapSort[j+1]){
            j++;
        }

    }

    comparacoesHeapsort++;

    vetorHeapSort[i] = x;
    movimentacoesHeapSort++;//Atribuicao de um elemento do vetorHeapSort

}

void ordenacaoHeapsort(int *vetorHeapSort, int tamanhoVetor){

    int w;

    for(int L = tamanhoVetor/2; L >= 1; L = L - 1){
        heapify(vetorHeapSort, L , tamanhoVetor);
    }

    for(int R = tamanhoVetor; R >= 2; R = R - 1){
        w = vetorHeapSort[1];
        vetorHeapSort[1] = vetorHeapSort[R];
        vetorHeapSort[R] = w;
        movimentacoesHeapSort += 3;//3 atribuicoes utilizando um elemento do vetorHeapSort
        heapify(vetorHeapSort, 1 , R - 1);
    }
}

int main(){

    int tamanhoVetor;
    clock_t tempo1, tempo2;
    double tempo_total;

    cout << "Qual sera o tamanho n do vetor? ";
    cin >> tamanhoVetor;

    int vetorHeapSort[tamanhoVetor + 1];

    /*
    //Atribuicao de valores aleatorio - pares e impares tem padroes distintos
    for(int i = 1; i <= tamanhoVetor; i++){
        if(i%2){
            vetorHeapSort[i] = 3*i;
        }
        else{
            vetorHeapSort[i] = ((5*i)/2 + 3);
        }
    }

    cout << endl << "\nDefina cada posicao do vetor, partindo de 1 ate n: \n";
    for(int aux = 1; aux <= tamanhoVetor; aux++){
        cout << "\tVetor " << aux << ": ";
            cin >> vetorHeapSort[aux];
            cin.ignore();
        cout << endl;
    }

    //Atribuicao de valores decrescentes
    int j = tamanhoVetor;
    for(int i = 1; i <= tamanhoVetor; i++){
        vetorHeapSort[i] = j;
        j--;
    }*/

    //Atribuicao de valores crescentes
    for(int i = 1; i <= tamanhoVetor; i++){
        vetorHeapSort[i] = i;
    }

    //Estrutura que fara o calculo de tempo
    cout << endl << endl;
    tempo1 = clock();
    ordenacaoHeapsort(vetorHeapSort,tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout << "\nTempo total: " << tempo_total;

    cout << "HeapSort: ";
    //Estrutura que printa vetor ordenado - usado para conferir a organizacao dos vetores dados
    /*for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
       cout << vetorHeapSort[aux3] << " ";
    }*/

    //Estrutura que printa o numero de movimentacoes e comparacoes
    cout << endl << "Movimentacoes: "<< movimentacoesHeapSort
    << " e comparacoes: " << comparacoesHeapsort;

}
