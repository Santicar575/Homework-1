#include <iostream>

int** create_matrix(int n);
void print_matrix(int** matrix, int n);
void free_matrix(int** matrix, int n);

int main(){
    int n;
    std::cout<<"Ingrese el tamaño de la matriz: ";
    std::cin>>n;
    int** matrix = create_matrix(n);
    print_matrix(matrix,n);
    free_matrix(matrix,n);
    return 0;
}

int** create_matrix(int n){
    int** matrix = nullptr;
    try{
        matrix = new int*[n];
    }catch(std::bad_alloc){
        throw std::runtime_error("No hay memoria suficiente");
    }
    int curr = 1;
    int* line = nullptr;
    for(int i=0;i<n;i++){
        try{
            line = new int[n];
        }catch(std::bad_alloc){
            throw std::runtime_error("No hay memoria suficiente");
        }
        
        for(int j=0;j<n;j++){
            line[j] = curr;
            curr++;
        }
        matrix[i] = line;
    }
    return matrix;
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
    if(!matrix) return;
    for(int i = 0; i < n; i++){
        delete matrix[i];
        matrix[i] = nullptr;
    }
    delete matrix;
    matrix = nullptr;
}
