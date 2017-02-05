library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity ModUpSequenceUpto13 is
port(din : std_logic_vector(3 downto 0);
     load,clk,reset : in std_logic;
     dout : out std_logic_vector(3 downto 0));
end ModUpSequenceUpto13;

architecture func of ModUpSequenceUpto13 is
begin
process(clk,reset)
variable tmp : std_logic_vector(3 downto 0) := "0000";
begin
if(reset='1')then
tmp:= "0000";
else
	if(rising_edge(clk))then
		if(load='1')then
			tmp:= din;
		else
			if(tmp="1100")then
				tmp:="0000";
			else
				tmp:= tmp+"0001";
			end if;
		end if;
	end if;
end if;
dout<=tmp;
end process;

end func;
				
