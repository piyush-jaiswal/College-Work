library ieee;
use ieee.std_logic_1164.all;

entity Mux2x1 is 
port(din : in std_logic_vector(1 downto 0);
     sel : in std_logic;
     dout : out std_logic);
end Mux2x1;

architecture func of Mux2x1 is
begin
mux : process(din,sel) is
begin
	if(sel='0')then
		dout<= din(0);
	else
		dout<= din(1);
	end if;
end process mux;

end func;