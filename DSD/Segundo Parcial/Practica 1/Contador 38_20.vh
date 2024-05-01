module contador ( 
	clk,
	reset,
	count_o,
	end_o
	) ;

input  clk;
input  reset;
inout [7:0] count_o;
inout  end_o;
