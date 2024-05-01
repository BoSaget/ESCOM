LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY Sumador IS
    PORT (a : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
          b : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		  reset: IN STD_LOGIC;
		  clk: IN STD_LOGIC;
          salida : OUT STD_LOGIC_VECTOR(4 DOWNTO 0));		  
END Sumador;

ARCHITECTURE Suma OF Sumador IS
BEGIN
    PROCESS (a, b, clk, reset)
    BEGIN
    	IF reset = '1' then
            salida <= "00000";

		ELSIF rising_edge(clk) then
			salida <= std_logic_vector('0' & UNSIGNED(a) + UNSIGNED(b));
		END IF;	
    END PROCESS;
END Suma;
