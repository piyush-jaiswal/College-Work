library ieee;
use ieee.std_logic_1164.all;

entity HalfAdder is
port( A,B : in std_logic;
      sum,Cout : out std_logic);
end HalfAdder;

architecture halfAdder of HalfAdder is

component ANDgate is -- import AND gate
port( A,B : in std_logic;
	F : out std_logic);
end component;

component XORgate is -- import xor gate
port( A,B : in std_logic;
	F : out std_logic);
end component;

begin 
G1 : XORgate port map(A,B,sum);
G2 : ANDgate port map(A,B,Cout);
end halfAdder; 
