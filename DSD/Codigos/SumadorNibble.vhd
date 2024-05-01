library ieee;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_1164.all;

entity SumadorNibble is
port
(
	A,B : in std_logic_vector(3 downto 0);
	Cin : in std_logic;
	Cout : out std_logic;
	S : out std_logic_vector(3 downto 0)
);
end SumadorNibble;

architecture Suma4bits of SumadorNibble is 

component SumadorCompleto
    port
    (
        A,B : in std_logic;
        Cin : in std_logic;
        Cout : out std_logic;
        S : out std_logic
    );
end component;

signal auxCout : std_logic_vector(2 downto 0);

begin 

FA1: SumadorCompleto Port map
(
    A => A(0),
    B => B(0),
    Cin => Cin,
    Cout => auxCout(0),
    S => S(0)
);

FA2: SumadorCompleto Port map
(
    A => A(1),
    B => B(1),
    Cin => auxCout(0),
    Cout => auxCout(1),
    S => S(1)
);

FA3: SumadorCompleto Port map
(
    A => A(2),
    B => B(2),
    Cin => auxCout(1),
    Cout => auxCout(2),
    S => S(2)
);

FA4: SumadorCompleto Port map
(
    A => A(3),
    B => B(3),
    Cin => auxCout(2),
    Cout => Cout,
    S => S(3)
);

end Suma4bits;