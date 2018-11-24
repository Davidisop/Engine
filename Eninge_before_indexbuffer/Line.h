#pragma once
#include "Object_Handling.h"


class Line_Axis_s : public Object_Handling
{
public:
	bool   Set_VertexData();
	bool   update_ConstantBuffer();

public:
	bool Create(ID3D11Device* pd3dDevice, const TCHAR* pVsFile, const TCHAR* pPsFile, const TCHAR* pTexFile);

public:

	D3D_PRIMITIVE_TOPOLOGY m_Primitive;
	 bool	PreRender(ID3D11DeviceContext* pContext) { PipeLineSetup.PreRender(pContext, m_Primitive);	return true; }

public:
	Line_Axis_s() { m_Primitive = D3D_PRIMITIVE_TOPOLOGY_LINELIST; }
	virtual ~Line_Axis_s() {}
};

bool   Line_Axis_s::update_ConstantBuffer()
{
	g_pContext->UpdateSubresource(PipeLineSetup.m_pConstantBuffer, 0, NULL, &m_Constant_Data, 0, 0);

	return true;
}



bool  Line_Axis_s::Set_VertexData()
{


	m_VertexList.resize(9);

	int iner_index = 0;
	m_VertexList[iner_index++].p = D3DXVECTOR3(0.0f, 0.0f, 0.0f);   m_VertexList[0].c = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.5f); m_VertexList[0].t = D3DXVECTOR2(0.0f, 0.0f);
	m_VertexList[iner_index++].p = D3DXVECTOR3(1000.0f, 0.0f, 0.0f);   m_VertexList[1].c = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 0.5f); m_VertexList[1].t = D3DXVECTOR2(1.0f, 0.0f);
	m_VertexList[iner_index++].p = D3DXVECTOR3(0.0f, 0.0f, 0.0f);   m_VertexList[0].c = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.5f); m_VertexList[0].t = D3DXVECTOR2(0.0f, 0.0f);

	m_VertexList[iner_index++].p = D3DXVECTOR3(0.0f, 0.0f, 0.0f);   m_VertexList[0].c = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.5f); m_VertexList[0].t = D3DXVECTOR2(0.0f, 0.0f);
	m_VertexList[iner_index++].p = D3DXVECTOR3(0.0f, 1000.0f, 0.0f);   m_VertexList[1].c = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 0.5f); m_VertexList[1].t = D3DXVECTOR2(1.0f, 0.0f);
	m_VertexList[iner_index++].p = D3DXVECTOR3(0.0f, 0.0f, 0.0f);   m_VertexList[0].c = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.5f); m_VertexList[0].t = D3DXVECTOR2(0.0f, 0.0f);

	m_VertexList[iner_index++].p = D3DXVECTOR3(0.0f, 0.0f, 0.0f);   m_VertexList[0].c = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.5f); m_VertexList[0].t = D3DXVECTOR2(0.0f, 0.0f);
	m_VertexList[iner_index++].p = D3DXVECTOR3(0.0f, 0.0f, 1000.0f);   m_VertexList[1].c = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 0.5f); m_VertexList[1].t = D3DXVECTOR2(1.0f, 0.0f);
	m_VertexList[iner_index++].p = D3DXVECTOR3(0.0f, 0.0f, 0.0f);   m_VertexList[0].c = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.5f); m_VertexList[0].t = D3DXVECTOR2(0.0f, 0.0f);
	m_icount_Vertexs = m_VertexList.size();

	return true;
}


bool    Line_Axis_s::Create(ID3D11Device* pd3dDevice, const TCHAR* pVsFile, const TCHAR* pPsFile, const TCHAR* pTexFile)
{
	PipeLineSetup.LoadTexture(pd3dDevice, pTexFile);
	PipeLineSetup.SetBlendState(pd3dDevice);
	PipeLineSetup.CreateVertextBuffer(pd3dDevice, &m_VertexList.at(0), m_icount_Vertexs);
	PipeLineSetup.CreateConstantBuffer(pd3dDevice, &m_Constant_Data);
	PipeLineSetup.CreateVertexShader(pd3dDevice, pVsFile);
	PipeLineSetup.CreateLayout(pd3dDevice);
	PipeLineSetup.CreatePixelShader(pd3dDevice, pPsFile);


	PipeLineSetup.For_Viewport_get_set();
	PipeLineSetup.Create_RasterizerState();
	PipeLineSetup.CreateTexture2D_DepthStencilView();
	PipeLineSetup.CreateDepthStencilState();

	return true;
}