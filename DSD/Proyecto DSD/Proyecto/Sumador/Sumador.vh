module sumador ( 
	a,
	b,
	reset,
	clk,
	salida
	) ;

input [3:0] a;
input [3:0] b;
input  reset;
input  clk;
inout [4:0] salida;
