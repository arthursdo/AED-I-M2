//
// Created by arthur on 19/05/22.
//

#include "sort.h"

int *insertion(int *v, int s) {
    int pivo, j;
    for (int i = 1; i < s; ++i) {
        pivo = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > pivo) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = pivo;
    }
    return v;
}

int *selection(int *v, int s) {
    int pivo;
    for (int i = 0; i < s; ++i) {
        pivo = i;
        for (int j = i; j < s; ++j) {
            if (v[j] < v[pivo]) {
                pivo = j;
            }
        }
        if (pivo != i) {
            troca(&v[i], &v[pivo]);
        }
    }

    return v;
}

int *merge(int *esq, int *dir, int s) {

    int t1 = s / 2;
    int t2 = s - t1;

    int *v = (int *) malloc(sizeof(int) * (t1 + t2));
    if (v == NULL) {
        exit(16);
    }

    int i, j, k;

    for (i = 0, j = 0, k = 0; i < t1 && j < t2; k++) {
        if (esq[i] <= dir[j]) {
            v[k] = esq[i++];
        } else {
            v[k] = dir[j++];
        }
    }

    while (i < t1) {
        v[k++] = esq[i++];
    }
    while (j < t2) {
        v[k++] = dir[j++];
    }

    return v;
}

int *mergeSorte(int *v, int s) {
    if (s == 1) {
        return v;
    }

    int t1 = s / 2;
    int t2 = s - t1;


    int *esq = (int *) malloc(t1 * sizeof(int));
    int *dir = (int *) malloc(t2 * sizeof(int));
    if (esq == NULL)
        exit(17);
    if (dir == NULL)
        exit(18);

    int *s1 = esq, *s2 = dir;
    esq = mergeSorte(v, t1);
    dir = mergeSorte(&v[t1], t2);

    v = merge(esq, dir, t1 + t2);

    free(s1);
    free(s2);

    return v;
}

int *quickSort(int *v, int s) {

    int pivo = rand() % s,i=0,j=s;
    while (i<=j) {
        while (v[i]<v[pivo]&& i < s){
            i++;
        }
        while (v[j]>v[pivo]&&j>0){
            j--;
        }
        if(i<=j){
            troca(&v[i++],&v[j--]);
        }
    }
    if(j>0){
        quickSort(v, j + 1);
    }
    if(i < s){
        quickSort(&v[i], s-i);
    }
    return v;
}