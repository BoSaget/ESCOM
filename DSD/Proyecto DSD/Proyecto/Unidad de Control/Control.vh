module controlunit ( 
	clk,
	entrada,
	start,
	carga,
	suma,
	resta,
	swap
	) ;

input  clk;
input [1:0] entrada;
input  start;
inout  carga;
inout  suma;
inout  resta;
inout  swap;
