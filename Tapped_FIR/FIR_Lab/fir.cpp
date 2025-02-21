
#include "fir.h"

void fir (data_t *y, data_t x){
	coef_t c[N] = {53, 0, -91, 213,112,0,313,500,213,313,0,-91,500,0,-91,313,0,-91,53};


	static 	data_t shift_reg[N];
			acc_t acc;
			int i;
			acc = 0;
Shift_Accum_Loop:for (i = N-1; i >= 0; i--){
//#pragma HLS PIPELINE II = 1
//#pragma HLS array_partition variable=shift_reg type=block factor=4
//#pragma HLS unroll
			if (i==0) {
				acc += x * c[0];
				shift_reg[0] = x;
				}
			else {
				shift_reg[i] = shift_reg[i - 1];
				acc += shift_reg[i]*c[i];
				}
	}
	*y = acc;
	}





