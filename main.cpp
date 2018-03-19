/************************************************************
fisher yates法
	偏りをなくすため、回を追うごとに乱数範囲を狭めていくのがコツ
	http://www.fumiononaka.com/TechNotes/Flash/FN0212003.html
	
精度の高いrandom
	https://github.com/SJ-magic-study/study__rand/blob/master/main.cpp
************************************************************/
#include <stdio.h>

#include <stdlib.h>
#include <time.h>

/************************************************************
************************************************************/
void shuffle(int* data, int size);


/************************************************************
************************************************************/

/******************************
******************************/
int main(int argc, char** argv)
{
	/********************
	********************/
	if(argc < 2){
		printf("xxx.exe num_trys\n");
		return -1;
	}
	
	int num_trys = atoi(argv[1]);
	
	
	/********************
	********************/
	enum{
		SIZE_ARRAY = 10,
	};
	int data[SIZE_ARRAY];
	
	/********************
	********************/
	srand((unsigned int)time(NULL));
	
	for(int try_id = 0; try_id < num_trys; try_id++){
		printf("[%3d] ", try_id);
		
		for(int i = 0; i < SIZE_ARRAY; i++){
			data[i] = i;
		}
		
		shuffle(data, SIZE_ARRAY);
		
		for(int i = 0; i < SIZE_ARRAY; i++){
			printf("%3d", data[i]);
		}
		printf("\n");
	}
	
	return 0;
}


/******************************
description
	fisher yates法
	偏りをなくすため、回を追うごとに乱数範囲を狭めていくのがコツ
	http://www.fumiononaka.com/TechNotes/Flash/FN0212003.html
******************************/
void shuffle(int* data, int size)
{
	int i = size;
	
	while(i--){
		/********************
		int j = rand() % (i + 1);
		********************/
		int j = (int)( ((double)rand() / ((double)RAND_MAX + 1)) * (i + 1) );
		
		/********************
		********************/
		int temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
}
