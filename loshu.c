#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


const int size = 3;

int checkRows(const int[][size]);
int checkColumns(const int[][size]);
int checkDiagonals(const int[][size]);
int checkLoshu(const int[][size]);
void printArray(const int[][size]);
void shuffle(int *array, int n);



int main () {

    //Generate random numbers everytime
    time_t t;
    srand((unsigned)time(&t));
    int randomCounter = 0;

    //Using example working Loshu Square
    int array[][3] = {{4, 9, 2}, 
                    {3, 5, 7}, 
                    {8, 1, 6}};

    printArray(array);
    if(checkRows(array)== 1 && checkColumns(array) == 1 && checkDiagonals(array)==1)
        printf("Loshu square \n");
    else   
        printf("Not a loshu square \n");

    //Using example of not working Loshu Square
    int array2[][3] = {{1, 2, 3}, 
                    {4, 5, 6}, 
                    {7, 8, 9}};
    printArray(array2);
    if(checkRows(array2)== 1 && checkColumns(array2) == 1 && checkDiagonals(array2)==1)
        printf("Loshu square \n");
    else   
        printf("Not a loshu square \n");

    //Create new array, shuffle and check if loshu square
    int arrayRandom[3][3];
    int oneDimensionArray[9] = {1,2,3,4,5,6,7,8,9};

    do {
        shuffle(oneDimensionArray, 9);
        arrayRandom[0][0] = oneDimensionArray[0];
        arrayRandom[0][1] = oneDimensionArray[1];
        arrayRandom[0][2] = oneDimensionArray[2];

        arrayRandom[1][0] = oneDimensionArray[3];
        arrayRandom[1][1] = oneDimensionArray[4];
        arrayRandom[1][2] = oneDimensionArray[5];

        arrayRandom[2][0] = oneDimensionArray[6];
        arrayRandom[2][1] = oneDimensionArray[7];
        arrayRandom[2][2] = oneDimensionArray[8];

        randomCounter++;
    } while(!(checkRows(arrayRandom) == 1 && checkColumns(arrayRandom) == 1 && checkDiagonals(arrayRandom)==1));

    printArray(arrayRandom);
    printf("This took %d tries.", randomCounter);
}

int checkRows(const int numbers[][size])
{
    int sum[3];
    for (int i = 0; i < size; i++){
        sum[i] = numbers[i][0] + numbers[i][1] + numbers[i][2];
    }
    if (sum[0] == sum[1] && sum[1] == sum[2] && sum[0] == 15)
        return 1;
    else
        return 0;
}

int checkColumns(const int numbers[][size])
{
    int sum[3];
    for (int i = 0; i < size; i++){
        sum[i] = numbers[0][i] + numbers[1][i] + numbers[2][i];
    }
    if (sum[0] == sum[1] && sum[1] == sum[2] && sum[0] == 15)
        return 1;
    else
        return 0;
}

int checkDiagonals(const int numbers[][size])
{
    int sum1 = numbers[0][0] + numbers[1][1] + numbers[2][2];
    int sum2 = numbers[2][0] + numbers[1][1] + numbers[0][2];

    if (sum1 == sum2 && sum1 == 15)
        return 1;
    else
        return 0;
}

void printArray(const int arr[][size])
{
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void shuffle(int *array, int n) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < n - 1; i++) {
        size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}