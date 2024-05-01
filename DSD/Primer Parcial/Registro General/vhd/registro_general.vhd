
--  CYPRESS NOVA XVL Structural Architecture

--  JED2VHD Reverse Assembler - 6.3 IR 35


--    VHDL File: registro_general.vhd

--    Date: Mon Sep 27 18:42:16 2021

--  Disassembly from Jedec file for: c22v10

--  Device Ordercode is: PALC22V10D-15PC
library ieee;
use ieee.std_logic_1164.all;

library primitive;
use primitive.primitive.all;


-- Beginning Test Bench Header

ENTITY registro IS
    PORT (
	                 clk :    in std_logic ;
	                 clr :    in std_logic ;
	             control :    in std_logic_vector (1 downto 0) ;
	                   d :    in std_logic_vector (2 downto 0) ;
	                   q : inout std_logic_vector (2 downto 0)
    );
END registro;

-- End of Test Bench Header

ARCHITECTURE DSMB of registro is

	signal jed_node1	: std_logic:='0' ; -- d(0)
	signal jed_node2	: std_logic:='0' ; -- d(1)
	signal jed_node3	: std_logic:='0' ; -- d(2)
	signal jed_node4	: std_logic:='0' ;
	signal jed_node5	: std_logic:='0' ; -- clk
	signal jed_node6	: std_logic:='0' ; -- clr
	signal jed_node7	: std_logic:='0' ;
	signal jed_node8	: std_logic:='0' ; -- control(0)
	signal jed_node9	: std_logic:='0' ; -- control(1)
	signal jed_node10	: std_logic:='0' ;
	signal jed_node11	: std_logic:='0' ;
	signal jed_node12	: std_logic:='0' ;
	signal jed_node13	: std_logic:='0' ;
	signal jed_node14	: std_logic:='0' ;
	signal jed_node15	: std_logic:='0' ;
	signal jed_node16	: std_logic:='0' ;
	signal jed_node17	: std_logic:='0' ;
	signal jed_node18	: std_logic:='0' ;
	signal jed_node19	: std_logic:='0' ;
	signal jed_node20	: std_logic:='0' ;
	signal jed_node24	: std_logic:='0' ;

	for all: c22v10m use entity primitive.c22v10m (sim);

SIGNAL  one:std_logic:='1';
SIGNAL  zero:std_logic:='0';
SIGNAL  jed_oept_1:std_logic:='0';
--Attribute PIN_NUMBERS of d(0):SIGNAL is "0001";

SIGNAL  jed_oept_2:std_logic:='0';
--Attribute PIN_NUMBERS of d(1):SIGNAL is "0002";

SIGNAL  jed_oept_3:std_logic:='0';
--Attribute PIN_NUMBERS of d(2):SIGNAL is "0003";

SIGNAL  jed_oept_5:std_logic:='0';
--Attribute PIN_NUMBERS of clk:SIGNAL is "0005";

SIGNAL  jed_oept_6:std_logic:='0';
--Attribute PIN_NUMBERS of clr:SIGNAL is "0006";

SIGNAL  jed_oept_8:std_logic:='0';
--Attribute PIN_NUMBERS of control(0):SIGNAL is "0008";

SIGNAL  jed_oept_9:std_logic:='0';
--Attribute PIN_NUMBERS of control(1):SIGNAL is "0009";

SIGNAL  jed_oept_14:std_logic:='0';
SIGNAL daux_2:std_logic:='0';
SIGNAL  jed_sum_14,jed_fb_14:std_logic:='0';
--Attribute PIN_NUMBERS of jed_node14:SIGNAL is "0014";

SIGNAL  jed_oept_15:std_logic:='0';
SIGNAL daux_1:std_logic:='0';
SIGNAL  jed_sum_15,jed_fb_15:std_logic:='0';
--Attribute PIN_NUMBERS of jed_node15:SIGNAL is "0015";

SIGNAL  jed_oept_16:std_logic:='0';
SIGNAL daux_0:std_logic:='0';
SIGNAL  jed_sum_16,jed_fb_16:std_logic:='0';
--Attribute PIN_NUMBERS of jed_node16:SIGNAL is "0016";

SIGNAL  jed_oept_21:std_logic:='0';
SIGNAL  jed_sum_21,jed_fb_21:std_logic:='0';
--Attribute PIN_NUMBERS of q(2):SIGNAL is "0021";

SIGNAL  jed_oept_22:std_logic:='0';
SIGNAL  jed_sum_22,jed_fb_22:std_logic:='0';
--Attribute PIN_NUMBERS of q(1):SIGNAL is "0022";

SIGNAL  jed_oept_23:std_logic:='0';
SIGNAL  jed_sum_23,jed_fb_23:std_logic:='0';
--Attribute PIN_NUMBERS of q(0):SIGNAL is "0023";

SIGNAL  jed_oept_25:std_logic:='0';
SIGNAL  jed_node25,jed_sum_25:std_logic:='0';
SIGNAL  jed_oept_26:std_logic:='0';
SIGNAL  jed_node26,jed_sum_26:std_logic:='0';

BEGIN
jed_node1 <= d(0) ;
jed_node2 <= d(1) ;
jed_node3 <= d(2) ;
jed_node5 <= clk ;
jed_node6 <= clr ;
jed_node8 <= control(0) ;
jed_node9 <= control(1) ;
Mcell_14:c22v10m
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
     d=>jed_sum_14,
     clk=>jed_node1,
     oe=>jed_oept_14,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>jed_node14,
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
	10 ns, --tar
	20 ns, --tap
	10 ns  --tspr
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
     d=>jed_sum_16,
     clk=>jed_node1,
     oe=>jed_oept_16,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>jed_node16,
     fb=>jed_fb_16
   );

Mcell_21:c22v10m
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
     d=>jed_sum_21,
     clk=>jed_node1,
     oe=>jed_oept_21,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>q(2),
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
     y=>q(1),
     fb=>jed_fb_22
   );

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
     y=>q(0),
     fb=>jed_fb_23
   );

daux_2 <= jed_fb_14;
daux_1 <= jed_fb_15;
daux_0 <= jed_fb_16;
jed_node25<=jed_sum_25;
jed_node26<=jed_sum_26;
jed_oept_14<=(one);

jed_sum_14<= (((jed_fb_21) and (jed_node5) and not(jed_node6) and (jed_node9)
) or
((jed_node3) and (jed_node5) and not(jed_node6) and not(jed_node9)
) or
((jed_node6) and (jed_fb_14)) or
(not(jed_node5) and (jed_fb_14)));

jed_oept_15<=(one);

jed_sum_15<= (((jed_fb_22) and (jed_node5) and not(jed_node6) and (jed_node9)
) or
((jed_node2) and (jed_node5) and not(jed_node6) and not(jed_node9)
) or
((jed_node6) and (jed_fb_15)) or
(not(jed_node5) and (jed_fb_15)));

jed_oept_16<=(one);

jed_sum_16<= (((jed_fb_23) and (jed_node5) and not(jed_node6) and (jed_node9)
) or
((jed_node1) and (jed_node5) and not(jed_node6) and not(jed_node9)
) or
((jed_node6) and (jed_fb_16)) or
(not(jed_node5) and (jed_fb_16)));

jed_oept_21<=(one);

jed_sum_21<= (((jed_node1) and (jed_node5) and not(jed_node6) and (jed_node8)
 and (jed_node9)) or
((jed_node2) and (jed_node5) and not(jed_node6) and not(jed_node8)
 and (jed_node9)) or
((jed_node5) and not(jed_node6) and (jed_node8) and not(jed_node9)
 and (jed_fb_14)) or
((jed_node3) and (jed_node5) and not(jed_node6) and not(jed_node8)
 and not(jed_node9)) or
((jed_fb_21) and (jed_node6)) or
((jed_fb_21) and not(jed_node5)));

jed_oept_22<=(one);

jed_sum_22<= (((jed_node3) and (jed_node5) and not(jed_node6) and (jed_node8)
 and (jed_node9)) or
((jed_node1) and (jed_node5) and not(jed_node6) and not(jed_node8)
 and (jed_node9)) or
((jed_node5) and not(jed_node6) and (jed_node8) and not(jed_node9)
 and (jed_fb_15)) or
((jed_node2) and (jed_node5) and not(jed_node6) and not(jed_node8)
 and not(jed_node9)) or
((jed_fb_22) and (jed_node6)) or
((jed_fb_22) and not(jed_node5)));

jed_oept_23<=(one);

jed_sum_23<= (((jed_node2) and (jed_node5) and not(jed_node6) and (jed_node8)
 and (jed_node9)) or
((jed_node3) and (jed_node5) and not(jed_node6) and not(jed_node8)
 and (jed_node9)) or
((jed_node5) and not(jed_node6) and (jed_node8) and (jed_fb_16)
 and not(jed_node9)) or
((jed_node1) and (jed_node5) and not(jed_node6) and not(jed_node8)
 and not(jed_node9)) or
((jed_fb_23) and (jed_node6)) or
((jed_fb_23) and not(jed_node5)));

end DSMB;
