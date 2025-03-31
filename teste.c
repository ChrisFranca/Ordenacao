#include "functions.h"

int main()
{
    int parentVector[] = {19,-21,54,79,98,-76,12,8,65,1};
    int parentVectorSize = sizeof(parentVector)/sizeof(parentVector[0]); 
    
    int numberOfdivisions;
    printf("How many auxiliar vectors you want?");
    scanf("%d",&numberOfdivisions);
    
    //define the auxiliares vectors
    int** vectorOfvector= (int**)malloc(numberOfdivisions*sizeof(int));
    int* auxVectorsSize = (int*)malloc(numberOfdivisions*sizeof(int));
    int module= parentVectorSize%numberOfdivisions;
    int baseSize= parentVectorSize/numberOfdivisions;
    
    DefineAuxVectorsSize(auxVectorsSize, numberOfdivisions, baseSize, module);
    AllocateVectorsMemory(vectorOfvector,auxVectorsSize,numberOfdivisions);
    FitFinalArray(vectorOfvector,auxVectorsSize,parentVector,numberOfdivisions);
    SortAuxVector(vectorOfvector, auxVectorsSize, numberOfdivisions);
    ShowVector(vectorOfvector, auxVectorsSize, numberOfdivisions);

    FreeMalloc(vectorOfvector,auxVectorsSize,numberOfdivisions);
    return 0;
}