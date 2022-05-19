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

int *selection(int *v, int s){
    int pivo;
    for (int i = 0; i < s; ++i) {
        pivo=i;
        for (int j = i; j < s; ++j) {
            if(v[j]<v[pivo]){
                pivo=j;
            }
        }
        if(pivo!=i){
            troca(&v[i],&v[pivo]);
        }
    }

    return v;
}

int *merge(int *v, int s){


    return v;
}

int *merge_sorte(int *v, int s){
    int *esq,*dir;
    int tesq=((s/2)+(s%2)),tdir=(s/2);

    esq=(int*) malloc(sizeof(int*)*tesq);
    dir=(int*) malloc(sizeof(int*)*tdir);

    if(esq==NULL){
        exit(18);
    }

    if(dir==NULL){
        exit(18);
    }

    memcpy(esq,v,sizeof(int)*tesq);
    memcpy(dir,v+sizeof(int)*tesq,tdir);

}
