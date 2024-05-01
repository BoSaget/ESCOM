
--  CYPRESS NOVA XVL Structural Architecture

--  JED2VHD Reverse Assembler - 6.3 IR 35


--    VHDL File: codigo.vhd

--    Date: Tue Sep 21 21:55:35 2021

--  Disassembly from Jedec file for: c22v10

--  Device Ordercode is: PALC22V10D-15PC
library ieee;
use ieee.std_logic_1164.all;

library primitive;
use primitive.primitive.all;


-- Beginning Test Bench Header

ENTITY decodificador IS
    PORT (
	                dato :    in std_logic_vector (3 downto 0) ;
	            segmento : inout std_logic_vector (6 downto 0)
    );
END decodificador;

-- End of Test Bench Header

ARCHITECTURE DSMB of decodificador is

	signal jed_node1	: std_logic:='0' ; -- dato(3)
	signal jed_node2	: std_logic:='0' ; -- dato(2)
	signal jed_node3	: std_logic:='0' ; -- dato(1)
	signal jed_node4	: std_logic:='0' ; -- dato(0)
	signal jed_node5	: std_logic:='0' ;
	signal jed_node6	: std_logic:='0' ;
	signal jed_node7	: std_logic:='0' ;
	signal jed_node8	: std_logic:='0' ;
	signal jed_node9	: std_logic:='0' ;
	signal jed_node10	: std_logic:='0' ;
	signal jed_node11	: std_logic:='0' ;
	signal jed_node12	: std_logic:='0' ;
	signal jed_node13	: std_logic:='0' ;
	signal jed_node14	: std_logic:='0' ;
	signal jed_node15	: std_logic:='0' ;
	signal jed_node16	: std_logic:='0' ;
	signal jed_node24	: std_logic:='0' ;

	for all: c22v10m use entity primitive.c22v10m (sim);

SIGNAL  one:std_logic:='1';
SIGNAL  zero:std_logic:='0';
SIGNAL  jed_oept_1:std_logic:='0';
--Attribute PIN_NUMBERS of dato(3):SIGNAL is "0001";

SIGNAL  jed_oept_2:std_logic:='0';
--Attribute PIN_NUMBERS of dato(2):SIGNAL is "0002";

SIGNAL  jed_oept_3:std_logic:='0';
--Attribute PIN_NUMBERS of dato(1):SIGNAL is "0003";

SIGNAL  jed_oept_4:std_logic:='0';
--Attribute PIN_NUMBERS of dato(0):SIGNAL is "0004";

SIGNAL  jed_oept_17:std_logic:='0';
SIGNAL  jed_sum_17,jed_fb_17:std_logic:='0';
--Attribute PIN_NUMBERS of segmento(6):SIGNAL is "0017";

SIGNAL  jed_oept_18:std_logic:='0';
SIGNAL  jed_sum_18,jed_fb_18:std_logic:='0';
--Attribute PIN_NUMBERS of segmento(5):SIGNAL is "0018";

SIGNAL  jed_oept_19:std_logic:='0';
SIGNAL  jed_sum_19,jed_fb_19:std_logic:='0';
--Attribute PIN_NUMBERS of segmento(4):SIGNAL is "0019";

SIGNAL  jed_oept_20:std_logic:='0';
SIGNAL  jed_sum_20,jed_fb_20:std_logic:='0';
--Attribute PIN_NUMBERS of segmento(3):SIGNAL is "0020";

SIGNAL  jed_oept_21:std_logic:='0';
SIGNAL  jed_sum_21,jed_fb_21:std_logic:='0';
--Attribute PIN_NUMBERS of segmento(2):SIGNAL is "0021";

SIGNAL  jed_oept_22:std_logic:='0';
SIGNAL  jed_sum_22,jed_fb_22:std_logic:='0';
--Attribute PIN_NUMBERS of segmento(1):SIGNAL is "0022";

SIGNAL  jed_oept_23:std_logic:='0';
SIGNAL  jed_sum_23,jed_fb_23:std_logic:='0';
--Attribute PIN_NUMBERS of segmento(0):SIGNAL is "0023";

SIGNAL  jed_oept_25:std_logic:='0';
SIGNAL  jed_node25,jed_sum_25:std_logic:='0';
SIGNAL  jed_oept_26:std_logic:='0';
SIGNAL  jed_node26,jed_sum_26:std_logic:='0';

BEGIN
jed_node1 <= dato(3) ;
jed_node2 <= dato(2) ;
jed_node3 <= dato(1) ;
jed_node4 <= dato(0) ;
Mcell_17:c22v10m
generic map(comb,
   invt,
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
     d=>jed_sum_17,
     clk=>jed_node1,
     oe=>jed_oept_17,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>segmento(6),
     fb=>jed_fb_17
   );

Mcell_18:c22v10m
generic map(comb,
   invt,
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
     d=>jed_sum_18,
     clk=>jed_node1,
     oe=>jed_oept_18,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>segmento(5),
     fb=>jed_fb_18
   );

Mcell_19:c22v10m
generic map(comb,
   invt,
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
     d=>jed_sum_19,
     clk=>jed_node1,
     oe=>jed_oept_19,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>segmento(4),
     fb=>jed_fb_19
   );

Mcell_20:c22v10m
generic map(comb,
   invt,
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
     d=>jed_sum_20,
     clk=>jed_node1,
     oe=>jed_oept_20,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>segmento(3),
     fb=>jed_fb_20
   );

Mcell_21:c22v10m
generic map(comb,
   invt,
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
     d=>jed_sum_21,
     clk=>jed_node1,
     oe=>jed_oept_21,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>segmento(2),
     fb=>jed_fb_21
   );

Mcell_22:c22v10m
generic map(comb,
   invt,
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
     d=>jed_sum_22,
     clk=>jed_node1,
     oe=>jed_oept_22,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>segmento(1),
     fb=>jed_fb_22
   );

Mcell_23:c22v10m
generic map(comb,
   invt,
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
     y=>segmento(0),
     fb=>jed_fb_23
   );

jed_node25<=jed_sum_25;
jed_node26<=jed_sum_26;
jed_oept_17<=(one);

jed_sum_17<= (((jed_node1) and (jed_node2) and not(jed_node3) and not(jed_node4)
) or
(not(jed_node1) and (jed_node2) and (jed_node3) and (jed_node4)
) or
(not(jed_node1) and not(jed_node2) and not(jed_node3)
));

jed_oept_18<=(one);

jed_sum_18<= (((jed_node1) and (jed_node2) and not(jed_node3) and (jed_node4)
) or
(not(jed_node1) and (jed_node3) and (jed_node4)) or
(not(jed_node1) and not(jed_node2) and (jed_node3)) or
(not(jed_node1) and not(jed_node2) and (jed_node4)));

jed_oept_19<=(one);

jed_sum_19<= ((not(jed_node2) and not(jed_node3) and (jed_node4)) or
(not(jed_node1) and (jed_node2) and not(jed_node3)) or
(not(jed_node1) and (jed_node4)));

jed_oept_20<=(one);

jed_sum_20<= (((jed_node1) and not(jed_node2) and (jed_node3) and not(jed_node4)
) or
(not(jed_node1) and (jed_node2) and not(jed_node3) and not(jed_node4)
) or
(not(jed_node1) and not(jed_node2) and not(jed_node3)
 and (jed_node4)) or
((jed_node2) and (jed_node3) and (jed_node4)));

jed_oept_21<=(one);

jed_sum_21<= ((not(jed_node1) and not(jed_node2) and (jed_node3) and not(jed_node4)
) or
((jed_node1) and (jed_node2) and not(jed_node4)) or
((jed_node1) and (jed_node2) and (jed_node3)));

jed_oept_22<=(one);

jed_sum_22<= ((not(jed_node1) and (jed_node2) and not(jed_node3) and (jed_node4)
) or
((jed_node1) and (jed_node3) and (jed_node4)) or
((jed_node1) and (jed_node2) and not(jed_node4)) or
((jed_node2) and (jed_node3) and not(jed_node4)));

jed_oept_23<=(one);

jed_sum_23<= (((jed_node1) and (jed_node2) and not(jed_node3) and (jed_node4)
) or
((jed_node1) and not(jed_node2) and (jed_node3) and (jed_node4)
) or
(not(jed_node1) and (jed_node2) and not(jed_node3) and not(jed_node4)
) or
(not(jed_node1) and not(jed_node2) and not(jed_node3)
 and (jed_node4)));

end DSMB;
