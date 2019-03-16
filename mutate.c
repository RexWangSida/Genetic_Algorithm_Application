#include "Generit_Algorithm_Application.h"
#include <stdio.h>
#include <stdlib.h>

void mutate(Individual *individual, double rate){
	int n = individual -> image.width * individual -> image.height; //size of image
	int t;
	int mutate_rate;
	mutate_rate = (int)(rate/100 * n);
	int max_c = (individual -> image.max_color) + 1;
	for(int i = 0; i < mutate_rate; i++){
		t = rand()%(n+1);
		individual -> image.data[t].r = rand()%max_c;
		individual -> image.data[t].g = rand()%max_c;
		individual -> image.data[t].b = rand()%max_c;
		
	}	
}

void mutate_population(Individual *individual, int population_size, double rate){
	int index = population_size/4;
	
	for(int i = index; i < population_size; i++){
		mutate(individual + i, rate);
	}
}
