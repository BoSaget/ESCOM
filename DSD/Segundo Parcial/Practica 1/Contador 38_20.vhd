library ieee;
use ieee.std_logic_1164.all;

entity Contador38_20 is
    port ( 
            T, CLK: in std_logic;
            Q, nQ: out std_logic_vector(5 downto 0) 
        );

end entity;

architecture Contador of Contador38_20  is
signal auxCLK : std_logic_vector(5 downto 0);
signal auxT, auxCLR, auxSET : std_logic;
begin
    process(T, CLK, auxCLK, auxT, auxCLR, auxSET)
    begin
        auxCLK(0) <= CLK;
        --FlipFlop1
        if (auxCLK(0) = '0' and auxCLK(0)'EVENT) then
            
            if ( auxT <= '0') then
                Q(0) <= auxT;
                nQ(0) <= not auxT;

            elsif ( auxT = '1') then
                Q(0) <= not auxT;
                nQ(0) <= auxT;

            end if;

            auxCLK(1) <= Q(0);
            auxT <= nQ(0);

        end if;
    end process;
end architecture;