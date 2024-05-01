-- Contador Sincrono  de 3 bits
library ieee;
use ieee.std_logic_1164.all;

entity contador_3_bits is
  port (
    clk : in std_logic;
    reset : in std_logic;
    enable : in std_logic;
    q : out std_logic_vector(2 downto 0)
  );
end contador_3_bits;

architecture behavioral of contador_3_bits is

  signal q_int : std_logic_vector(2 downto 0);

begin

  process (clk, reset)
  begin
    if reset = '1' then
      q_int <= (others => '0');
    elsif clk'event and clk = '1' then
      if enable = '1' then
        q_int <= q_int + 1;
      end if;
    end if;
  end process;

  q <= q_int;

end behavioral;
