`timescale 1ns / 1ps


module inv(
    input a,
    input b,
    input c,
    output d_and
    );
    and(d_and,a,b,c);
endmodule