#include <iostream>

//Declaracion de funciones
int** create_matrix(int n);
void print_matrix(int** matrix, int n);
void free_matrix(int** matrix, int n);

int main(){
    int n;
    std::cout << "Ingrese el tamaño de la matriz: "; // Solicita al usuario el tamaño de la matriz
    std::cin >> n; // Lee el tamaño de la matriz
    int** matrix = create_matrix(n); // Crea la matriz dinámica
    print_matrix(matrix, n); // Imprime la matriz
    free_matrix(matrix, n); // Libera la memoria asignada a la matriz
    return 0;
}

// Función para crear una matriz dinámica de tamaño n x n
int** create_matrix(int n){
    int** matrix = nullptr; 
    try{
        matrix = new int*[n]; // Reserva memoria para las filas de la matriz
    }catch(const std::bad_alloc&){
        throw std::runtime_error("No hay memoria suficiente"); // Manejo de error si no hay memoria
    }
    int curr = 1; // Variable para llenar la matriz con números consecutivos
    int* line = nullptr; // Puntero temporal para cada fila
    for(int i = 0; i < n; i++){
        try{
            line = new int[n]; // Reserva memoria para una fila de la matriz
        }catch(const std::bad_alloc&){
            throw std::runtime_error("No hay memoria suficiente"); // Manejo de error si no hay memoria
        }
        
        // Llena la fila con números consecutivos
        for(int j = 0; j < n; j++){
            line[j] = curr; // Asigna el valor actual
            curr++; // Incrementa el valor para el siguiente elemento
        }
        matrix[i] = line; // Asigna la fila a la matriz
    }
    return matrix; // Devuelve el puntero a la matriz
}

// Función para imprimir los elementos de la matriz
void print_matrix(int** matrix, int n){
    int x0 = n - 1, x1 = n - 1; // Inicializa los índices para recorrer la matriz desde el final
    for(int i = 0; i < (n * n); i++){ // Recorre todos los elementos de la matriz
        std::cout << "M[" << x0 << "][" << x1 << "] = " << matrix[x0][x1] << '\n'; // Imprime el elemento actual
        x1--; // Decrementa el índice de la columna
        if(x1 == -1){ // Si se llega al inicio de una fila
            x1 = n - 1; // Reinicia el índice de la columna al final
            x0--; // Pasa a la fila anterior
        }
    }
}


// Función para liberar la memoria asignada a la matriz
void free_matrix(int** matrix, int n){
    if(!matrix) return; // Si la matriz es nula, no hace nada
    for(int i = 0; i < n; i++){ // Recorre cada fila
        delete[] matrix[i]; // Libera la memoria de la fila
        matrix[i] = nullptr; // Establece el puntero de la fila a nullptr para evitar dangling pointers
    }
    delete[] matrix; // Libera la memoria de las filas
    matrix = nullptr; // Establece el puntero de la matriz a nullptr para evitar dangling pointers
}
