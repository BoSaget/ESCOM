
--  CYPRESS NOVA XVL Structural Architecture

--  JED2VHD Reverse Assembler - 6.3 IR 35


--    VHDL File: Sumador.vhd

--    Date: Mon Jan 08 02:26:41 2024

--  Disassembly from Jedec file for: c22v10

--  Device Ordercode is: PALCE22V10-15PC
library ieee;
use ieee.std_logic_1164.all;

library primitive;
use primitive.primitive.all;


-- Beginning Test Bench Header

ENTITY sumador IS
    PORT (
	                   a :    in std_logic_vector (3 downto 0) ;
	                   b :    in std_logic_vector (3 downto 0) ;
	               reset :    in std_logic ;
	                 clk :    in std_logic ;
	              salida : inout std_logic_vector (4 downto 0)
    );
END sumador;

-- End of Test Bench Header

ARCHITECTURE DSMB of sumador is

	signal jed_node1	: std_logic:='0' ; -- clk
	signal jed_node2	: std_logic:='0' ; -- reset
	signal jed_node3	: std_logic:='0' ; -- b(3)
	signal jed_node4	: std_logic:='0' ; -- b(2)
	signal jed_node5	: std_logic:='0' ; -- b(1)
	signal jed_node6	: std_logic:='0' ; -- b(0)
	signal jed_node7	: std_logic:='0' ; -- a(3)
	signal jed_node8	: std_logic:='0' ; -- a(2)
	signal jed_node9	: std_logic:='0' ; -- a(1)
	signal jed_node10	: std_logic:='0' ; -- a(0)
	signal jed_node11	: std_logic:='0' ;
	signal jed_node12	: std_logic:='0' ;
	signal jed_node13	: std_logic:='0' ;
	signal jed_node15	: std_logic:='0' ;
	signal jed_node17	: std_logic:='0' ;
	signal jed_node19	: std_logic:='0' ;
	signal jed_node20	: std_logic:='0' ;
	signal jed_node22	: std_logic:='0' ;
	signal jed_node24	: std_logic:='0' ;

	for all: c22v10m use entity primitive.c22v10m (sim);

SIGNAL  one:std_logic:='1';
SIGNAL  zero:std_logic:='0';
SIGNAL  jed_oept_1:std_logic:='0';
--Attribute PIN_NUMBERS of clk:SIGNAL is "0001";

SIGNAL  jed_oept_2:std_logic:='0';
--Attribute PIN_NUMBERS of reset:SIGNAL is "0002";

SIGNAL  jed_oept_3:std_logic:='0';
--Attribute PIN_NUMBERS of b(3):SIGNAL is "0003";

SIGNAL  jed_oept_4:std_logic:='0';
--Attribute PIN_NUMBERS of b(2):SIGNAL is "0004";

SIGNAL  jed_oept_5:std_logic:='0';
--Attribute PIN_NUMBERS of b(1):SIGNAL is "0005";

SIGNAL  jed_oept_6:std_logic:='0';
--Attribute PIN_NUMBERS of b(0):SIGNAL is "0006";

SIGNAL  jed_oept_7:std_logic:='0';
--Attribute PIN_NUMBERS of a(3):SIGNAL is "0007";

SIGNAL  jed_oept_8:std_logic:='0';
--Attribute PIN_NUMBERS of a(2):SIGNAL is "0008";

SIGNAL  jed_oept_9:std_logic:='0';
--Attribute PIN_NUMBERS of a(1):SIGNAL is "0009";

SIGNAL  jed_oept_10:std_logic:='0';
--Attribute PIN_NUMBERS of a(0):SIGNAL is "0010";

SIGNAL  jed_oept_14:std_logic:='0';
SIGNAL  jed_sum_14,jed_fb_14:std_logic:='0';
--Attribute PIN_NUMBERS of salida(1):SIGNAL is "0014";

SIGNAL  jed_oept_15:std_logic:='0';
SIGNAL \MODULE_1:g1:a0:g0:u0:ga:t1:ga0(1):gas:u1\:std_logic:='0';
SIGNAL  jed_sum_15,jed_fb_15:std_logic:='0';
--Attribute PIN_NUMBERS of jed_node15:SIGNAL is "0015";

SIGNAL  jed_oept_16:std_logic:='0';
SIGNAL  jed_sum_16,jed_fb_16:std_logic:='0';
--Attribute PIN_NUMBERS of salida(3):SIGNAL is "0016";

SIGNAL  jed_oept_17:std_logic:='0';
SIGNAL \MODULE_1:g1:a0:g0:u0:ga:t1:ga0(1):u3\:std_logic:='0';
SIGNAL  jed_sum_17,jed_fb_17:std_logic:='0';
--Attribute PIN_NUMBERS of jed_node17:SIGNAL is "0017";

SIGNAL  jed_oept_18:std_logic:='0';
SIGNAL  jed_sum_18,jed_fb_18:std_logic:='0';
--Attribute PIN_NUMBERS of salida(4):SIGNAL is "0018";

SIGNAL  jed_oept_20:std_logic:='0';
SIGNAL \MODULE_1:g1:a0:g0:u0:ga:t1:ga0(1):gas:u2\:std_logic:='0';
SIGNAL  jed_sum_20,jed_fb_20:std_logic:='0';
--Attribute PIN_NUMBERS of jed_node20:SIGNAL is "0020";

SIGNAL  jed_oept_21:std_logic:='0';
SIGNAL  jed_sum_21,jed_fb_21:std_logic:='0';
--Attribute PIN_NUMBERS of salida(0):SIGNAL is "0021";

SIGNAL  jed_oept_22:std_logic:='0';
SIGNAL \MODULE_1:g1:a0:g0:u0:ga:g1:ua0\:std_logic:='0';
SIGNAL  jed_sum_22,jed_fb_22:std_logic:='0';
--Attribute PIN_NUMBERS of jed_node22:SIGNAL is "0022";

SIGNAL  jed_oept_23:std_logic:='0';
SIGNAL  jed_sum_23,jed_fb_23:std_logic:='0';
--Attribute PIN_NUMBERS of salida(2):SIGNAL is "0023";

SIGNAL  jed_oept_25:std_logic:='0';
SIGNAL  jed_node25,jed_sum_25:std_logic:='0';
SIGNAL  jed_oept_26:std_logic:='0';
SIGNAL  jed_node26,jed_sum_26:std_logic:='0';

BEGIN
jed_node1 <= clk ;
jed_node2 <= reset ;
jed_node3 <= b(3) ;
jed_node4 <= b(2) ;
jed_node5 <= b(1) ;
jed_node6 <= b(0) ;
jed_node7 <= a(3) ;
jed_node8 <= a(2) ;
jed_node9 <= a(1) ;
jed_node10 <= a(0) ;
Mcell_14:c22v10m
generic map(reg,
   ninv,
   xreg,
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
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_14,
     clk=>jed_node1,
     oe=>jed_oept_14,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>salida(1),
     fb=>jed_fb_14
   );

Mcell_15:c22v10m
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
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_15,
     clk=>jed_node1,
     oe=>jed_oept_15,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>jed_node15,
     fb=>jed_fb_15
   );

Mcell_16:c22v10m
generic map(reg,
   ninv,
   xreg,
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
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_16,
     clk=>jed_node1,
     oe=>jed_oept_16,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>salida(3),
     fb=>jed_fb_16
   );

Mcell_17:c22v10m
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
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_17,
     clk=>jed_node1,
     oe=>jed_oept_17,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>jed_node17,
     fb=>jed_fb_17
   );

Mcell_18:c22v10m
generic map(reg,
   ninv,
   xreg,
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
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_18,
     clk=>jed_node1,
     oe=>jed_oept_18,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>salida(4),
     fb=>jed_fb_18
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
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_20,
     clk=>jed_node1,
     oe=>jed_oept_20,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>jed_node20,
     fb=>jed_fb_20
   );

Mcell_21:c22v10m
generic map(reg,
   ninv,
   xreg,
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
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_21,
     clk=>jed_node1,
     oe=>jed_oept_21,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>salida(0),
     fb=>jed_fb_21
   );

Mcell_22:c22v10m
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
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_22,
     clk=>jed_node1,
     oe=>jed_oept_22,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>jed_node22,
     fb=>jed_fb_22
   );

Mcell_23:c22v10m
generic map(reg,
   ninv,
   xreg,
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
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_23,
     clk=>jed_node1,
     oe=>jed_oept_23,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>salida(2),
     fb=>jed_fb_23
   );

\MODULE_1:g1:a0:g0:u0:ga:t1:ga0(1):gas:u1\ <= jed_fb_15;
\MODULE_1:g1:a0:g0:u0:ga:t1:ga0(1):u3\ <= jed_fb_17;
\MODULE_1:g1:a0:g0:u0:ga:t1:ga0(1):gas:u2\ <= jed_fb_20;
\MODULE_1:g1:a0:g0:u0:ga:g1:ua0\ <= jed_fb_22;
jed_node25<=jed_sum_25;
jed_node26<=jed_sum_26;
jed_oept_14<=(one);

jed_sum_14<= (((jed_node5) and (jed_node6) and (jed_node9) and (jed_node10)
) or
(not(jed_node5) and (jed_node6) and not(jed_node9) and (jed_node10)
) or
((jed_node5) and not(jed_node9) and not(jed_node10)
) or
((jed_node5) and not(jed_node6) and not(jed_node9)) or
(not(jed_node5) and (jed_node9) and not(jed_node10)
) or
(not(jed_node5) and not(jed_node6) and (jed_node9)));

jed_oept_15<=(one);

jed_sum_15<= (((jed_node3) and (jed_node4) and (jed_node8)) or
((jed_node4) and (jed_node7) and (jed_node8)) or
((jed_node3) and (jed_node7)));

jed_oept_16<=(one);

jed_sum_16<= (((jed_node3) and (jed_node4) and (jed_node7) and (jed_node8)
) or
((jed_fb_22) and (jed_node3) and (jed_node4) and (jed_node7)
) or
((jed_fb_22) and (jed_node3) and (jed_node7) and (jed_node8)
) or
(not(jed_fb_22) and (jed_node3) and not(jed_node7) and not(jed_node8)
) or
(not(jed_fb_22) and (jed_node3) and not(jed_node4) and not(jed_node7)
) or
((jed_node3) and not(jed_node4) and not(jed_node7) and not(jed_node8)
) or
(not(jed_fb_22) and not(jed_node3) and (jed_node7) and not(jed_node8)
) or
(not(jed_node3) and (jed_node4) and not(jed_node7) and (jed_node8)
) or
((jed_fb_22) and not(jed_node3) and (jed_node4) and not(jed_node7)
) or
((jed_fb_22) and not(jed_node3) and not(jed_node7) and (jed_node8)
) or
(not(jed_fb_22) and not(jed_node3) and not(jed_node4)
 and (jed_node7)) or
(not(jed_node3) and not(jed_node4) and (jed_node7) and not(jed_node8)
));

jed_oept_17<=(one);

jed_sum_17<= (((jed_fb_22) and (jed_fb_20)) or
((jed_fb_15)));

jed_oept_18<=(one);

jed_sum_18<= (((jed_fb_17)));

jed_oept_20<=(one);

jed_sum_20<= ((not(jed_node4) and not(jed_node8)) or
(not(jed_node3) and not(jed_node7)));

jed_oept_21<=(one);

jed_sum_21<= (((jed_node6) and not(jed_node10)) or
(not(jed_node6) and (jed_node10)));

jed_oept_22<=(one);

jed_sum_22<= (((jed_node5) and (jed_node6) and (jed_node10)) or
((jed_node6) and (jed_node9) and (jed_node10)) or
((jed_node5) and (jed_node9)));

jed_oept_23<=(one);

jed_sum_23<= (((jed_fb_22) and (jed_node4) and (jed_node8)) or
(not(jed_fb_22) and (jed_node4) and not(jed_node8)) or
(not(jed_fb_22) and not(jed_node4) and (jed_node8)) or
((jed_fb_22) and not(jed_node4) and not(jed_node8)));

jed_sum_25<= (((jed_node2)));

end DSMB;
