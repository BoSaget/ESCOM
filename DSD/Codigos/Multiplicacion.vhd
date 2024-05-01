library IEEE;
use IEEE.std_logic_1164.all;

--P0 y p1 medio sumador
--p2 y p3
entity Multiplicador is
port
(
    a : in std_logic_vector(1 downto 0);
    b : in std_logic_vector(1 downto 0);
    p: out std_logic_vector(3 downto 0)
);

end Multiplicador;

architecture Multiplicacion of Multiplicador is
component SemiSumador
port
(
    A,B : in std_logic;
	Cout : out std_logic;
    S : out std_logic
);
end component;

component SumadorCompleto
port
(
	A,B : in std_logic;
	Cin : in std_logic;
	Cout : out std_logic;
	S : out std_logic
);
end component;

signal auxCout, auxCin: STD_LOGIC;

begin
S1: SemiSumador Port map
(
    A => a(0) and b(0),
    B => '0',
    Cout => auxCout,
    S => p(0)
);

S2: SemiSumador Port map
(
    A => a(1) and b(0),
    B => a(0) and b(1),
    Cout => auxCout,
    S => p(1)
);

S3: SumadorCompleto Port map
(
    A => auxCout,
    B => a(1) and b(1),
    Cin => auxCin,
    Cout => auxCout,
    S => p(2)
);

p(3) <= auxCout;

end Multiplicacion; 