#include "Generit_Algorithm_Application.h"
#include <stdlib.h>
#include <stdio.h> 

PPM_IMAGE *read_ppm(const char *file_name){

	PPM_IMAGE *PMM;
	FILE * input;
		
	/* read the PPM_File */
	input = fopen(file_name, "r");
	PMM = malloc(sizeof(PPM_IMAGE));
	
	/* get the width height and max_color */
	fscanf(input, "P3\n%d %d", &PMM -> width, &PMM -> height);
	fscanf(input, "%d", &PMM->max_color);
	
	/* get the data and form an array */
	int size = (PMM -> height * PMM -> width);
	PMM -> data = malloc(sizeof(PIXEL) * size);
	for(int i = 0; i < size; i++){
		
		fscanf(input, "%hhd %hhd %hhd", &(PMM -> data + i) -> r, &(PMM -> data + i) -> g, &(PMM -> data + i) -> b);	
		
	}
	fclose(input);
	return PMM;
}

void write_ppm(const char *file_name, const PPM_IMAGE *image){
	FILE *input = fopen(file_name, "w");
	
	
	fprintf(input, "P3\n%d %d\n%d\n", image ->width, image -> height, image -> max_color);
	
	int row = image -> width;
	int size = image -> height * image -> width;
	for(int i = 1; i < size + 1 ; i++){
		fprintf(input, "%d %d %d ", (image -> data + (i - 1)) -> r, (image -> data + (i - 1)) -> g, (image -> data + (i -1)) -> b);
		
		if((i % row) == 0){
		fprintf(input, "\n");
		}
	}
	fclose(input);
}

