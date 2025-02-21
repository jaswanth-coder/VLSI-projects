// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "E:/Tapped_FIR/FIR_Lab/fir.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "E:/Tapped_FIR/FIR_Lab/fir.cpp"

# 1 "E:/Tapped_FIR/FIR_Lab/fir.h" 1



const int N = 19;

typedef int coef_t;
typedef int data_t;
typedef int acc_t;

void fir (data_t *y, data_t x);
# 3 "E:/Tapped_FIR/FIR_Lab/fir.cpp" 2

void fir (data_t *y, data_t x){
 coef_t c[N] = {53, 0, -91, 213,112,0,313,500,213,313,0,-91,500,0,-91,313,0,-91,53};


 static data_t shift_reg[N];
   acc_t acc;
   int i;
   acc = 0;
Shift_Accum_Loop:for (i = N-1; i >= 0; i--){



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
#ifndef HLS_FASTSIM
#ifdef __cplusplus
extern "C"
#endif
void apatb_fir_ir(int *, int);
#ifdef __cplusplus
extern "C"
#endif
void fir_hw_stub(int *y, int x){
fir(y, x);
return ;
}
#ifdef __cplusplus
extern "C"
#endif
void apatb_fir_sw(int *y, int x){
apatb_fir_ir(y, x);
return ;
}
#endif
# 26 "E:/Tapped_FIR/FIR_Lab/fir.cpp"

