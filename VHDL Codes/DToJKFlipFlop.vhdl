library ieee;
use ieee.std_logic_1164.all;

entity DToJKFlipFLop is
port(J,K,Clk : in std_logic;
     Q,QBar : out std_logic);
end DToJKFlipFLop;

architecture func of DToJKFlipFLop is

component DFlipFLop is
port(D,Clk : in std_logic;
     Q,QBar : out std_logic);
end component;

component ANDgate is
port(A,B : in std_logic;
     F : out std_logic);
end component;

component ORGATE is
port(A,B : in std_logic;
     Z : out std_logic);
end component;

component notGate is
port(inPort : in std_logic;
     outPort : out std_logic);
end component;

signal knot, and1, and2, or1 : std_logic;
signal Q_buf : std_logic:='0';
signal QBar_buf : std_logic:='1';
begin
Q<=Q_buf;
QBar<=QBar_Buf;
G1: notGate port map(K,knot);
G2: ANDgate port map(QBar_buf,J,and1);
G3: ANDgate port map(Q_buf,knot,and2);
G4: ORGATE port map(and1,and2,or1);
G5: DFlipFlop port map(or1,Clk,Q,Qbar);
end func;