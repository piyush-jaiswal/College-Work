library ieee;
use ieee.std_logic_1164.all;

entity ORGATE is
port(A: in std_logic;
     B: in std_logic;
     Z: out std_logic);
end ORGATE;

Architecture func of ORGATE is 
begin 	
	Z<= A OR B;
end func;
