library ieee;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;

entity QuineM is
port(   F : in std_logic_vector(3 downto 0);
        S : out std_logic_vector(3 downto 0));
end QuineM ;

Arquitecture ArqQuineM of QuineM is
begin
    process(F)
    begin
        case F is
            --cuando: 000-
            when "0000" =>
                S <= "1";
            
            when "0001" =>
                S <= "1";
            --Cuando: 1-11
            when "1011" =>
                S <= "1";

            when "1111" =>
                S <= "1";

            --Cuando: 111-
            when "1110" =>
                S <= "1";
            when "1111" =>
                S <= "1";
        end case;
    end process;
end ArqQuineM ;