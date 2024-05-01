library IEEE;
use IEEE.std_logic_1164.all;


entity Compuerta_Or is

    port(
            entrada : in std_logic_vector(3 downto 0);
            salida : out std_logic
        );

end Compuerta_Or;

architecture COr of Compuerta_Or is

 begin
    process(entrada)
    begin
        if entrada = "0000" then
            salida <= '0';

        else
            salida <= '1';

        end if; 
    end process;
end COr; 