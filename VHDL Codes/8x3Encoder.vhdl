library ieee;
use ieee.std_logic_1164.all;

entity Encoder8x3 is
port(din : in std_logic_vector(7 downto 0);
     dout : out std_logic_vector(2 downto 0));
end Encoder8x3;

architecture func of Encoder8x3 is
begin
encode : process(din) is
begin
	if(din = "00000001")then	
		dout<= "000";
	elsif(din = "00000010")then
		dout<= "001";
	elsif(din = "00000100")then
		dout<= "010";
	elsif(din = "00001000")then
		dout<= "011";
	elsif(din = "00010000")then
		dout<= "100";
	elsif(din = "00100000")then
		dout<= "101";
	elsif(din = "01000000")then
		dout<= "110";
	else
		dout<= "111";
	end if;
end process encode;

end func;