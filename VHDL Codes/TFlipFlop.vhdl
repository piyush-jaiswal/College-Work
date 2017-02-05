library ieee;
use ieee.std_logic_1164.all;

entity TFlipFLop is
port(T,Clk : in std_logic;
     Q, QBar : out std_logic);
end TFlipFlop;

architecture func of TFlipFlop is
begin

process(Clk)
variable tmp : std_logic := '0';
begin

if(rising_edge(Clk))then
	if(T = '1')then
		tmp:= not tmp;
	else
		tmp:= tmp;
	end if;
end if;
Q<= tmp;
QBar<= not tmp;
end process;

end func;
