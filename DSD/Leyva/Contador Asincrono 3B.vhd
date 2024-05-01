-- Contador Asincrono  de 3 bits
library ieee;
use ieee.std_logic_1164.all;

entity contador_3bits is
  port (
    entrada : in std_logic;
    salida : out std_logic_vector(2 downto 0)
  );
end contador_3bits;

architecture behavioral of contador_3bits is
  signal Q0 : std_logic;
  signal Q1 : std_logic;
  signal Q2 : std_logic;

begin
  -- Comportamiento del flip flop Q0
  Q0 <= not entrada;

  -- Comportamiento del flip flop Q1
  Q1 <= not (Q0 and entrada);

  -- Comportamiento del flip flop Q2
  Q2 <= not (Q1 and Q0);

  -- Salida del contador
  salida <= std_logic_vector(to_bitvector(Q2, 1) & to_bitvector(Q1, 1) & to_bitvector(Q0, 1));
end behavioral;
