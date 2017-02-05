library ieee;
use ieee.std_logic_1164.all;

entity DFlipFLop is
port(D, Clk, Rst : in std_logic;
     Q, QBar : out std_logic);
end DFlipFLop;

architecture func of DFlipFlop is
begin

process(CLk)
variable tmp : std_logic:='0';
begin
if(rising_edge(Clk))then
	if(Rst = '1')then
		tmp:='0';
	else
		if(D = '0')then
			tmp:='0';
		else
			tmp:= '1';
		end if;
	end if;
end if;
Q<= tmp;
QBar<= not tmp;
end process;
end func;
