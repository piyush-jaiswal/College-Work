library ieee;
use ieee.std_logic_1164.all;

entity JKFlipFlop is
port(J,K,Clk : in std_logic;
     Q, QBar : out std_logic);
end JKFlipFlop;

architecture func of JKFlipFLop is
begin

process(Clk)
variable tmp : std_logic := '0';
begin

if(rising_edge(Clk))then
	if(J='0' and K='0')then
		tmp := tmp;
	elsif(J='0' and K='1')then
		tmp := '0';
	elsif(J='1' and K='1')then
		tmp := not tmp;
	else
		tmp:='1';
	end if;
end if;
Q<= tmp;
QBar<= not tmp;
end process;

end func;