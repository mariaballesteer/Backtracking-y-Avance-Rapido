#include <iostream>

using namespace std;

struct Camisetas {
    string talla;
    int cantidad;
};
struct Empleado {
    string talla1;
    string talla2;
};

const int NUM_TALLAS = 6;
const int XS = 0;
const int S = 1;
const int M = 2;
const int L = 3;
const int XL = 4;
const int XXL = 5;

int n;
int m;

Camisetas camisetas[NUM_TALLAS]; //array para las camisetas que quedan

int generar(int nivel, int sol[]){
    return sol[nivel]+1; //avanza al siguiente hermano
}

bool criterio (int nivel, int sol[], Empleado empleados[]){
    bool seguir = false;
    string camisetaActual = camisetas[sol[nivel]].talla;
    if(camisetas[sol[nivel]].cantidad >= 0 && (empleados[nivel].talla1 == camisetaActual || empleados[nivel].talla2 == camisetaActual) && nivel < m) {
        
        seguir = true;
    }
        
    return seguir;
}

bool solucion(int nivel, int sol[], Empleado empleados[]){
    bool tieneSol = true;
    bool esSol = false;
    bool criterioVal = true;
    //bool camisetasRep = true;
    for(int i = 0; i < m; i++){ //busca que algún empleado no tenga camiseta todavía
        if(sol[i] == -1){
            tieneSol = false;
        }
    }
    for(int i = 0; i <= nivel; i++){
        if(!criterio(i,sol,empleados)){
            criterioVal = false;
        }
    }
    if(nivel == m-1 && tieneSol && criterioVal){ //si está en el último nivel, en el último empleado y todos los empleados tienen camiseta
        esSol = true;
    }
    return esSol;
}

bool masHermanos(int nivel, int sol[]){
    bool mas = false;
    if(sol[nivel] < NUM_TALLAS){ //comprueba que se pueda seguir con más hermanos por la derecha
        mas = true;
    }
    return mas;
}

void devolverCamiseta(int nivel, int sol[]){
    switch (sol[nivel]){ //devuelve la camiseta
        case XS:
            camisetas[XS].cantidad++;
            break;
        case S:
            camisetas[S].cantidad++;
            break;
        case M:
            camisetas[M].cantidad++;
            break;
        case L:
            camisetas[L].cantidad++;
            break;
        case XL:
            camisetas[XL].cantidad++;
            break;
        case XXL:
            camisetas[XXL].cantidad++;
            break;
        default:
                break;
        }
}

void imprimir(int fin, int nivel){
    if(nivel == -1 || !fin){
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}

void backTracking(Empleado empleados[], int n, int m){
    int nivel = 0;
    int sol[m];
    for(int i = 0; i < m; i++){
        sol[i] = -1;
    }
    bool fin = false;
    do{
        sol[nivel] = generar(nivel,sol);
        if(sol[nivel] < NUM_TALLAS){
            switch (sol[nivel]){
            case XS:
                camisetas[XS].cantidad--;
                break;
            case S:
                camisetas[S].cantidad--;
                break;
            case M:
                camisetas[M].cantidad--;
                break;
            case L:
                camisetas[L].cantidad--;
                break;
            case XL:
                camisetas[XL].cantidad--;
                break;
            case XXL:
                camisetas[XXL].cantidad--;
                break;
            default:
                break;
            }
        }
        if(nivel==m-1 && solucion(nivel,sol,empleados)){
            fin = true;
        }
        else if(criterio(nivel,sol,empleados)){
            nivel++;
        }
        else {
            while(nivel>=0 && !masHermanos(nivel, sol)){
                devolverCamiseta(nivel,sol);
                sol[nivel]=-1;
                nivel--;
            }
            if(nivel>=0){
                devolverCamiseta(nivel,sol);
            }
        }
    }while(!fin && nivel!=-1);
    
    imprimir(fin, nivel);
}

int main(){
    int P; //P -> número de casos de prueba; N -> múltiplo de 6 entre 1 y 36, número de camisetas; M -> número de voluntarios; N >= M
    cin >> P;
    while(P > 0){
        cin >> n >> m;
        // inicialización array
        int tallas = n/NUM_TALLAS;
        camisetas[XS].talla = "XS";
        camisetas[S].talla = "S";
        camisetas[M].talla = "M";
        camisetas[L].talla = "L";
        camisetas[XL].talla = "XL";
        camisetas[XXL].talla = "XXL";
        for(int i = 0; i < n; i++){
            camisetas[i].cantidad = tallas;
        }
        Empleado empleados[m];
        for(int i = 0; i < m; i++){
            cin >> empleados[i].talla1 >> empleados[i].talla2;
        }

        backTracking(empleados, n, m);
        P--;
    }
    return 0;
}