#pragma once
#include "Object_Handling.h"


class Plane : public Object_Handling
{
public:
	bool   Set_VertexData();
	bool   update_ConstantBuffer();

public:
	bool Create(ID3D11Device* pd3dDevice, const TCHAR* pVsFile, const TCHAR* pPsFile, const TCHAR* pTexFile);


public:
	Plane() {}
	virtual ~Plane() {}
};

bool   Plane::update_ConstantBuffer()
{
	g_pContext->UpdateSubresource(PipeLineSetup.m_pConstantBuffer, 0, NULL, &m_Constant_Data, 0, 0);

	return true;
}



bool  Plane:: Set_VertexData()
{
	

	m_VertexList[0].x = -0.5f; m_VertexList[0].y = 0.5f;  m_VertexList[0].z = 0.0f;   m_VertexList[0].r = 0.0f;	m_VertexList[0].g = 0.0f;	m_VertexList[0].b = 0.0f;	m_VertexList[0].a = 0.0f;  m_VertexList[0].u = 0.0f;	m_VertexList[0].v = 0.0f;
	m_VertexList[1].x = 0.5f; m_VertexList[1].y = 0.5f;  m_VertexList[1].z = 0.0f;   m_VertexList[1].r = 1.0f;	m_VertexList[1].g = 0.0f;	m_VertexList[1].b = 1.0f;	m_VertexList[1].a = 0.0f;  m_VertexList[1].u = 1.0f;	m_VertexList[1].v = 0.0f;
	m_VertexList[2].x = -0.5f; m_VertexList[2].y = -0.5f; m_VertexList[2].z = 0.0f;   m_VertexList[2].r = 0.0f;	m_VertexList[2].g = 1.0f;	m_VertexList[2].b = 0.0f;	m_VertexList[2].a = 1.0f;  m_VertexList[2].u = 0.0f;	m_VertexList[2].v = 1.0f;
	m_VertexList[3].x = -0.5f; m_VertexList[3].y = -0.5f; m_VertexList[3].z = 0.0f;   m_VertexList[3].r = 0.0f;	m_VertexList[3].g = 1.0f;	m_VertexList[3].b = 0.0f;	m_VertexList[3].a = 1.0f;  m_VertexList[3].u = 0.0f;	m_VertexList[3].v = 1.0f;
	m_VertexList[4].x = 0.5f; m_VertexList[4].y = 0.5f; m_VertexList[4].z = 0.0f;     m_VertexList[4].r = 1.0f;   m_VertexList[4].g = 0.0f;	m_VertexList[4].b = 1.0f;   m_VertexList[4].a = 0.0f;  m_VertexList[4].u = 1.0f;   m_VertexList[4].v = 0.0f;
	m_VertexList[5].x = 0.5f; m_VertexList[5].y = -0.5f; m_VertexList[5].z = 0.0f;    m_VertexList[5].r = 1.0f;	m_VertexList[5].g = 1.0f;	m_VertexList[5].b = 1.0f;	m_VertexList[5].a = 1.0f;  m_VertexList[5].u = 1.0f;	m_VertexList[5].v = 1.0f;

	m_icount_Vertexs = 6;

	return true;
}


bool    Plane::Create(ID3D11Device* pd3dDevice, const TCHAR* pVsFile, const TCHAR* pPsFile, const TCHAR* pTexFile)
{
	PipeLineSetup.LoadTexture(pd3dDevice, pTexFile);
	PipeLineSetup.SetBlendState(pd3dDevice);
	PipeLineSetup.CreateVertextBuffer(pd3dDevice, m_VertexList, 6);
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