#pragma once
#include "Object_Handling.h"

class Box : public Object_Handling
{
public:
	bool   Set_VertexData();
	bool   update_ConstantBuffer();

public:

	bool	CreateIndexData();

public:
	bool Create(ID3D11Device* pd3dDevice, const TCHAR* pVsFile, const TCHAR* pPsFile, const TCHAR* pTexFile);


public:
	Box() {}
	virtual ~Box() {}
};

bool   Box::update_ConstantBuffer()
{
	g_pContext->UpdateSubresource(PipeLineSetup.m_pConstantBuffer, 0, NULL, &m_Constant_Data, 0, 0);

	return true;
}



bool  Box::Set_VertexData()
{
	m_VertexList.resize(24);
	int iner_index = 0;

	//�ո�

	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(-0.5f, 0.5f, -0.5f), D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(0.5f, 0.5f, -0.5f), D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(0.5f, -0.5f, -0.5f), D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));

	
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(-0.5f, -0.5f, -0.5f), D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));
	

	// �޸�
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(0.5f, 0.5f, 0.5f), D3DXVECTOR4(0.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(-0.5f, 0.5f, 0.5f), D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(-0.5f, -0.5f, 0.5f), D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	

	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(0.5f, -0.5f, 0.5f), D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));
	

	// ������
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(0.5f, 0.5f, -0.5f), D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(0.5f, 0.5f, 0.5f), D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(0.5f, -0.5f, 0.5f), D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));



	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(0.5f, -0.5f, -0.5f), D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));
	

	// ����
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(-0.5f, 0.5f, 0.5f), D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(-0.5f, 0.5f, -0.5f), D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(-0.5f, -0.5f, -0.5f), D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));

	
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(-0.5f, -0.5f, 0.5f), D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));


	// ����
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(-0.5f, 0.5f, 0.5f), D3DXVECTOR4(1.0f, 0.5f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(0.5f, 0.5f, 0.5f), D3DXVECTOR4(1.0f, 0.5f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(0.5f, 0.5f, -0.5f), D3DXVECTOR4(1.0f, 0.5f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	
	
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(-0.5f, 0.5f, -0.5f), D3DXVECTOR4(1.0f, 0.5f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));
	

	// �Ʒ���
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(-0.5f, -0.5f, -0.5f), D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(0.5f, -0.5f, -0.5f), D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VertexList[iner_index++] = SimpleVertex(D3DXVECTOR3(0.5f, -0.5f, 0.5f), D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	

	m_VertexList[iner_index] = SimpleVertex(D3DXVECTOR3(-0.5f, -0.5f, 0.5f), D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));
	

	m_icount_Vertexs = iner_index + 1;

	return true;
}



bool Box::CreateIndexData()
{
	
	m_IndexList.resize(36);
	int iIndex = 0;
	m_IndexList[iIndex++] = 0; 	m_IndexList[iIndex++] = 1; 	m_IndexList[iIndex++] = 2;
	m_IndexList[iIndex++] = 3;	m_IndexList[iIndex++] = 0; 	m_IndexList[iIndex++] = 2;

	m_IndexList[iIndex++] = 4; 	m_IndexList[iIndex++] = 5; 	m_IndexList[iIndex++] = 6;
	m_IndexList[iIndex++] = 7;	m_IndexList[iIndex++] = 4; 	m_IndexList[iIndex++] = 6;

	m_IndexList[iIndex++] = 8; 	m_IndexList[iIndex++] = 9; 	m_IndexList[iIndex++] = 10;
	m_IndexList[iIndex++] = 11;	m_IndexList[iIndex++] = 8; m_IndexList[iIndex++] = 10;

	m_IndexList[iIndex++] = 12; m_IndexList[iIndex++] = 13; m_IndexList[iIndex++] = 14;
	m_IndexList[iIndex++] = 15;	m_IndexList[iIndex++] = 12; m_IndexList[iIndex++] = 14;

	m_IndexList[iIndex++] = 16; m_IndexList[iIndex++] = 17; m_IndexList[iIndex++] = 18;
	m_IndexList[iIndex++] = 19;	m_IndexList[iIndex++] = 16; m_IndexList[iIndex++] = 18;

	m_IndexList[iIndex++] = 20; m_IndexList[iIndex++] = 21; m_IndexList[iIndex++] = 22;
	m_IndexList[iIndex++] = 23;	m_IndexList[iIndex++] = 20; m_IndexList[iIndex] = 22;

	m_icount_Indexs = iIndex + 1;

	return true;

}



bool    Box::Create(ID3D11Device* pd3dDevice, const TCHAR* pVsFile, const TCHAR* pPsFile, const TCHAR* pTexFile)
{
	PipeLineSetup.LoadTexture(pd3dDevice, pTexFile);
	PipeLineSetup.SetBlendState(pd3dDevice);
	PipeLineSetup.CreateVertextBuffer(pd3dDevice, &m_VertexList.at(0), m_icount_Vertexs);
	PipeLineSetup.CreateIndexBuffer(pd3dDevice, &m_IndexList.at(0), m_icount_Indexs);
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