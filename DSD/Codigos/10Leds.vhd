library ieee;
use ieee.std_logic_1164.all;

entity LED is
	port(
		switch: in std_logic_vector(3 downto 0);
		leds: out std_logic_vector (9 downto 0)
	);
attribute pin_numbers of LED: entity is
"switch(3):1 switch(2):2 switch(1):3 switch(0):4 leds(9):23 leds(8):22 leds(7):21 leds(6):20 leds(5):19 leds(4):18 leds(3):17 leds(2):16 leds(1):15 leds(0):14";
end LED;

architecture ENCENDER of LED is
	begin
	process (switch)
		begin
			if (switch = "0001") then
				leds <= "0000000001";

			elsif (switch = "0010") then
				leds <= "0000000010";

			elsif (switch = "0011") then
				leds <= "0000000100";

			elsif (switch = "0100") then
				leds <= "0000001000";

			elsif (switch = "0101") then
				leds <= "0000100000";

			elsif (switch = "0110") then
				leds <= "0001000000";

			elsif (switch = "0111") then
				leds <= "0010000000";

			elsif (switch = "1000") then
				leds <= "0100000000";

			elsif (switch = "1001") then
				leds <= "1000000000";
			
			else
				leds <= "0000000000";

			end if;
	end process;
end ENCENDER;
