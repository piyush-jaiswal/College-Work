library ieee;
use ieee.std_logic_1164.all;

entity NORUsingOrAndNot is
port(A,B : in std_logic;
     F : out std_logic);
end NORUsingOrAndNot;

architecture func of NORUsingOrAndNot is

component ORGATE is -- import OR gate
port(A,B: in std_logic;
     Z : out std_logic);
end component;

component notGate is -- import NOT gate
port(inPort : in std_logic;
     outPort : out std_logic);
end component;

signal OrAns : std_logic;

begin
G1: ORGATE port map(A, B, OrAns);
G2: notGate port map(OrAns, F);
end func;