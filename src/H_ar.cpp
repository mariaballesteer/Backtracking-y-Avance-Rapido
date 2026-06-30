#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

struct Tarea {
    int tarea;
    int tiempo;
};

struct Solucion {
    int tarea;
    int maquina;
};

bool comparador(const Tarea& a, const Tarea& b) { //Criterio de organizacion de vector
    return a.tiempo < b.tiempo;
}

int esFactible(vector<int> tiempoMaq, vector<int> indices, int j, int maq, float tiempoTarea, vector<vector<Tarea>>tiempos){
    int fac = 0;
    if(tiempoMaq[j]+tiempos[j][indices[j]].tiempo < tiempoMaq[maq]+tiempoTarea){
        fac = 1;
    }
    if(tiempoMaq[j]+tiempos[j][indices[j]].tiempo == tiempoMaq[maq]+tiempoTarea){
        fac = 2;
    }
    return fac;
}

void avanceRapido(vector<vector<Tarea>> tiempos, int N, int M){

    //vector para tiempo (total actual) de las máquinas
    vector<int> tiempoMaq(M);
    //vector booleano para los usos de las tareas, falsae -> no usado
    vector<bool> candidatos(N);
    //vector de struct nuevo para guardar la solución, nº tarea, nº maquina
    vector<Solucion> solucion(N);
    //vector que lleva los índices de cada máquina, por qué hueco va de cada máquina
    vector<int> indices(M);

    for(int i = 0; i < N; i++){
        float tiempoTarea = INFINITY;
        int maq = 0;
        int tarea = i;
            for(int j = 0; j < M; j++){
                while(indices[j] < N && candidatos[tiempos[j][indices[j]].tarea-1]){
                    indices[j]++;
                }
                
                if(!candidatos[tiempos[j][indices[j]].tarea-1]){
                    int fac = esFactible(tiempoMaq,indices,j,maq,tiempoTarea,tiempos);
                    if(fac == 1){
                        tiempoTarea = tiempos[j][indices[j]].tiempo;
                            
                        maq = j;
                            
                        tarea = tiempos[j][indices[j]].tarea-1;
                        
                    }
                    else if(fac == 2){
                        if(tiempoMaq[j]<=tiempoMaq[maq]){
                            tiempoTarea = tiempos[j][indices[j]].tiempo;
                            maq = j;
                            tarea = tiempos[j][indices[j]].tarea-1;
                        }
                    }
                }
        }
        // guardar datos "finales"
        candidatos[tarea] = true;
        tiempoMaq[maq] += tiempoTarea;
        Solucion sol;
        sol.maquina = maq;
        sol.tarea = tarea; 
        solucion[i] = sol;
        indices[maq]++; 

    }

    // imprimir
    int tiempoTotal = -1;

    for(int i = 0; i < M; i++){
        if(tiempoMaq[i] > tiempoTotal){
            tiempoTotal = tiempoMaq[i];
        }
    }

    cout << tiempoTotal << endl;

    for(int i = 0; i < N; i++){
        cout << solucion[i].tarea+1 << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        cout << solucion[i].maquina+1 << " ";
    }
    cout << endl;
    return;
}

int main()
{
    //Variables
    int P,N,M; //P -> número de casos; N -> número de tareas; M -> número de máquinas
    cin >> P;
    while(P>0){
        cin >> N >> M;
        //podemos considerar que los tiempos que se van a guardar son los pesos de las opciones
        vector<vector<Tarea>> tiempos(M,vector<Tarea>(N)); //filas columnas
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> tiempos[j][i].tiempo; //tiempo que tarda la tarea en la máquina
                tiempos[j][i].tarea = i+1; //meter el dato leído en la tabla
            }
        }
        for(int i = 0; i < M; i++){
                sort(tiempos[i].begin(),tiempos[i].end(),comparador);
        }

        avanceRapido(tiempos, N, M);
        P--;
    }
   

    return 0;
}