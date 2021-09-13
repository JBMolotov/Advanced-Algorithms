#include <iostream>
#include <string.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct job {
    int duracao;
    int peso;
};

void swap(job *a, job *b) 
{ 
    job t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (job arr[], int low, int high) 
{ 
    job pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j].peso > pivot.peso) 
        { 
            i++; // increment index of smaller element 
            swap(arr[i], arr[j]);
        } else if (arr[j].peso == pivot.peso) {
            if (arr[j].duracao < pivot.duracao){
                i++;
                swap(arr[i], arr[j]);
            }
        }
    }
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 

void quickSort(job arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

/* Function to print an array */
void printArray(job arr[], int size) 
{ 
    // for (int i = 0; i < size; i++)
    //     cout << arr[i].duracao << " " << arr[i].peso << " " << endl; 

    int Cj = 0, total = 0;
    for (int i = 0; i < size; i++) {
        Cj += arr[i].duracao;
        total += (Cj * arr[i].peso);
    }

    cout << total << endl;
    
} 
  
void guloso() {
    int tam;
    
    job j[100];

    cin >> tam;

    for (int i = 0; i < tam; i++)
    {
        cin >> j[i].duracao;
        cin >> j[i].peso;
    }

    quickSort(j, 0, tam-1);    

    printArray(j, tam);
    
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        guloso();
    }
}

//Molotov