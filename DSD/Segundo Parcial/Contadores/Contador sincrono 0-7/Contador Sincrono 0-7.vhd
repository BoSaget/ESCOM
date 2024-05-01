library ieee;
use ieee.std_logic_1164.all;

entity Contador0_7 is
    port ( 
            T, CLK: in std_logic;
            Q, nQ: out std_logic_vector(2 downto 0) 
        );

end entity;

architecture Contador of Contador0_7  is
signal Taux: std_logic_vector (2 downto 0);
begin
    process(T, CLK)
    begin
        Taux(0) <= T;
        --FlipFlop1
        if (CLK = '0' and CLK'EVENT) then
            
            if (Taux(0) = '0') then
                Q(0) <= Taux(0);
                nQ(0) <= not Taux(0);

            elsif (Taux(0) = '1') then
                Q(0) <= not Taux(0);
                nQ(0) <= Taux(0);
            end if;

            Taux(1) <= Q(0);

            if (Taux(1) = '0') then
                Q(1) <= Taux(1);
                nQ(1) <= not Taux(1);

            elsif (Taux(1) = '1') then
                Q(1) <= not Taux(1);
                nQ(1) <= Taux(1);
            end if;

            Taux(2) <= Q(1);

            if (Taux(2) = '0') then
                Q(2) <= Taux(2);
                nQ(2) <= not Taux(2);

            elsif (Taux(2) = '1') then
                Q(2) <= not Taux(2);
                nQ(2) <= Taux(2);
            end if;

        end if;
    end process;
end architecture;