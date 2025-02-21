-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
-- Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity fir_fir_int_int_c_rom is 
    generic(
             DWIDTH     : integer := 32; 
             AWIDTH     : integer := 5; 
             MEM_SIZE    : integer := 19
    ); 
    port (
          addr0      : in std_logic_vector(AWIDTH-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DWIDTH-1 downto 0);
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of fir_fir_int_int_c_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "00000000000000000000000000110101", 
    1 => "00000000000000000000000000000000", 
    2 => "11111111111111111111111110100101", 
    3 => "00000000000000000000000011010101", 
    4 => "00000000000000000000000001110000", 
    5 => "00000000000000000000000000000000", 
    6 => "00000000000000000000000100111001", 
    7 => "00000000000000000000000111110100", 
    8 => "00000000000000000000000011010101", 
    9 => "00000000000000000000000100111001", 
    10 => "00000000000000000000000000000000", 
    11 => "11111111111111111111111110100101", 
    12 => "00000000000000000000000111110100", 
    13 => "00000000000000000000000000000000", 
    14 => "11111111111111111111111110100101", 
    15 => "00000000000000000000000100111001", 
    16 => "00000000000000000000000000000000", 
    17 => "11111111111111111111111110100101", 
    18 => "00000000000000000000000000110101" );


begin 


memory_access_guard_0: process (addr0) 
begin
      addr0_tmp <= addr0;
--synthesis translate_off
      if (CONV_INTEGER(addr0) > mem_size-1) then
           addr0_tmp <= (others => '0');
      else 
           addr0_tmp <= addr0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(addr0_tmp)); 
        end if;
    end if;
end process;

end rtl;

Library IEEE;
use IEEE.std_logic_1164.all;

entity fir_fir_int_int_c is
    generic (
        DataWidth : INTEGER := 32;
        AddressRange : INTEGER := 19;
        AddressWidth : INTEGER := 5);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of fir_fir_int_int_c is
    component fir_fir_int_int_c_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    fir_fir_int_int_c_rom_U :  component fir_fir_int_int_c_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


