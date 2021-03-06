//-------------------------------
//BlurV_ps20.hlsl
// Vertical Gaussian-Blur pass
//-------------------------------

Texture2D Blur0;          // Color texture for mesh

SamplerState g_samLinear
{
    Filter = MIN_MAG_MIP_LINEAR;
    AddressU = Wrap;
    AddressV = Wrap;
};

// Simple blur filter

//We use the Normal-gauss distribution formula
//f(x) being the formula, we used f(0.5)-f(-0.5); f(1.5)-f(0.5)...
static const float samples[11] =
{//stddev=2.0
0.01222447,
0.02783468,
0.06559061,
0.12097757,
0.17466632,

0.19741265,

0.17466632,
0.12097757,
0.06559061,
0.02783468,
0.01222447
};

static const float2 pos[11] =
{
0, -5,
0, -4,
0, -3,
0, -2,
0, -1,
0, 0,
0, 1,
0, 2,
0, 3,
0, 4,
0, 5
};


struct VS_OUTPUT {
    float4 Pos : SV_Position;
    float2 texCoord : TEXCOORD0;
};


float4 main(VS_OUTPUT input) : SV_Target
{
   float4 sum = 0;
   for (int i = 0; i < 11; i++)
   {
      sum += Blur0.Sample(g_samLinear, input.texCoord + pos[i]*0.01) * samples[i];
   }
   return sum;
}
