library ieee;
use ieee.std_logic_1164.all;

entity SRFlipFlop is
port(S,R,Clk : in std_logic;
     Q, QBar : out std_logic);
end SRFlipFlop;

architecture func of SRFlipFlop is

begin

process(Clk)
variable tmp : std_logic := '0';

begin
	if(rising_edge(Clk))then
		if(S='0' and R='0')then
			tmp :=tmp;
		elsif(S='1' and R='1')then
			tmp := 'Z';
		elsif(S='1' and R='0')then
			tmp := '1';
		else
			tmp := '0';
		end if;
	end if;
Q <= tmp;
QBar <= not tmp;
end process;

end func;
