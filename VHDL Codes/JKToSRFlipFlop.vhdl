library ieee;
use ieee.std_logic_1164.all;

entity JKToSRFlipFlop is
port(S,R,Clk : in std_logic;
     Q, QBar : out std_logic);
end JKToSRFlipFlop;

architecture func of JKToSRFlipFlop is

component JKFlipFlop is -- import JK FLipFLop
port(J,K,Clk : in std_logic;
     Q, QBar : out std_logic);
end component;

begin
G1 : JKFlipFlop port map(S,R,Clk,Q,QBar);
end func;