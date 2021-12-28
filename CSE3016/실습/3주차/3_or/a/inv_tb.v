`timescale 1ns / 1ps

module inv_tb;

reg a,b,c;

wire d_and;

inv u_inv (
.a (a ),
.b (b ),
.c (c ),
.d_and (d_and )
 );

initial a = 1'b0;
initial b = 1'b0;
initial c = 1'b0;
always a = #100 ~a;
always b = #50 ~b;
always c = #25 ~c;

initial begin
    #1000
    $finish;
end

endmodule