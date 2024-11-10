#include <iostream>
#include <ctime>
#include <cstdlib>
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

void ordenacaoQuicksort(int *vetorQuickSort, int tamanhoVetor){

    int indice_menor, numeroAtual;

    qsort(vetorQuickSort, 1, tamanhoVetor);

    cout << "Quicksort: ";
    /*for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorQuickSort[aux3] << " ";
    }
    cout << endl << "Movimentacoes: "<< movimentacoesQuickSort << " e comparacoes: " << comparacoesQuickSort;
*/
}

int main(){

    int tamanhoVetor;
    clock_t tempo1, tempo2;
    double tempo_total;

    cout << "Qual sera o tamanho n do vetor? ";
    cin >> tamanhoVetor;
    cin.ignore();

    int vetorQuickSort[tamanhoVetor + 1];

    /*cout << endl << "\nDefina cada posicao do vetor, partindo de 1 ate n: \n";
    for(int aux = 1; aux <= tamanhoVetor; aux++){
        cout << "\tVetor " << aux << ": ";
            cin >> vetorQuickSort[aux];
            cin.ignore();
        cout << endl;
    }*/

    int j = 1;
    for(int i = tamanhoVetor; i >= 1; i++){
        vetorQuickSort[j] = i;
        j++;
    }



    cout << endl << endl;
    tempo1 = clock();
    ordenacaoQuicksort(vetorQuickSort,tamanhoVetor);
    tempo2=clock();
    cout << "\nTempo total: " << difftime(tempo2,tempo1)/CLOCKS_PER_SEC;

}
