library ieee;
use ieee.std_logic_1164.all;

entity Cto is
port
(
	A: in std_logic;
    B: in std_logic;
    C: in std_logic;
    D: in std_logic;
    validado: out std_logic);
attribute pin_numbers of Cto: entity is
"A:1 B:2 C:3 D:4 validado:22";
end Cto;

architecture Examen1 of Cto is 
signal aux: std_logic_vector(3 downto 0);
signal NA: std_logic;
signal NB: std_logic;
begin
    process(A, B, C, D)
    begin
        NA <= not A;
        Nb <= not B;
        
        --A'BC
        aux(0) <= NA and B and C;

        --AB'C
        aux(1) <=  A and NB and C;

        --B'CD
        aux(2) <=  NB and C and D;

        --AB'D
        aux(3) <=  A and NB and D;

        --A’BC + AB’C + B’CD + AB’D

        validado <= aux(0) or aux(1) or aux(2) or aux(3);

        
    end process;
end architecture;