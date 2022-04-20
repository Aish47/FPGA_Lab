//declaring the module
module helloworldfpga(

input  wire A, //MSB bit input
input  wire B,
input  wire C, //LSB bit input

output wire a,
output wire b,
output wire c,
output wire d,
output wire e,
output wire f,
output wire g,
output wire redled, // LHS output
);

reg W,X,Y,Z,out;

//Display Decoder
always @(*)
begin

out = (A&&B&&C);

if(out == 1)
	begin
		Z=0;
		Y=0;
		X=0;
		W=1;
	end
else
	begin
		Z=0;
		Y=0;
		X=0;
		W=0;
	end

a=(!Z&!Y&!X&W)|(!Z&Y&!X&!W);
b=(!Z&Y&!X&W)|(!Z&Y&X&!W);
c=(!Z&!Y&X&!W);
d=(!Z&!Y&!X&W)|(!Z&Y&!X&!W)|(!Z&Y&X&W);
e=(!Z&!Y&!X&W)|(!Z&!Y&X&W)|(!Z&Y&!X&!W)|(!Z&Y&!X&W)|(!Z&Y&X&W)|(Z&!Y&!X&W);
f=(!Z&!Y&!X&W)|(!Z&!Y&X&!W)|(!Z&!Y&X&W)|(!Z&Y&X&W);
g=(!Z&!Y&!X&!W)|(!Z&!Y&!X&W)|(!Z&Y&X&W);
redled = A&((!A)|B)&C&(A|B);
end
endmodule
//end of the module
