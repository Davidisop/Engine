//--------------------------------------------------------------------------------------
// Constant Buffer Variables
//--------------------------------------------------------------------------------------
cbuffer cb0
{
	matrix	g_matWorld		: packoffset(c0);
	matrix	g_matView		: packoffset(c4);
	matrix	g_matProj		: packoffset(c8);
};

struct VS_INPUT
{
	float4 p : POSITION;
	float4 c : COLOR;
	float2 t : TEXCOORD;
};


struct VS_OUTPUT
{
	float4 p : SV_POSITION;
	float4 c : COLOR0;
	float2 t : TEXCOORD0;
};


VS_OUTPUT VS(VS_INPUT Input)
{
	VS_OUTPUT output = (VS_OUTPUT)0;
	output.p = Input.p;
	output.c = Input.c;
	output.t = Input.t;
	return output;
}

