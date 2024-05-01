library ieee;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;

entity SumadorCompleto is
port
(
	A,B : in std_logic;
	Cin : in std_logic;
	Cout : out std_logic;
	S : out std_logic
);
end SumadorCompleto;

architecture Suma of SumadorCompleto is 

component SemiSumador
port
(
    A,B : in std_logic;
	Cout : out std_logic;
    S : out std_logic
);
end component;

signal auxCout : STD_LOGIC_VECTOR (1 downto 0);
signal auxS : STD_LOGIC;

begin 

HA1: SemiSumador Port map
(
    A => A,
    B => B,
    Cout => auxCout(1),
    S => auxS
);

HA2: SemiSumador Port map
(
    A => auxS,
    B => Cin,
    Cout => auxCout(0),
    S => S
);

Cout <= auxCout(0) xor auxCout(1);

end Suma;