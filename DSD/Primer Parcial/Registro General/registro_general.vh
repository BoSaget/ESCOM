module registro ( 
	clk,
	clr,
	control,
	d,
	q
	) ;

input  clk;
input  clr;
input [1:0] control;
input [2:0] d;
inout [2:0] q;
