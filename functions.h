#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ShowVector(int** vectorOfVector, int* auxVectorsSize, int numberOfDivisions){
    int iterator;
    //percorre cada vetor
    for(iterator=0;iterator<numberOfDivisions;iterator++){
        int i;
        printf("    Vetor %d: [", iterator);
        //percorre o vetor selecionado
        for(i=0;i<auxVectorsSize[iterator];i++){
            printf("%d",vectorOfVector[iterator][i]);
            printf("%c",(i<auxVectorsSize[iterator]-1?',':']'));
        }
        printf("\n");
    }
}

//efetiva a troca de dois valores em um vetor
void Swap(int** vectorOfVector,int iterator, int i, int smallest){
    int aux = vectorOfVector[iterator][i];
    vectorOfVector[iterator][i]= vectorOfVector[iterator][smallest];
    vectorOfVector[iterator][smallest]= aux;
    return;
}

//SelectionSort = Ordena o vetor(do menor para o maior)
void SortAuxVector(int** vectorOfVector, int* auxVectorsSize, int numberOfdivisions){
    printf("Ordenando os vetores...\n\n");
    int iterator;
    //seleciona cada vetor auxiliar
    for(iterator=0;iterator<numberOfdivisions;iterator++){
        int i;
        //percorre o vetor selecionado para encontrar o menor valor
        for(i=0; i< auxVectorsSize[iterator]; i++){
            int smallest = i;
            int index;
            for(index= i+1;index<auxVectorsSize[iterator]; index++){
                if(vectorOfVector[iterator][index]<vectorOfVector[iterator][smallest]){
                smallest = index;
                }
            }
            Swap(vectorOfVector,iterator, i, smallest);
        }
    }
    return;
}

//Preenche o vetor com a quantide de espaços necessários para cada vetor auxiliar
void DefineAuxVectorsSize(int* auxVectorsSize, int numberOfdivisions, int baseSize, int module)
{
    printf("\nDefinindo o tamanho dos vetores auxiliares...\n");
    int iterator;
    for(iterator=0;iterator<numberOfdivisions;iterator++)
    {
        auxVectorsSize[iterator]= baseSize+(iterator<module?1:0);
    }
}

//Aloca memória no vetor a ser preenchido, baseando-se no espaço necessário definido na função DefineAuxVectorsSize
void AllocateVectorsMemory(int** vectorOfVector, int* auxVectorsSize, int numberOfdivisions)
{
    printf("\nalocando memoria...\n");
    int iterator;
    for(iterator= 0;iterator<numberOfdivisions;iterator++)
    {
        vectorOfVector[iterator]= (int*)malloc(auxVectorsSize[iterator]*sizeof(int));
    }
}

//Split the values of parentVector in numberOfdivisions times and fit in vectorOfvector
void FitFinalArray(int** vectorOfVector,int* auxVectorsSize, int* parentVector, int numberOfdivisions)
{
    printf("\nPreenchendo os vetores...\n\n");
    int iterator;
    int parentVectorIndex= 0;
    int auxiliaryIterator;
    //percorre cada vetor
    for(iterator=0;iterator<numberOfdivisions;iterator++)
    {
        //iterate content of selected vector
        for(auxiliaryIterator=0;auxiliaryIterator<auxVectorsSize[iterator];auxiliaryIterator++)
        {
            vectorOfVector[iterator][auxiliaryIterator]= parentVector[parentVectorIndex++];
        }
    }
}

//Free allocate memory
void FreeMalloc(int** vectorOfVector, int* auxVectorsSize, int numberOfdivisions)
{
    printf("\nLiberando memoria...\n");
    int i;
    for(i=0;i<numberOfdivisions;i++){
        free(vectorOfVector[i]);
    }
    free(vectorOfVector);
    free(auxVectorsSize);
    printf("\nMemoria liberada com sucesso!\n");
}