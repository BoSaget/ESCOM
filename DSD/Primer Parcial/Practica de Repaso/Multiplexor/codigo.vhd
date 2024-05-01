library ieee;
use ieee.std_logic_1164.all;

entity Multiplexor4_1 is
    port (
            control : in std_logic_vector(1 downto 0);
            entradas : in std_logic_vector(3 downto 0);
            salida : out std_logic            );
attribute pin_numbers of Multiplexor4_1: entity is
"control(1):1 control(0):2  entradas(3):8 entradas(2):9 entradas(1):10 entradas(0):11 salida:23";
end entity;

architecture Multiplexor of Multiplexor4_1 is
begin
    process(control, entradas)
    begin
        if control = "00" and entradas(0) = '0' then
            salida <= '0';
        
        elsif control = "00" and entradas(0) = '1' then
            salida <= '1';
        
        elsif control = "01" and entradas(1) = '0' then
            salida <= '0';
            
        elsif control = "01" and entradas(1) = '1' then
            salida <= '1';

        elsif control = "10" and entradas(2) = '0' then
            salida <= '0';
                
        elsif control = "10" and entradas(2) = '1' then
            salida <= '1';

        elsif control = "11" and entradas(3) = '0' then
            salida <= '0';
                
        elsif control = "11" and entradas(3) = '1' then
            salida <= '1';

        end if;
    end process;
end architecture;