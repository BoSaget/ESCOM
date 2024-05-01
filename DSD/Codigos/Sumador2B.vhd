library ieee;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;

entity Sumador2B is
port
(
	A,B : in std_logic_vector(3 downto 0);
	Cin : in std_logic;
	Cout : out std_logic;
	S : out std_logic_vector(1 downto 0)
);
end Sumador2B;

architecture Suma2bits of Sumador2B is 

component SumadorCompleto
    port
    (
        A,B : in std_logic;
        Cin : in std_logic;
        Cout : out std_logic;
        S : out std_logic
    );
end component;

signal auxCout : std_logic;

begin 

FA1: SumadorCompleto Port map
(
    A => A(0),
    B => B(0),
    Cin => Cin,
    Cout => auxCout,
    S => S(0)
);

FA2: SumadorCompleto Port map
(
    A => A(1),
    B => B(1),
    Cin => auxCout,
    Cout => Cout,
    S => S(1)
);

end Suma2bits;