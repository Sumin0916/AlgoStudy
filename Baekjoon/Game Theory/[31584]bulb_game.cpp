#include<iostream>
//#include "bulb.h"

static int N;
static int sw[1010], bulb[1010], next_bulb[1010];

void Init(int n) {
	N = n;
}

int MakeTurn(int M) {
	int res=0; int max_bulb = -N;
	sw[M] = 1;
	for(int S=1; S<=N; S++){
		int ON = 0; int OFF = 0;
		for(int i=1; i<N; i++) next_bulb[i] = bulb[i];
		if(sw[S] == 1) continue;
		if(M <= S) for(int x=M; x<S; x++) next_bulb[x] = 1-next_bulb[x];
		else for(int x=S; x<M; x++) next_bulb[x] = 1-next_bulb[x];
		for(int i=1; i<N; i++){
			if(next_bulb[i]) ON++;
			else OFF++;
		}
		if(ON-OFF > max_bulb){
			max_bulb = ON-OFF;
			res = S;
		}
	}
	if(M <= res) for(int x=M; x<res; x++) bulb[x] = 1-bulb[x];
	else for(int x=res; x<M; x++) bulb[x] = 1-bulb[x];
	sw[res] = 1;
	return res;
}
