#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

PIXEL *generate_random_image(int width, int height, int max_color){
	srand(time(NULL));
	int random_size = height * width;	
	PIXEL * L = malloc((sizeof(PIXEL)) * random_size);
	
	for(int i = 0; i < random_size; i++){
			L[i].r = rand()%(max_color+1);
			L[i].g = rand()%(max_color+1);
			L[i].b = rand()%(max_color+1);
	}
	return L;
}

Individual *generate_population(int population_size, int width, int height, int max_color){
	Individual * q = malloc((sizeof(Individual)) * population_size);
	
	for(int i = 0; i < population_size; i++){
		 q[i].image.width = width;
		 q[i].image.height = height;
	     q[i].image.max_color = max_color;
		 q[i].image.data = generate_random_image(width, height, max_color);
	}
	return q;
}
