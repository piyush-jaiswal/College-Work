library ieee;
use ieee.std_logic_1164.all;

entity Mux4x1Using2x1 is
port(din : in std_logic_vector(3 downto 0);
     sel : in std_logic_vector(1 downto 0);
     dout : out std_logic);
end Mux4x1Using2x1;

architecture func of Mux4x1Using2x1 is

component Mux2x1 is -- import 2x1 entity
port(din : in std_logic_vector(1 downto 0);
     sel : in std_logic;
     dout : out std_logic);
end component;

signal o : std_logic_vector(1 downto 0);

begin
--mux: process(din,sel) is
--begin
G1 : Mux2x1 port map(din(3 downto 2),sel(0),o(1));
G2 : Mux2x1 port map(din(1 downto 0), sel(0), o(0));
G3 : Mux2x1 port map(o, sel(1), dout);
--end process mux;

end func;