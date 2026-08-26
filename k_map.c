#include <stdio.h>

#define max_minterm 16

int power(int, int);
int max_powered_to_2(int);

void arrange_matrix(int x, int y, int main[x][y], int arr[]);
void render(int x, int y, int main[x][y]);

int main(){
    int min_term_values[max_minterm] = {0};
    int largest_term_in_minterm = 0;

    while(true){
        printf("Enter index of exisiting minterm (max: %d) : ",max_minterm);

        int num;
        scanf("%d", &num);

        if(num < max_minterm && num>=0){
            min_term_values[num] = 1;
            if(num > largest_term_in_minterm){
                largest_term_in_minterm = num;
            }
        }
        else{
            break;
        }
    }

    int max_powered = max_powered_to_2(largest_term_in_minterm+1); // Finding the maximum powered number to 2

    printf("Maxinum value : %d, Powerd by : %d", largest_term_in_minterm, max_powered);

    int x_matrix, y_matrix; //These Represent x,y Matrix Variables, (Here 0 = One Variable, 1= Two Varibales)

    if(max_powered%2 == 0){
        x_matrix = max_powered / 2;
        if(x_matrix == 0){
            x_matrix = 1;
        }
        y_matrix = x_matrix;
    }
    else{
        x_matrix = max_powered / 2;
        if(x_matrix == 0){
            x_matrix = 1;
            y_matrix = x_matrix;
        }
        else{
            y_matrix = x_matrix + 1;
        }
    }
    x_matrix = x_matrix * 2;
    y_matrix = y_matrix * 2;

    printf("X  : %d , Y : %d",x_matrix, y_matrix);

    int main_matrix[x_matrix][y_matrix];
    
    arrange_matrix(x_matrix, y_matrix, main_matrix, min_term_values);
    render(x_matrix, y_matrix, main_matrix);

}

int power(int main_number, int powered_to){ //powering function
    if(powered_to == 0){
        return 1;
    }
    else{
        int powered_output = 1;
        for(int i = 0; i<powered_to; i++){
            powered_output = powered_output * main_number;
        }
        return powered_output;
    }
}

int max_powered_to_2(int max_number){
    for(int i=0;;i++){
        if(max_number == 0 || max_number == 1){
            return 1;
        }
        if(max_number<=power(2,i)){
            return i;
        }
    }
}

void arrange_matrix(int x, int y, int main[x][y], int arr[]){
    printf("\n");
    for(int i = 0; i<x; i++){
        for(int j = 0; j<y; j++){
            main[i][j] = 0;
        }
    }
}

void render(int x, int y, int main[x][y]){
    for(int i = 0; i<x; i++){
        for(int j = 0; j<y; j++){
            printf("%d \t",main[i][j]);
        }
        printf("\n");
    }
}

