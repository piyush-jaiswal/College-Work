library ieee;
use ieee.std_logic_1164.all;

entity AndUsingOrAndNot is
port(A,B : in std_logic;
     F : out std_logic);
end AndUsingOrAndNot;

architecture func of AndUsingOrAndNot is

component ORGATE is -- import OR gate
port(A,B: in std_logic;
     Z : out std_logic);
end component;

component notGate is -- import NOT gate
port(inPort : in std_logic;
     outPort : out std_logic);
end component;

signal Acomp, Bcomp, ORans: std_logic; 

begin
G1: notGate port map(A, Acomp);
G2: notGate port map(B, Bcomp);
G3: ORGATE port map(Acomp, Bcomp, ORans);
G4: notGate port map(Orans, F);
end func;
