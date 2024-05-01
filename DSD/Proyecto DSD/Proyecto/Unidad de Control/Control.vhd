library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ControlUnit is
    Port ( clk : in STD_LOGIC;
           entrada : in STD_LOGIC_VECTOR(1 downto 0);
           start : in STD_LOGIC;
           carga : out STD_LOGIC;
		   suma : out STD_LOGIC;
		   resta : out STD_LOGIC;
		   swap : out STD_LOGIC);
end ControlUnit;

architecture Behavioral of ControlUnit is
begin
    process(clk)
    begin
        if rising_edge(clk) then
            if start = '1' then
                case entrada is
                    when "00" => --carga
                       carga <= '1';
					   suma <= '0';
					   resta <= '0';
					   swap <= '0';
                    when "01" => --suma
                       carga <= '0';
					   suma <= '1';
					   resta <= '0';
					   swap <= '0';
                    when "10" => --resta
                       carga <= '0';
					   suma <= '0';
					   resta <= '1';
					   swap <= '0';
                    when others => --swap
                       carga <= '0';
					   suma <= '0';
					   resta <= '0';
					   swap <= '1';
                end case;
            end if;
        end if;
    end process;
end Behavioral;
