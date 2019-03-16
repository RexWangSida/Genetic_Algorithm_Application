#include "Generit_Algorithm_Application.h"
#include <stdio.h>
#include <math.h>

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
	double distance;
	double sum = 0;
	double r, g, b;
	double r_2, g_2, b_2;
	int reminder = image_size %2;
	int last = image_size - 1;
	if(reminder == 0){
		for(int i = 0; i < image_size; i+=2){
			r = A[i].r - B[i].r;
			g = A[i].g - B[i].g;
			b = A[i].b - B[i].b;
			r_2 = r*r;
			g_2 = g*g;
			b_2 = b*b ;
			sum += r_2 + g_2 + b_2;
			r = A[i+1].r - B[i+1].r;
			g = A[i+1].g - B[i+1].g;
			b = A[i+1].b - B[i+1].b;
			r_2 = r*r;
			g_2 = g*g;
			b_2 = b*b ;
			sum += r_2 + g_2 + b_2;
		}
	}
	else if(image_size == 1){
		r = A[last].r - B[last].r;
		g = A[last].g - B[last].g;
		b = A[last].b - B[last].b;
		r_2 = r*r;
		g_2 = g*g;
		b_2 = b*b ;
		sum += r_2 + g_2 + b_2;
	}
	else if(reminder == 1){
		for(int i = 0; i < image_size; i+=2){
			r = A[i].r - B[i].r;
			g = A[i].g - B[i].g;
			b = A[i].b - B[i].b;
			r_2 = r*r;
			g_2 = g*g;
			b_2 = b*b ;
			sum += r_2 + g_2 + b_2;
			r = A[i+1].r - B[i+1].r;
			g = A[i+1].g - B[i+1].g;
			b = A[i+1].b - B[i+1].b;
			r_2 = r*r;
			g_2 = g*g;
			b_2 = b*b ;
			sum += r_2 + g_2 + b_2;
		}
		r = A[last].r - B[last].r;
		g = A[last].g - B[last].g;
		b = A[last].b - B[last].b;
		r_2 = r*r;
		g_2 = g*g;
		b_2 = b*b ;
		sum += r_2 + g_2 + b_2;
	}
	distance = sqrt(sum);
	return distance;
}

void comp_fitness_population(const PIXEL *image, Individual * individual, int population_size){
	int i;
	int size = individual -> image.width * individual -> image.height;
	
	for(i = 0; i < population_size; i++){
		individual[i].fitness = comp_distance(individual[i].image.data, image, size);
		
	}
}
