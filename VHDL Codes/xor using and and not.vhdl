library ieee;
use ieee.std_logic_1164.all;

entity XorUsingAndAndNot is
port(A,B: in std_logic;
     F: out std_logic);
end XorUsingAndAndNot;

architecture func of XorUsingAndAndNot is

component ANDgate is -- imoprt AND gate
port(A,B : in std_logic;
     F: out std_logic);
end component;

component notGate is -- import NOT gate
port(inPort : in std_logic;
     outPort : out std_logic);
end component;

signal Acomp, Bcomp, And1, And2, Comp1, Comp2, Comp3 : std_logic;

begin
G1: notGate port map(A, Acomp);
G2: notGate port map(B, Bcomp);
G3: ANDgate port map(Acomp, B, And1);
G4: ANDgate port map(A, Bcomp, And2);
G5: notGate port map(And1, Comp1);
G6: notGate port map(And2, Comp2);
G7: ANDgate port map(Comp1, Comp2, Comp3);
G8: notGate port map(Comp3, F);
end func;
