#include "Generit_Algorithm_Application.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp(const void *a, const void *b) { 
	return (*(Individual *)a).fitness  > (*(Individual *)b).fitness ? 1: -1; 
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate){
	
	Individual *p;
	p = generate_population(population_size, image -> width, image -> height, image -> max_color);
	
	
	comp_fitness_population(image -> data, p, population_size);
	
	qsort(p, population_size, sizeof(*p), cmp);
	
	for(int generation = 0; generation < num_generations; generation++){
		crossover(p, population_size);
		mutate_population(p, population_size, rate);
		comp_fitness_population(image -> data, p, population_size);
		qsort(p, population_size, sizeof(*p), cmp);
    }
	PPM_IMAGE *L = malloc(sizeof(PPM_IMAGE));
	L -> width = p[0].image.width;
	L -> height = p[0].image.height;
	L -> max_color = p[0].image.max_color;
	L -> data = p[0].image.data;

	for(int i = 1; i < population_size; i++){
		
		free(p[i].image.data);
	}
	free(p);
	return L;
	
}

void free_image(PPM_IMAGE *p){
	free(p->data);
	free(p);
}
