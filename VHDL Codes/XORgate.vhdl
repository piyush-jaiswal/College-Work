library ieee;
use ieee.std_logic_1164.all;

entity XORgate is
port( A,B: in std_logic;
	F: out std_logic);
end XORgate;

architecture func of XORgate is
begin
  F<= A xor B;
end func;

