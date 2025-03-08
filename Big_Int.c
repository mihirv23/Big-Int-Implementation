#include<stdio.h>
#include<string.h>


typedef enum{FALSE,TRUE} boolean ;
boolean OverFlowCheck(char[]);

char* reverse(char str1[]){
    int left , right ;
    char temp ;
    left = 0 ;
    right = strlen(str1) - 1;
  
    while(left < right){
        temp = str1[left] ;
        str1[left] = str1[right] ;
        str1[right] = temp ;
        left ++ ;
        right --;
    }

    return str1;
}

char* add(char str1[] , char str2[]){

    int int_index_value1;
    int int_index_value2;
    int int_index_res;
    int carry = 0;
    char  final_value;
    static char str_res[309]; // 2 morefor /0 and carry
    char* a , *b ; // same as a[] and b[]

    a = reverse(str1);
    b = reverse(str2);

    int i = 0;
    while (i < strlen(str1) || i < strlen(str2) || carry) {
        int int_index_value1 = (i < strlen(str1)) ? (a[i] - '0') : 0;
        int int_index_value2 = (i < strlen(str2)) ? (b[i] - '0') : 0;

        int int_index_res = int_index_value1 + int_index_value2 + carry;
        carry = int_index_res / 10;
        str_res[i] = (int_index_res % 10) + '0';
        // here i could also have done dma in which i wont have to consider the case of static
        i++;
    }
    
    str_res[i] = '\0'; 

    if(strlen(str_res) < 309){
        return reverse(str_res);
    }
    else if(strlen(str_res) > 309){
        return "Overflow";
    }
    else{
        if(OverFlowCheck(str_res)){
            return "Overflow";
        }
        else{
            return reverse(str_res);
        }
    }
     // grave error locally defined array ko return kaise kar sakta hai 
    // either static use kar nahi toh dynamically memory allocate kiya kar 
    

}


char* subtract(char str1[], char str2[]) {
    int borrow = 0;
    int greater;
    int flag = 0;
    static char str_final[310];
  
    
   
    char *a, *b;

    // Determine which number is greater
    if (strlen(str1) == strlen(str2)) {
        int i = 0;
        while (flag == 0 && i < strlen(str1)) {
            if ((str1[i] - '0') != (str2[i] - '0')) {
                flag = 1;
                greater = (str1[i] - '0') > (str2[i] - '0') ? 1 : 2;
            }
            i++;
        }
        if (flag == 0) {
            // Both numbers are equal
            str_final[0] = '0';
            str_final[1] = '\0';
            return str_final;
        }
    } else {
        greater = strlen(str1) > strlen(str2) ? 1 : 2;
    }

    
    a = reverse(str1);
    b = reverse(str2);

    int i = 0;
    if (greater == 1) {
        // str1 is greater
        while (i < strlen(str1) || i < strlen(str2) || borrow) {
            int int_index_value1 = (i < strlen(str1)) ? (a[i] - '0') : 0;
            int int_index_value2 = (i < strlen(str2)) ? (b[i] - '0') : 0;

            int k = int_index_value1 - int_index_value2 + borrow;
            if (k < 0) {
                str_final[i] = k + 10 + '0';
                borrow = -1;
            } else {
                str_final[i] = k + '0';
                borrow = 0;
            }
            i++;
        }
    } 
    else {
        // str2 is greater
        while (i < strlen(str1) || i < strlen(str2) || borrow) {
            int int_index_value1 = (i < strlen(str1)) ? (a[i] - '0') : 0;
            int int_index_value2 = (i < strlen(str2)) ? (b[i] - '0') : 0;

            int k = int_index_value2 - int_index_value1 + borrow;
            if (k < 0) {
                str_final[i] = k + 10 + '0';
                borrow = -1;
            } else {
                str_final[i] = k + '0';
                borrow = 0;
            }
            i++;
        }
    }
    while (i > 1 && str_final[i - 1] == '0') {
        i--;
    }

    str_final[i] = '\0';

    if(strlen(str_final) < 309){
        return reverse(str_final);
    }
    else if(strlen(str_final) > 309){
        return "Overflow";
    }
    else{
        if(OverFlowCheck(str_final)){
            return "Overflow";
        }
        else{
            return reverse(str_final);
        }
    }

    
}

char* multiply(char str1[], char str2[]) {
    int value_str1, value_str2, res_value, carry;
    char temp_str[700];  // Temporary string for intermediate results
    static char fin_res[700] = "0"; 
    memset(fin_res, 0, sizeof(fin_res)); // new concept learnt which helps to clear the buffer 
    char *a, *b;

   
    a = reverse(str1);
    b = reverse(str2);

    
    for (int i = 0; i < strlen(b); i++) {
       
        int k = 0; // Index for temp_str

        
        for (int z = 0; z < i; z++) {
            temp_str[k++] = '0';
        } // helps to add zeroes at end during intermediate multplication steps 

        carry = 0;
        for (int j = 0; j < strlen(a); j++) {
            value_str1 = a[j] - '0'; 
            value_str2 = b[i] - '0'; 

            // Multiply and add carry
            res_value = (value_str1 * value_str2) + carry;

            temp_str[k++] = (res_value % 10) + '0'; 
            carry = res_value / 10;                
        }

        // Handle any remaining carry after the inner loop
        if (carry > 0) {
            temp_str[k++] = carry + '0'; 
        }
        temp_str[k] = '\0'; 
        char* reversed_temp = reverse(temp_str);
        strcpy(fin_res, add(fin_res, reversed_temp));
    }
    if(strlen(fin_res) < 309){
        return fin_res;
    }
    else if(strlen(fin_res) > 309){
        return "Overflow";
    }
    else{
        if(OverFlowCheck(fin_res)){
            return "Overflow";
        }
        else{
            return fin_res;
        }
    }
}

boolean OverFlowCheck(char str[]){
    char str2[310];
    boolean b;
    FILE* fp;
    fp = fopen("string_input.txt","r");
    if(fp != NULL){
        
        fscanf(fp,"%s",str2);
        fclose(fp);
        
    }
    if(strcmp(str,str2) > 0){
        
        b = TRUE;
    }
    else{
        b = FALSE;
    }
    return b;
}

int main(){
    char str1[309];
    char str2[309];
    
    printf("Input the first number: \n");
    scanf("%s",str1);
    printf("Input the second number: \n");
    scanf("%s",str2);
    if((strlen(str1) == 309 ) || (strlen(str2) == 309)){
        if(OverFlowCheck(str1)){
            printf("Overflow occured \n");
        }
        else{
            
            // printf("Addition ans is %s \n", add(str1,str2));
            // printf("Subtraction ans is %s \n", subtract(str1,str2));
            
            printf("Multiplication result is %s \n",multiply(str1,str2));
        }
    }
    else if((strlen(str1) > 309) ||(strlen(str2) > 309)){
        printf("Overflow  occured \n");
    }
    else{
        
        // printf("Addition ans is %s \n", add(str1,str2));
        // printf("Subtraction ans is %s \n", subtract(str1,str2));
        
        printf("Multiplication result is %s \n",multiply(str1,str2));
        

    }
    return 0;
}
