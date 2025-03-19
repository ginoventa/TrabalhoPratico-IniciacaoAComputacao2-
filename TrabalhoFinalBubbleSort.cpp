#include <iostream>
#include <ctime>
using namespace std;

int comparacoes = 0, movimentacoes = 0;

void ordenacaoBubblesort(int *vetorBubbleSort, int tamanhoVetor){
    int numeroAtual;

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
}
int main(){

    int tamanhoVetor;
    clock_t tempo1, tempo2;
    double tempo_total;

    cout << "Qual sera o tamanho n do vetor? ";
    cin >> tamanhoVetor;
    cin.ignore();
    int vetorBubbleSort[tamanhoVetor + 1];

    /*
    //Atribuicao de valores aleatorio - pares e impares tem padroes distintos
    for(int i = 1; i <= tamanhoVetor; i++){
        if(i%2){
            vetorBubbleSort[i] = 3*i;
        }
        else{
            vetorBubbleSort[i] = ((5*i)/2 + 3);
        }
    }

    cout << endl << "\nDefina cada posicao do vetor, partindo de 1 ate n: \n";
    for(int aux = 1; aux <= tamanhoVetor; aux++){
        cout << "\tVetor " << aux << ": ";
            cin >> vetorBubbleSort[aux];
            cin.ignore();
        cout << endl;
    }*/

    //Atribuicao de valores decrescentes
    int j = tamanhoVetor;
    for(int i = 1; i <= tamanhoVetor; i++){
        vetorBubbleSort[i] = j;
        j--;
    }

    /*
    //Atribuicao de valores crescentes
    for(int i = 1; i <= tamanhoVetor; i++){
        vetorBubbleSort[i] = i;
    }*/

    //Estrutura que fara o calculo de tempo
    cout << endl << endl;
    tempo1 = clock();
    ordenacaoBubblesort(vetorBubbleSort, tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout << "\nTempo total: " << tempo_total;

    cout << "Ordenacao por metodo bolha: ";
    //Estrutura que printa vetor ordenado - usado para conferir a organizacao dos vetores dados
    for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
      cout << vetorBubbleSort[aux3] << " ";
    }

    //Estrutura que printa o numero de movimentacoes e comparacoes
    cout << endl << "Movimentacoes: "<< movimentacoes << " e comparacoes: "
    << comparacoes;

}
