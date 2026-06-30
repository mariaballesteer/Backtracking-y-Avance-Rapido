# Optimización Algorítmica: Avance Rápido y Backtracking

Proyecto de análisis y desarrollo desarrollado en C++ como parte de la asignatura **Algorítmos y Estructuras de Datos** del Grado en Ingeniería Informática.

**Autoras:** María Ballester Martínez y Lucía Olmos Martínez  
**Cuenta de prácticas:** G1_07  
**Fecha:** Mayo de 2024

---

## Descripción del Proyecto

Este repositorio reúne la resolución eficiente de dos problemas complejos de optimización y asignación combinatoria de recursos, empleando dos enfoques algorítmicos fundamentales:

### 1. Problema de Asignación de Tareas (Avance Rápido)
- **Fichero:** `src/H_ar.cpp`
- **Objetivo:** Planificar y distribuir de forma óptima un conjunto de $N$ tareas independientes en $M$ máquinas que operan en paralelo. El algoritmo implementa una heurística ágil que minimiza el tiempo total de finalización (*makespan*) buscando equilibrar de forma equitativa la carga de trabajo en cada procesador.

### 2. Problema de Reparto de Camisetas (Backtracking)
- **Fichero:** `src/L_bt.cpp`
- **Objetivo:** Resolver una asignación exacta de un stock limitado de camisetas de 6 tallas diferentes (`XS` a `XXL`) entre un conjunto de $M$ voluntarios. Cada voluntario especifica exactamente dos opciones de talla aceptables. El algoritmo explota el espacio de estados mediante una búsqueda estructurada en árbol utilizando funciones de poda para descartar ramas inviables prematuramente.

---

## Características Técnicas

- **Diseño de Heurísticas:** Estrategia ágil y voraz de ordenación previa para el problema de máquinas independientes.
- **Estructuras de Árbol Exploratorias:** Modelado exhaustivo del espacio de soluciones mediante backtracking interactivo/recursivo.
- **Estudio Teórico y Experimental:** Validación de curvas asintóticas y contraste del comportamiento temporal ante casos óptimos y de peor caso simulados por software.

---

## Estructura del repositorio

```bash
├── doc/
│   └── Memoria práctica 2.pdf renombrado
├── src/
│   ├── H_ar.cpp
│   └── L_bt.cpp    
└── README.md
```

---

## Requisitos y Compilación

Para compilar y ejecutar cualquiera de los módulos del sistema, se requiere un compilador compatible con el estándar moderno de C++ (como `g++`).
