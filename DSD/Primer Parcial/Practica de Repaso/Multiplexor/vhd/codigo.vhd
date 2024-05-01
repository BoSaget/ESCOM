
--  CYPRESS NOVA XVL Structural Architecture

--  JED2VHD Reverse Assembler - 6.3 IR 35


--    VHDL File: codigo.vhd

--    Date: Tue Sep 21 20:10:48 2021

--  Disassembly from Jedec file for: c22v10

--  Device Ordercode is: PALC22V10D-15PC
library ieee;
use ieee.std_logic_1164.all;

library primitive;
use primitive.primitive.all;


-- Beginning Test Bench Header

ENTITY multiplexor4_1 IS
    PORT (
	             control :    in std_logic_vector (1 downto 0) ;
	            entradas :    in std_logic_vector (3 downto 0) ;
	              salida : inout std_logic
    );
END multiplexor4_1;

-- End of Test Bench Header

ARCHITECTURE DSMB of multiplexor4_1 is

	signal jed_node1	: std_logic:='0' ; -- control(1)
	signal jed_node2	: std_logic:='0' ; -- control(0)
	signal jed_node3	: std_logic:='0' ;
	signal jed_node4	: std_logic:='0' ;
	signal jed_node5	: std_logic:='0' ;
	signal jed_node6	: std_logic:='0' ;
	signal jed_node7	: std_logic:='0' ;
	signal jed_node8	: std_logic:='0' ; -- entradas(3)
	signal jed_node9	: std_logic:='0' ; -- entradas(2)
	signal jed_node10	: std_logic:='0' ; -- entradas(1)
	signal jed_node11	: std_logic:='0' ; -- entradas(0)
	signal jed_node12	: std_logic:='0' ;
	signal jed_node13	: std_logic:='0' ;
	signal jed_node14	: std_logic:='0' ;
	signal jed_node15	: std_logic:='0' ;
	signal jed_node16	: std_logic:='0' ;
	signal jed_node17	: std_logic:='0' ;
	signal jed_node18	: std_logic:='0' ;
	signal jed_node19	: std_logic:='0' ;
	signal jed_node20	: std_logic:='0' ;
	signal jed_node21	: std_logic:='0' ;
	signal jed_node22	: std_logic:='0' ;
	signal jed_node24	: std_logic:='0' ;

	for all: c22v10m use entity primitive.c22v10m (sim);

SIGNAL  one:std_logic:='1';
SIGNAL  zero:std_logic:='0';
SIGNAL  jed_oept_1:std_logic:='0';
--Attribute PIN_NUMBERS of control(1):SIGNAL is "0001";

SIGNAL  jed_oept_2:std_logic:='0';
--Attribute PIN_NUMBERS of control(0):SIGNAL is "0002";

SIGNAL  jed_oept_8:std_logic:='0';
--Attribute PIN_NUMBERS of entradas(3):SIGNAL is "0008";

SIGNAL  jed_oept_9:std_logic:='0';
--Attribute PIN_NUMBERS of entradas(2):SIGNAL is "0009";

SIGNAL  jed_oept_10:std_logic:='0';
--Attribute PIN_NUMBERS of entradas(1):SIGNAL is "0010";

SIGNAL  jed_oept_11:std_logic:='0';
--Attribute PIN_NUMBERS of entradas(0):SIGNAL is "0011";

SIGNAL  jed_oept_23:std_logic:='0';
SIGNAL  jed_sum_23,jed_fb_23:std_logic:='0';
--Attribute PIN_NUMBERS of salida:SIGNAL is "0023";

SIGNAL  jed_oept_25:std_logic:='0';
SIGNAL  jed_node25,jed_sum_25:std_logic:='0';
SIGNAL  jed_oept_26:std_logic:='0';
SIGNAL  jed_node26,jed_sum_26:std_logic:='0';

BEGIN
jed_node1 <= control(1) ;
jed_node2 <= control(0) ;
jed_node8 <= entradas(3) ;
jed_node9 <= entradas(2) ;
jed_node10 <= entradas(1) ;
jed_node11 <= entradas(0) ;
Mcell_23:c22v10m
generic map(comb,
   ninv,
   xpin,
   	15 ns, --tpd
	15 ns, --tea
	15 ns, --ter
	8 ns, --tco
	10 ns, --ts
	0 ns, --th
	6 ns, --twh
	6 ns, --twl
	4 ns, --tcf
	15 ns, --taw
	10 ns, --tar
	20 ns, --tap
	10 ns  --tspr
)
port map(
     d=>jed_sum_23,
     clk=>jed_node1,
     oe=>jed_oept_23,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>salida,
     fb=>jed_fb_23
   );

jed_node25<=jed_sum_25;
jed_node26<=jed_sum_26;
jed_oept_23<=(one);

jed_sum_23<= (((jed_node1) and (jed_node2) and (jed_node8)) or
((jed_node1) and not(jed_node2) and (jed_node9)) or
(not(jed_node1) and (jed_node2) and (jed_node10)) or
(not(jed_node1) and not(jed_node2) and (jed_node11)
));

end DSMB;
