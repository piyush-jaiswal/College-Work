library ieee;
use ieee.std_logic_1164.all;

entity CarryLookAheadAdder8bit is
port(inp1, inp2 : in std_logic_vector(7 downto 0);
     cin : in std_logic;
     out1 : out std_logic_vector(7 downto 0);
     cout : out std_logic);
end CarryLookAheadAdder8bit;

architecture func of CarryLookAheadAdder8bit is

begin
process(inp1,inp2,cin)
variable c : std_logic_vector(8 downto 0);
variable g,p : std_logic;

begin
c(0):= cin;
c(8):='0';
for i in 0 to 7 loop
out1(i)<= inp1(i) xor inp2(i) xor c(i);
g:= inp1(i) and inp2(i);
p:= inp1(i) xor inp2(i);
c(i+1):= g or (p and c(i));
end loop;
cout<=c(8);
end process;

end func;

