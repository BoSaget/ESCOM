library ieee;
use ieee.std_logic_1164.all;

entity Decodificador is
	port(
		dato: in std_logic_vector(3 downto 0);
		segmento: out std_logic_vector (6 downto 0)
	);
attribute pin_numbers of Decodificador: entity is
"segmento(0):23 segmento(1):22 segmento(2):21 segmento(3):20 segmento(4):19 segmento(5):18 segmento(6):17";
end Decodificador;

architecture Decodificar of Decodificador is
	begin
	process (dato)
		begin
			if (dato = "0000") then
				segmento <= "0111111";

			elsif (dato = "0001") then
				segmento <= "0000110";

            elsif (dato = "0010") then
				segmento <= "1011011";

            elsif (dato = "0011") then
				segmento <= "1001111";

            elsif (dato = "0100") then
				segmento <= "1100110";

            elsif (dato = "0101") then
				segmento <= "1101101";
            
            elsif (dato = "0110") then
				segmento <= "1111101";

            elsif (dato = "0111") then
				segmento <= "0000111";

            elsif (dato = "1000") then
				segmento <= "1111111";

            elsif (dato = "1001") then
				segmento <= "1101111";

            elsif (dato = "1010") then
				segmento <= "1110111";

            elsif (dato = "1011") then
				segmento <= "1111100";

            elsif (dato = "1100") then
				segmento <= "0111001";

            elsif (dato = "1101") then
				segmento <= "1011110";

            elsif (dato = "1110") then
				segmento <= "1111001";

            else
				segmento <= "1110001";

			end if;
	end process;
end Decodificar;

