#include <iostream>

int** create_matrix(int n){
    int** matriz = (int**)calloc(n,sizeof(int*));
    int curr = 1;
    for(int i=0;i<n;i++){
        int* line = (int*)calloc(n,sizeof(int));
        for(int j=0;j<n;j++){
            line[j] = curr;
            curr++;
        }
        matriz[i] = line;
    }
    return matriz;
}

void print_matrix(int** matrix, int n){
    int x0=n-1,x1=n-1;
    for(int i = 0; i < (n*n); i++){
        std::cout<<"M["<<x0<<"]["<<x1<<"] = "<<matrix[x0][x1]<<'\n';
        x1--;
        if(x1 == -1){
            x1 = n - 1;
            x0--;
        }
    }
}

void free_matrix(int** matrix, int n){
    for(int i = 0; i < n; i++){
        free(matrix[i]);
    }
    free(matrix);
}

int main(){
    int n;
    std::cout<<"Ingrese el tamaño de la matriz: ";
    std::cin>>n;
    int** matrix = create_matrix(n);
    print_matrix(matrix,n);
    free_matrix(matrix,n);
    return 0;
}