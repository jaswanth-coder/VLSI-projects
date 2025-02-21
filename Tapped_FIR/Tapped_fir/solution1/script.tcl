############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Tapped_fir
set_top fir
add_files FIR_Lab/fir.cpp
add_files -tb FIR_Lab/fir_test.cpp
open_solution "solution1" -flow_target vivado
set_part {xcvu11p-flga2577-1-e}
create_clock -period 10 -name default
config_export -format ip_catalog -output E:/Tapped_FIR/fir.zip -rtl verilog
#source "./Tapped_fir/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all
export_design -rtl verilog -format ip_catalog -output E:/Tapped_FIR/fir.zip
