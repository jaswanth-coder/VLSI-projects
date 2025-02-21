
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "fir.h"


//void generate_gold_output(FILE *fin, FILE *fout) {
//
//	int N=19;
//	const int   SAMPLES = 600;
//    coef_t c[N] = {53, 0, -91, 213, 112, 0, 313, 500, 213, 313, 0, -91, 500, 0, -91, 313, 0, -91, 53};
//
//
//    data_t input_buffer[N] = {0};
//
//    data_t x;
//    acc_t y;
//    int i, j;
//
//    for (i = 0; i < SAMPLES; i++) {
//
//
//        // Shift the delay line
//        for (j = N - 1; j > 0; j--) {
//            input_buffer[j] = input_buffer[j - 1];
//        }
//        input_buffer[0] = x;
//
//        // Calculate the FIR output using the general equation
//        y = 0;
//        for (j = 0; j < N; j++) {
//            y += input_buffer[j] * c[j];
//        }
//
//
//        fprintf(fout, "%d\n", y);
//    }
//}


int main () {
  const int   SAMPLES = 600;
  FILE   *fp, *fin;

  data_t signal, output;
  int i;
  int temp;

  signal = 0;




  fin=fopen("E:/Tapped_FIR/FIR_Lab/input.dat","r");
  fp=fopen("E:/Tapped_FIR/FIR_Lab/out.dat","w");
  //fgold = fopen("G:\\FIR_Lab\\Lab_files\\Lab6_FIR_Lab\\FIR_Lab\\out.gold.dat", "w");
  //Generate the output of FIR filter using general equation and saving it the out.gold.dat file .

  for (i=0;i<SAMPLES;i++) {
	fscanf(fin,"%d",&signal);
	printf("signal : %d\n",&signal);
	//Call the HLS block
    fir(&output,signal);
    // Save the results.
    fprintf(fp,"%d\n",output);
    printf("iteration : %i Signal: %d  output : %d\n",i,signal,output);
  }

  //generate_gold_output(fin, fgold);
  //fclose(fgold);
  fclose(fp);
  fclose(fin);

  //Comparing results with the golden output.

  printf ("Comparing against output data \n");
  temp=system("diff -w out.dat out.gold.dat");
  //printf("Temp value : %d\n",temp);

    if (temp) {
  	fprintf(stdout, "*******************************************\n");
  	fprintf(stdout,  "PASS: The output matches the golden output!\n");
  	fprintf(stdout, "*******************************************\n");
       return 0;
    } else {
  	fprintf(stdout, "*******************************************\n");
  	fprintf(stdout,"FAIL: Output DOES NOT match the golden output\n");
  	fprintf(stdout, "*******************************************\n");
       return 1;
    }

}

