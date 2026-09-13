#include <stdio.h>

#define max_minterm 64

int power(int, int);
int max_powered_to_2(int);
int string_int_converter(char *, int);

void arrange_matrix(int x, int y, int main[x][y], int arr[]);
void render(int x, int y, int main[x][y]);
void grey_code_generator(int[],int,int);

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

    printf("Maxinum value : %d, Powerd by : %d \n", largest_term_in_minterm, max_powered);

    int x_matrix, y_matrix, x_matrix_mat, y_matrix_mat; //These Represent x,y Matrix Variables, (Here 0 = One Variable, 1= Two Varibales)

    if(max_powered%2 == 0){
        x_matrix = max_powered / 2;
        x_matrix_mat = x_matrix;
        if(x_matrix == 0){
            x_matrix = 1;
        }
        y_matrix = max_powered / 2;
        y_matrix_mat = y_matrix;
        if(y_matrix == 0){
            y_matrix = 1;
        }
    }
    else{
        x_matrix = max_powered / 2;
        x_matrix_mat = x_matrix;
        if(x_matrix == 0){
            x_matrix = 1;
        }
        else{
            y_matrix = (max_powered / 2) + 1;
            y_matrix_mat = y_matrix;
            if(y_matrix == 0){
                y_matrix = 1;
            }
        }
    }

    //Here the Matrix 2^n is split in 2^x_matrix & 2^y_matrix
    printf("X  : %d , Y : %d",power(2,x_matrix), power(2,y_matrix));
    
    //Declaring main matrix
    int main_matrix[power(2,x_matrix)][power(2,y_matrix)];

    //Creating a the binary row and colume array that corresponds to The Grey Code Rule
    int binary_row[power(2,x_matrix)],binary_col[power(2,y_matrix)];

    grey_code_generator(binary_row,power(2,x_matrix),++x_matrix);

    for(int i = 0; i < x_matrix; i++){
        printf("\n row : %d , %d\n",i,binary_row[i]);
    }
    
    arrange_matrix(power(2,x_matrix), power(2,y_matrix), main_matrix, min_term_values);
    render(power(2,x_matrix), power(2,y_matrix), main_matrix);

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

    //Assigning all values of the 2D matrix to 0
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

void grey_code_generator(int arr[],int limit, int length){
    //greycode generated as string
    

}

int string_int_converter(char *string, int size){
    //
}