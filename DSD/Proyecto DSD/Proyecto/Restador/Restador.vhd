library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Restador4Bits is
    Port ( A : in STD_LOGIC_VECTOR(3 downto 0);
           B : in STD_LOGIC_VECTOR(3 downto 0);
           BorrowIn : in STD_LOGIC;
           Difference : out STD_LOGIC_VECTOR(3 downto 0);
           BorrowOut : out STD_LOGIC);
end Restador4Bits;

architecture Behavioral of Restador4Bits is
begin
    process (A, B, BorrowIn)
        variable TempDifference : STD_LOGIC_VECTOR(4 downto 0);
    begin
        TempDifference := (others => '0');
        for i in 0 to 3 loop
            TempDifference(i) := A(i) xor B(i) xor BorrowIn;
            BorrowIn <= (not A(i) and B(i)) or ((not A(i) xor B(i)) and BorrowIn);
        end loop;
        Difference <= TempDifference(3 downto 0);
        BorrowOut <= not BorrowIn;
    end process;
end Behavioral;