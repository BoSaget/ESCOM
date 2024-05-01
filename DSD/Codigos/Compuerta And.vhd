library ieee;
use ieee.std_logic_1164.all;


entity Compuerta_And is
    port(
            entrada : in std_logic_vector(3 downto 0);
            salida : out std_logic
        );
end Compuerta_And;

architecture CAnd of Compuerta_And is
    begin
        process(entrada)
        begin
            if entrada = "1111" then
                salida <= '0';

            else
                salida <= '1';

            end if; 
        end process;
end CAnd; 