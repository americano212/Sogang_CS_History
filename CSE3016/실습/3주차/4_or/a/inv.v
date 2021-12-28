`timescale 1ns / 1ps


module inv(
    input a,
    input b,
    input c,
    input d,
    output e_and
    );
    or(e_and,a,b,c,d);
    
endmodule