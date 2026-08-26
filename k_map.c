#include <stdio.h>

#define max_minterm 16

int power(int, int);
int max_powered_to_2(int);

void render(int, int);

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

    int max_powered = max_powered_to_2(largest_term_in_minterm); // Finding the maximum powered number to 2

    int x_matrix, y_matrix; //These Represent x,y Matrix Variables, (Here 0 = One Variable, 1= Two Varibales)

    if(max_powered%2 == 0){
        x_matrix = max_powered / 2;
        y_matrix = x_matrix;
    }
    else{
        x_matrix = max_powered / 2;
        y_matrix = x_matrix + 1;
    }

    printf("x: %d, y:%d \n", x_matrix, y_matrix);

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
    for(int i =0;;i++){
        if(max_number<=power(2,i)){
            return i+1;
        }
    }
}


