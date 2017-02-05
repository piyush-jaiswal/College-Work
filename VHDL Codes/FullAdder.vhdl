library ieee;
use ieee.std_logic_1164.all;

entity fullAdder is
port(A,B,Cin : in std_logic;
     sum,Cout : out std_logic);
end fullAdder;

architecture fullAdder of fullAdder is

component halfAdder is -- import half adder entity
port(A,B : in std_logic;
     sum,Cout : out std_logic);
end component;

component ORGATE is -- import OR gate entity
port(A,B: in std_logic;
     Z: out std_logic);
end component;

signal halfTohalf, halfToOr1, halfToOr2: std_logic; -- signal is as variables to store values which you later want to use but not as output

begin
G1 : halfAdder port map(A, B, halfTohalf, halfToOr1);
G2 : halfAdder port map(halfTohalf, Cin, sum, halfToOr2);
G3 : ORGATE port map(halfToOr1, halfToOr2, Cout);
end fullAdder;