
def highest_power_limit_two_checker(max_value):
    x = 0
    while True:
        if(max_value == 1 or max_value == 0):
            return 1
        if(max_value < pow(2,x)):
            return x
        x = x + 1

def grey_code(length, bit_limit):
    result = []

    for i in range(length):
        curresponding_binary = f"{i:0{bit_limit}b}"
        grey = [curresponding_binary[0]]

        for j in range(len(curresponding_binary) - 1):
            xor_bit = int(curresponding_binary[j]) ^ int(curresponding_binary[j + 1])
            grey.append(str(xor_bit))

        result.append("".join(grey))
    return result

def check_binary(value):
    return int(value,2)

intial_stg_1_list = [] #Intial Stage 1 list containing the min term value

while True:
    main_input = input("Enter Minterms (enter empty to exit): ")
    if(main_input == ""):
        break
    else:
        try:
            intial_stg_1_list.append(int(main_input))

        except Exception as e:
            print(f"Error Occured : {e}")

#Highest Power Limit (2^n)
highes_power_of_two_limit = highest_power_limit_two_checker(max(intial_stg_1_list))
print(f"Highes Power 2^{highes_power_of_two_limit}")

# Next Step Includes creating the table, rows and columns. Well we have to basically create create a shift of the power of 2
# For this instance we create left rows less than columns for odd numbered situation or else we have equal rows and columns

col = 0
row = 0

if(highes_power_of_two_limit % 2 == 0):
    row = highes_power_of_two_limit / 2
    col = row
else:
    row = int(highes_power_of_two_limit / 2)
    col = row + 1

print(f"The Row And Colums , 2^{row} X 2^{col}")

#declaring the main matrix list
# NOTICE we have only 2 powered ow and colum vaue so inorder to create table exact 2 raised value

main_matrix_list = []
for _ in range(pow(2,row)):
    row_line = [0] * pow(2,col)
    main_matrix_list.append(row_line)

print(main_matrix_list)

#We also need to know the highet bit length of the row and colum, as be pair location with greycode, we have to reach exact locaion
row_binary_length = row
col_binary_length = col

#Creating a list of row and colum for corresponding grey code and bit length respectively

list_of_row_grey_code_seq = grey_code(pow(2,row), row_binary_length)
print(f"List of Grey Code row : {list_of_row_grey_code_seq}")

list_of_col_grey_code_seq = grey_code(pow(2,col), col_binary_length)
print(f"List of Grey Code Col : {list_of_col_grey_code_seq}")

#Filling the main matrix list with the curresponding greycode row and colm value

for i in range(len(list_of_row_grey_code_seq)):
    for j in range(len(list_of_col_grey_code_seq)):
        #We check the corresponging value 2d matrix index of greycode then check if that value exist in the initial stage matrix 
        curresposnding_value_of_location = check_binary(list_of_row_grey_code_seq[i]+list_of_col_grey_code_seq[j])
        if(curresposnding_value_of_location in intial_stg_1_list):
            main_matrix_list[i][j] = 1


print(main_matrix_list) # Completed the matrix appending with corresponding greycode value