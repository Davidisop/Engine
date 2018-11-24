#include "PipeLineSetup.h"
#include "Canon_Camera.h"

class Object_BaseCamp
{
public:
	PipeLineSetup  PipeLineSetup;
	D3DVECTOR      m_vCenter;

public:

	SimpleVertex	m_VertexList[6];
	UINT		    m_icount_Vertexs;

public:

	T_CB_DATA		m_Constant_Data;

public:

	D3DXMATRIX		m_matWorld;

public:


	Canon_Camera	Basic_Camera;

	void camera_apply_to_constant_buffer();
	void camera_Coordinates_System_update();


public:
	virtual bool	Init() { return true;}
	virtual bool	Frame(float fGameTimer, float fFps)	{return true;}
	virtual bool	PreRender(ID3D11DeviceContext* pContext)	{ PipeLineSetup.PreRender(pContext);	return true;}
	virtual bool	Render(ID3D11DeviceContext* pContext) { PipeLineSetup.Render(pContext, m_icount_Vertexs); return true;}
	virtual bool	PostRender(ID3D11DeviceContext* pContext) { PipeLineSetup.PostRender(pContext, m_icount_Vertexs); return true;}
	virtual bool	Release() { return true;}
public:
	Object_BaseCamp() {}
	virtual ~Object_BaseCamp() {}
};



void Object_BaseCamp::camera_apply_to_constant_buffer()
{
	D3DXMatrixIdentity(&m_matWorld);
	D3DXMatrixTranspose(&m_Constant_Data.matWorld, &m_matWorld);
	D3DXMatrixTranspose(&m_Constant_Data.matView, &Basic_Camera.m_matView);
	D3DXMatrixTranspose(&m_Constant_Data.matProj, &Basic_Camera.m_matProj);
}

void Object_BaseCamp::camera_Coordinates_System_update()
{
	Basic_Camera.camera__Right.x = Basic_Camera.m_matView._11;	Basic_Camera.camera_up.x = Basic_Camera.m_matView._12;	  Basic_Camera.camera_up.x = Basic_Camera.m_matView._13;
	Basic_Camera.camera__Right.y = Basic_Camera.m_matView._21;	Basic_Camera.camera_up.y = Basic_Camera.m_matView._22;	  Basic_Camera.camera_up.y = Basic_Camera.m_matView._23;
	Basic_Camera.camera__Right.z = Basic_Camera.m_matView._31;	Basic_Camera.camera_up.z = Basic_Camera.m_matView._32;	  Basic_Camera.camera_up.z = Basic_Camera.m_matView._33;
}