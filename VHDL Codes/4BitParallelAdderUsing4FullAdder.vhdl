library ieee;
use ieee.std_logic_1164.all;

entity FourBitParallelAdder is
port(inp1, inp2: in std_logic_vector(3 downto 0);
     out1: out std_logic_vector(4 downto 0));
end FourBitParallelAdder;

architecture func of FourBitParallelAdder is

component fullAdder is -- import full adder
port(A,B,Cin : in std_logic;
     sum, Cout: out std_logic);
end component;

signal c1,c2,c3 : std_logic;

begin
G1 : fullAdder port map(inp1(0), inp2(0), '0', out1(0), c1);
G2 : fullAdder port map(inp1(1), inp2(1), c1, out1(1), c2);
G3 : fullAdder port map(inp1(2), inp2(2), c2, out1(2), c3);
G4 : fullAdder port map(inp1(3), inp2(3), c3, out1(3), out1(4));

end func;

