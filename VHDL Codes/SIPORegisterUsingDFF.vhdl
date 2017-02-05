library ieee;
use ieee.std_logic_1164.all;

entity SIPORegisterUsingDFF is
port(din, Clk, Rst : in std_logic;
     dout : out std_logic_vector(3 downto 0));
end SIPORegisterUsingDFF;

architecture func of SIPORegisterUsingDFF is

component DFlipFlop is
port(D, Clk, Rst : in std_logic;
     Q, QBar : out std_logic);
end component;

signal QNot : std_logic_vector(3 downto 0);
signal temp : std_logic_vector(3 downto 0);

begin
G1 : DFlipFLop port map(din,Clk,Rst,temp(0),QNot(0));
G2 : DFlipFLop port map(temp(0),Clk,Rst,temp(1),QNot(1));
G3 : DFlipFLop port map(temp(1),Clk,Rst,temp(2),QNot(2));
G4 : DFlipFLop port map(temp(2),Clk,Rst,temp(3),QNot(3));
dout<=temp;

end func;