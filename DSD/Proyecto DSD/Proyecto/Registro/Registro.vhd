library ieee;
use ieee.std_logic_1164.all;

entity reg4 is
  port (
    d : in std_logic_vector(3 downto 0);
    clk : in std_logic;
    en : in std_logic;
    q : out std_logic_vector(3 downto 0)
  );
end reg4;

architecture Behavioral of reg4 is
  signal reg : std_logic_vector(3 downto 0);
begin
  process(clk)
  begin
    if rising_edge(clk) then
      if en = '1' then
        reg <= d;
      end if;
    end if;
  end process;

  q <= reg;
end Behavioral;

