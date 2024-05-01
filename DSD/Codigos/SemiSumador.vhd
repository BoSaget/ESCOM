library ieee;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;


entity SemiSumador is
port
(
	A,B : in std_logic;
	Cout : out std_logic;
	S : out std_logic
);
end SemiSumador;

architecture SemiSuma of SemiSumador is 	
begin 
	process(A,B)
		begin
			if  A = '0' and B = '0' then
				S <= '0' ;
				Cout <= '0' ;

			elsif  A = '0' and B = '1' then
				S <= '1' ;
				Cout <= '0' ;
			
			elsif  A = '1' and B = '0' then
				S <= '1' ;
				Cout <= '0' ;
			
			elsif  A = '1' and B = '1'  then
				S <= '0' ;
				Cout <= '1' ;
			end if;
	end process;

end SemiSuma;