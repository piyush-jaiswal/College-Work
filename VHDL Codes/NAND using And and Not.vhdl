library ieee;
use ieee.std_logic_1164.all;

entity NandUsingAndAndNot is
port(A,B: in std_logic;
     F: out std_logic);
end NandUsingAndAndNot;

architecture func of NandUsingAndAndNot is

component ANDgate is -- imoprt AND gate
port(A,B : in std_logic;
     F: out std_logic);
end component;

component notGate is -- import NOT gate
port(inPort : in std_logic;
     outPort : out std_logic);
end component;

signal Andans : std_logic;

begin
G1: ANDgate port map(A, B, Andans);
G2: notGate port map(Andans, F);
end func;