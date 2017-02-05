library ieee;
use ieee.std_logic_1164.all;

entity Mux4X1Using2x1Mux is
port(I0,I1,I2,I3,S1,S0 : in std_logic;
     F: out std_logic);
end Mux4x1Using2x1Mux;

architecture func of Mux4x1Using2x1Mux is

component Mux2x1UsingAndOrNot is -- import 2x1 entity
port(I0,I1,S : in std_logic;
     F: out std_logic);
end component;

signal mux1, mux2 : std_logic;

begin
G1: Mux2x1UsingAndOrNot port map(I0, I1, S0, mux1);
G2: Mux2x1UsingAndOrNot port map(I2, I3, S0, mux2);
G3: Mux2x1UsingAndOrNot port map(mux1, mux2, S1, F);
end func;