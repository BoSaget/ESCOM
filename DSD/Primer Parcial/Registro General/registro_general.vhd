library ieee;
use ieee.std_logic_1164.all;

entity Registro is
	port(
		CLK, CLR: in std_logic;
        control : in std_logic_vector(1 downto 0);
        D : in std_logic_vector(2 downto 0);
		Q: out std_logic_vector (2 downto 0)
	);
attribute pin_numbers of Registro: entity is
"D(0):1 D(1):2 D(2):3  CLK:5 CLR:6 control(0):8 control(1):9 Q(0):23 Q(1):22 Q(2):21";
end entity;

architecture Registro3bits of Registro is
signal Daux : std_logic_vector(2 downto 0);
begin
	process (CLK, CLR, control, D)
		begin

            if (CLK = '1') then
                if (CLR = '0') then
                    
                    Daux <= D;
                    --Flip-Flop0
                    --Cargar Dato
                    if control = "00" then
                        Q(0) <= D(0);

                    --Retener Dato            
                    elsif control = "01" then
                        Daux(0) <= D(0);
                        Q(0) <= Daux(0);

                    --Desplazar Arriba
                    elsif control = "10" then
                        Q(0) <= D(2);
                        Daux(0) <= Q(0);

                    ----Desplazar Abajo
                    elsif control = "11" then
                        Q(0) <= D(1);
                        Daux(0) <= Q(0);

                    end if;

                    --Flip-Flop1
                    --Cargar Dato
                    if control = "00" then
                        Q(1) <= D(1);

                    --Retener Dato            
                    elsif control = "01" then
                        Daux(1) <= D(1);
                        Q(1) <= Daux(1);

                    --Desplazar Arriba
                    elsif control = "10" then
                        Q(1) <= D(0);
                        Daux(1) <= Q(1);

                    ----Desplazar Abajo
                    elsif control = "11" then
                        Q(1) <= D(2);
                        Daux(1) <= Q(1);
                    end if;

                    --Flip-Flop2
                    --Cargar Dato
                    if control = "00" then
                        Q(2) <= D(2);

                    --Retener Dato            
                    elsif control = "01" then
                        Daux(2) <= D(2);
                        Q(2) <= Daux(2);

                    --Desplazar Arriba
                    elsif control = "10" then
                        Q(2) <= D(1);
                        Daux(2) <= Q(2);

                    ----Desplazar Abajo
                    elsif control = "11" then
                        Q(2) <= D(0);
                        Daux(2) <= Q(2);
                    end if;
                    
                else
                    NULL;
                end if;
            end if;
	end process;
end architecture;