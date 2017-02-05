library ieee;
use ieee.std_logic_1164.all;

entity Mux2x1UsingAndOrNot is
port(I0,I1,S : in std_logic;
     F: out std_logic);
end Mux2x1UsingAndOrNot;

architecture func of Mux2x1UsingAndOrNot is

component ORGATE is -- import OR gate
port(A,B: in std_logic;
     Z : out std_logic);
end component;

component notGate is -- import NOT gate
port(inPort : in std_logic;
     outPort : out std_logic);
end component;

component ANDgate is -- imoprt AND gate
port(A,B : in std_logic;
     F: out std_logic);
end component;

signal notS, And1, And2 : std_logic; 

begin
G1: notGate port map(S, notS);
G2: ANDgate port map(notS, I0, And1);
G3: ANDgate port map(S,I1, And2);
G4: ORGATE port map(And1, And2, F);
end func;
