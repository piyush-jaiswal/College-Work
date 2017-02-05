library ieee;
use ieee.std_logic_1164.all;

entity ANDgate is
port( A, B : in std_logic;
	F:  out std_logic);
end ANDgate;

architecture func of ANDgate is
begin
  F<= A and B;
end func;
