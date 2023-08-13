#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#define X 2
#define Y 4
#define max 8

// Cost Memory Benchmark

struct example {
    int value;
    int *previous;
};



struct example arr[X][Y];
int arr2[max] = {0,1,2,3,4,5,6,7};

int arr3[X][Y];
int arr4[max] = {0,1,2,3,4,5,6,7};

void run(){
// With previous value
    struct example c;

    int position = 0;

    


// Without previous value
    int value;

    int position2 = 0;

    int option;
    printf("Choose result type:\n1 - Values comparison\n2 - Size comparison\n\n", option);
    scanf("%d", &option);
    system("clear");


    if(option == 1){
        printf("______________________________________________________________________________________________________________\n\n\n");
        // With previous value
        for(int i = 0;i < max; i++){

            c.value = 10*i;
            if(i == Y){
            position ++;
            c.previous = &arr[position - 1][Y - 1];
            arr[position][i] = c;
            printf("Position: %d  |  Value: %d  |  Previous: %d     -    Value of previous box:%d\n", position, arr[position][i].value, &arr[position][i].previous, *arr[position][i].previous);
            }else if(i == 0 && position == 0){
            c.previous = NULL;
            arr[position][i] = c;
            printf("Position: %d  |  Value: %d   |  Previous: %s \n", position, arr[position][i].value,"NULL");
            }else{
            c.previous = &arr[position][i-1];
            arr[position][i] = c;
            printf("Position: %d  |  Value: %d  |  Previous: %d     -    Value of previous box:%d\n", position, arr[position][i].value, &arr[position][i].previous, *arr[position][i].previous);
            };

        };

            printf("\nMemory of Array: %d   |   Memory of first box: %d   |   Size With Previous value: %d\n\n\n", &arr, &arr[0][0], sizeof(arr));
            printf("______________________________________________________________________________________________________________\n\n\n");

        // Without previous value   
        for(int i = 0;i < max; i++){

            value = 10*i;
            if(i == Y){
            position2 ++;
            arr[position2][i] = c;
            printf("Position: %d  |  Value: %d\n", position2, arr[position2][i].value);
            }else if(i == 0 && position2 == 0){
            c.previous = NULL;
            arr[position2][i] = c;
            printf("Position: %d  |  Value: %d   |  Previous: %s \n", position2, arr[position2][i].value,"NULL");
            }else{
            c.previous = &arr[position2][i-1];
            arr[position2][i] = c;
            printf("Position: %d  |  Value: %d  |  Previous: %d     -    Value of previous box:%d\n", position2, arr[position2][i].value);
            };

        };

        printf("\nMemory of Array: %d   |   Memory of first box: %d   |   Size without previous Value: %d\n\n\n", &arr3, &arr3[0][0], sizeof(arr3));

        printf("______________________________________________________________________________________________________________\n\n\n");

    }
    if(option == 2){

        system("clear");
        printf("\n\nComparison:\n\n");
        printf("2 values => box w/ 2 dimensions: %d bytes || %d bits\n", sizeof(arr), (sizeof(arr)*8));
        printf("1 value  => box traditional: %d bytes || %d bits\n", sizeof(arr2), (sizeof(arr2)*8));
        printf("1 value  => box w/ 2 dimensions: %d bytes || %d bits\n", sizeof(arr3), (sizeof(arr3)*8));
        printf("1 value  => box traditional: %d bytes || %d bits\n", sizeof(arr4), (sizeof(arr4)*8));

    };
}

int main(){

    printf("\n");
    run();
    
   
    return 0;
};